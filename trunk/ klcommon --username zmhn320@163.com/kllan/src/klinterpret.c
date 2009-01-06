/**
 * @file klinterpret.c
 * @author Kevin Lynx
 * @brief to interpret syntax tree
 */
#include "klinterpret.h"
#include "klparser.h"
#include "kllex.h"
#include "klsymtab.h"
#include <stdio.h>

/**
 * function executed result type
 */
enum
{
	ER_NORMAL,
	ER_RETURN,
};

/**
 * function executed result
 */
struct FuncRet
{
	struct Value val;
	int type;
};

/**
 * build the global symbol table
 */
static void inter_build_global_st( struct interEnv *env, struct treeNode *root );
static struct Symbol *inter_lookup_symbol( struct interEnv *env, const char *name );
static struct Value inter_op_exp( struct interEnv *env, struct treeNode *node );
static struct Value inter_expression( struct interEnv *env, struct treeNode *node );
static void inter_exp_stmt( struct interEnv *env, struct treeNode *tree );
static struct Value inter_function( struct interEnv *env, struct treeNode *tree );
static struct FuncRet inter_statements( struct interEnv *env, struct treeNode *node );
static struct FuncRet inter_if_stmt( struct interEnv *env, struct treeNode *node );
static struct FuncRet inter_while_stmt( struct interEnv *env, struct treeNode *node );

static void inter_build_global_st( struct interEnv *env, struct treeNode *root )
{
	struct treeNode *node;
	for( node = root; node != 0; node = node->sibling )
	{
		if( node->type == NT_STMT )
		{
			if( node->subtype.stmt == ST_VAR_DEF )
			{
				struct Value val;
			    val	= inter_expression( env, node->child[0] );
				sym_insert( env->global_st, node->attr.val.sval, val );				
			}
			else if( node->subtype.stmt == ST_FUNC_DEF )
			{
				struct Value val;
				val.address = node;
				val.type = SB_FUNC;
				sym_insert( env->global_st, node->attr.val.sval, val );
			}
			else
			{
				env->inter_log( "runtime error->error statement in global scope" );
			}
		}
		else
		{
			env->inter_log( "runtime error->global scope must be var/func def" );
		}
	}
}

static struct Symbol *inter_lookup_symbol( struct interEnv *env, const char *name )
{
	struct Symbol *sb;
	sb = sym_lookup( env->global_st, name );
	if( sb == 0 )
	{
		sb = sym_lookup( env->local_st, name );
	}
	return sb;
}

static struct Value inter_op_exp( struct interEnv *env, struct treeNode *node )
{
	struct Value ret, left, right;
	ret.address = 0;
	ret.type = SB_VAR_NUM;
	/* two operator operation */
	if( node->child[0] == 0 || node->child[1] == 0 )
	{
		env->inter_log( "runtime error->expect an expression" );
	}

	if( node->attr.op != '=' )
	{
		left = inter_expression( env, node->child[0] );
	}
	right = inter_expression( env, node->child[1] );
	switch( node->attr.op )
	{
		/* these operations below do not handle the type of the two opertions */
		case TK_OR:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval || right.dval );
			}
			break;

		case TK_AND:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval && right.dval );
			}
			break;

		case TK_LE:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval <= right.dval ? 1 : 0 );	
			}
			break;

		case TK_GE:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval >= right.dval ? 1 : 0 );
			}
			break;

		case TK_EQ:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval == right.dval ? 1 : 0 );
			}
			break;

		case TK_NE:
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval != right.dval ? 1 : 0 );
			}
			break;

		case '<':
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval < right.dval ? 1 : 0 );
			}
			break;

		case '>':
			{
				ret.type = SB_VAR_NUM;
				ret.dval = ( left.dval > right.dval ? 1 : 0 );
			}
			break;

		case '+':
			{
				if( left.type == SB_VAR_NUM && right.type == SB_VAR_NUM )
				{
					ret.type = SB_VAR_NUM;
					ret.dval = left.dval + right.dval;
				}
				else if( left.type == SB_VAR_STRING || right.type == SB_VAR_STRING )
				{
					char *str = 0;
					ret.type = SB_VAR_STRING;
					if( left.type == SB_VAR_STRING )
					{
						char tmp[STRING_MAX_LEN];
						sprintf( tmp, "%s%lf", left.sval, right.dval );
						ret.sval = (char*)malloc( strlen( tmp ) + 1 );
						strcpy( ret.sval, tmp );
					}
					else if( right.type == SB_VAR_STRING )
					{
						char tmp[STRING_MAX_LEN];
						sprintf( tmp, "%lf%s", left.dval, right.sval );
						ret.sval = (char*)malloc( strlen( tmp ) + 1 );
						strcpy( ret.sval, tmp );
					}	
				}
			}
			break;

		case '-':
			{
				ret.type = SB_VAR_NUM;
				ret.dval = left.dval - right.dval;
			}
			break;

		case '*':
			{
				ret.type = SB_VAR_NUM;
				ret.dval = left.dval * right.dval;
			}
			break;

		case '/':
			{
				if( right.dval == 0 )
				{
					env->inter_log( "runtime error->divied by 0" );
				}
				else
				{
					ret.type = SB_VAR_NUM;
					ret.dval = left.dval / right.dval;
				}
			}
			break;

		case '%':
			{
				if( right.dval == 0 )
				{
					env->inter_log( "runtime error->divied by 0" );
				}
				else
				{
					ret.type = SB_VAR_NUM;
					ret.dval = (int)left.dval % (int)right.dval;
				}
			}
			break;

		case '=':
			{
				struct treeNode *l_node = node->child[0];
				struct Symbol *sb = sym_lookup( env->global_st, l_node->attr.val.sval );
				if( sb == 0 )
				{
					sym_insert( env->local_st, l_node->attr.val.sval, right );
				}	
				else
				{
					sym_insert( env->global_st, l_node->attr.val.sval, right );
				}
				ret = right;
			}
			break;

		default:
			env->inter_log( "runtime error->unsupport operation" );
	}
	return ret;
}

static struct Value inter_expression( struct interEnv *env, struct treeNode *node )
{
	struct Value ret ;

	switch( node->subtype.exp )
	{
		case ET_OP:
			return inter_op_exp( env, node );

		case ET_CONST:
			ret.dval = node->attr.val.dval;
			ret.type = SB_VAR_NUM;
		    return ret;

		case ET_STRING:
			ret.sval = node->attr.val.sval;
			ret.type = SB_VAR_STRING;
			return ret;

		case ET_ID:
			/* lookup in the symbol table */
			{
				struct Symbol *sb = inter_lookup_symbol( env, node->attr.val.sval );
				if( sb == 0 )
				{
					/* not exist, create a new symbol */
					ret.dval = 0;
					ret.type = SB_VAR_NUM;
					sym_insert( env->local_st, node->attr.val.sval, ret ); 
					return ret;
				}
				return sb->val;
			}

		case ET_FUNC_CALL:
			{
			}
			break;	

		default:
			env->inter_log( "" );	
	}
	ret.address = 0;
	ret.type = SB_VAR_NUM;
	return ret;
}

static void inter_exp_stmt( struct interEnv *env, struct treeNode *tree )
{
	inter_expression( env, tree );
}

static struct FuncRet inter_if_stmt( struct interEnv *env, struct treeNode *tree )
{
	struct FuncRet ret = { { 0, SB_VAR_NUM }, ER_NORMAL };
	struct Value exp = inter_expression( env, tree->child[0] );
	if( (int)exp.dval )
	{
		ret = inter_statements( env, tree->child[1] );	
	}
	else if( tree->child[2] != 0 )
	{
		ret = inter_statements( env, tree->child[2] );
	}
	return ret;
}

static struct FuncRet inter_while_stmt( struct interEnv *env, struct treeNode *tree )
{
	struct FuncRet ret = { { 0, SB_VAR_NUM }, ER_NORMAL };
	struct Value exp = inter_expression( env, tree->child[0] );
	struct treeNode *node = 0;
	while( (int)exp.dval )
	{
		ret = inter_statements( env, tree->child[1] );
		if( ret.type == ER_RETURN )
		{
			break;
		}
		exp = inter_expression( env, tree->child[0] );
	}
	return ret;	
}

static struct FuncRet inter_return_stmt( struct interEnv *env, struct treeNode *node )
{
	struct FuncRet ret = { { 0, SB_VAR_NUM }, ER_RETURN };
	ret.val = inter_expression( env, node->child[0] );
	return ret;
}

static struct FuncRet inter_statements( struct interEnv *env, struct treeNode *node )
{
	struct FuncRet ret = { { 0, SB_VAR_NUM }, ER_NORMAL };
	for( ; node != 0; node = node->sibling )
	{
		if( node->type == NT_STMT )
		{
			switch( node->subtype.stmt )
			{
				case ST_IF:
					ret = inter_if_stmt( env, node );
					break;

				case ST_WHILE:
					ret = inter_while_stmt( env, node );
					break;

				case ST_RETURN:
					ret = inter_return_stmt( env, node );
					break;

				default:
					break;	
			}

			if( ret.type == ER_RETURN )
			{
				break;
			}
		}	
		else if( node->type == NT_EXP )
		{
			/* expression statement*/
			inter_exp_stmt( env, node );
		}
	}
	
	return ret;
}

static struct Value inter_function( struct interEnv *env, struct treeNode *tree )
{
	struct treeNode *node;
	struct FuncRet ret = { { 0, SB_VAR_NUM }, ER_NORMAL };
	env->local_st = sym_new();
	/* TODO: build the argument symbols */
	ret = inter_statements( env, tree->child[1] );
	sym_free( env->local_st );
	return ret.val;	
}

int inter_execute( struct treeNode *root, inter_log_func log_func )
{
	struct Symbol *main;
	struct interEnv *env = (struct interEnv*) malloc( sizeof( struct interEnv ) );
	env->inter_log = log_func;
	env->global_st = sym_new();
	inter_build_global_st( env, root );
	main = sym_lookup( env->global_st, "main" );
	if( main != 0 )
	{
		/* TODO: to remove the arguments of main */	
		inter_function( env, (struct treeNode*) main->val.address );
	}
	sym_free( env->global_st );
	free( env );
	return 0;
}


