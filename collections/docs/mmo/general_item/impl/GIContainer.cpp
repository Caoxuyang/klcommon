///
/// @file GIContainer.cpp
/// @author Kevin Lynx
/// 
#include "GIContainer.h"
#include "GIObject.h"
#include "GIObjectProto.h"
#include "GIContainerListener.h"

namespace GI
{

#define NOTIFY( op ) if( m_listener ) m_listener->op

    BaseContainer::BaseContainer()
    {
        m_listener = NULL;
    }

    BaseContainer::~BaseContainer()
    {
        DestroyAll();
    }

    void BaseContainer::SetListener( ContainerListener *lis )
    {
        m_listener = lis;
    }

    bool BaseContainer::Move( BaseContainer *destCon, TypeSet::IDType objID )
    {
        Object *obj = Get( objID );
        if( !obj ) return false;
        if( !destCon->Add( obj ) ) return false;
        Remove( objID );
    }

    bool BaseContainer::MoveAll( BaseContainer *destCon )
    {
        bool ret = true;
        for( ObjectMap::iterator it = m_objs.begin();
                it != m_objs.end(); )
        {
            bool lret = destCon->Add( it->second );
            if( lret )
            {
                // TODO: make more beautiful here.
                NOTIFY( OnRemove( it->second ) );
                it = m_objs.erase( it );
            }
            else ++ it;
            ret = lret && ret;
        }
        return ret;
    }

    bool BaseContainer::Destroy( TypeSet::IDType objID )
    {
        Object *obj = Get( objID );
        if( !obj ) return false;
        Remove( objID );
        NOTIFY( OnDestroy( obj ) );
        delete obj;
        return true;
    }

    void BaseContainer::DestroyAll()
    {
        for( ObjectMap::iterator it = m_objs.begin();
                it != m_objs.end(); )
        {
            // TODO: 
            NOTIFY( OnRemove( it->second ) );
            NOTIFY( OnDestroy( it->second ) );
            delete it->second;
        }
        m_objs.clear();
    }

    const Object *BaseContainer::Get( TypeSet::IDType objID ) const
    {
        ObjectMap::const_iterator it = m_objs.find( objID );
        return it == m_objs.end() ? NULL : it->second;
    }

    Object *BaseContainer::Get( TypeSet::IDType objID )
    {
        ObjectMap::iterator it = m_objs.find( objID );
        return it == m_objs.end() ? NULL : it->second;
    }

    bool BaseContainer::Add( Object *obj )
    {
        NOTIFY( OnAdd( obj ) );
        TypeSet::ValueType idVal = obj->GetValue( KeySet::IDKey );
        TypeSet::IDType id = TypeSet::ValueType::ToID( idVal );
        m_objs[id] = obj; 
        return true;
    }

    bool BaseContainer::Remove( Object *obj )
    {
        NOTIFY( OnRemove( obj ) );
        TypeSet::ValueType idVal = obj->GetValue( KeySet::IDKey );
        TypeSet::IDType id = TypeSet::ValueType::ToID( idVal );
        m_objs.erase( id );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////
    struct Creator
    {
        Creator( Object *obj ) : m_obj( obj ) { }

        void operator() ( ObjectProto::KeyType key, ObjectProto::ValueType val ) 
        {
            PropertyTypeSet &pts = PropertyTypeSet::getSingleton();
            int t = pts.GetType( key );
            if( IS_DYNAMIC( t ) )
            {
                val = pts.GenValue( key, NULL );
                m_obj->AddProperty( key, val );
            }
        }
        Object *m_obj;
    };
    FactoryContainer::FactoryContainer()
    {
    }

    FactoryContainer::~FactoryContainer()
    {
    }

    bool FactoryContainer::Create( TypeSet::IndexType index, Object::PListenerType *listener )
    {
        Object *obj = DoCreate( index, listener );
        if( !obj ) return false;
        NOTIFY( OnCreate( obj ) );
        Add( obj );
        return true;
    }

    Object *FactoryContainer::DoCreate( TypeSet::IndexType index, Object::PListenerType *listener )
    {
        const ObjectProto *proto = ObjProtoFactory::getSingleton().GetProto( index );
        if( !proto ) return NULL;
        Object *obj = new Object( listener );
        obj->SetProto( proto );
        proto->Traverse( Creator( obj ) ); 
        return obj;
    }
    ///////////////////////////////////////////////////////////////////////////
    ModifyContainer::ModifyContainer()
    {
    }

    ModifyContainer::~ModifyContainer()
    {
    }

    bool ModifyContainer::Modify( TypeSet::IDType objID, TypeSet::KeyType key, TypeSet::KeyType value )
    {
        Object *obj = Get( objID );
        if( !obj ) return false;
        NOTIFY( OnModify( obj, key, value ) );
        obj->SetValue( key, value );
        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
    MergeContainer::MergeContainer()
    {
    }

    MergeContainer::~MergeContainer()
    {
    }

    bool MergeContainer::Merge( TypeSet::IDType objID1, TypeSet::IDType objID2 )
    {
        Object *obj1 = Get( objID1 );
        Object *obj2 = Get( objID2 );
        if( !obj1 || !obj2 ) return false;
        if( obj1->GetValue( KeySet::IndexKey ) !=
            obj2->GetValue( KeySet::IndexKey ) ) return false;

        TypeSet::ValueType maxStack = obj1->GetValue( KeySet::MaxStackCntKey );
        int maxSCnt = (int) TypeSet::ValueType::ToStackCnt( maxStack );

        int sCnt1 = GetStackCnt( obj1 );
        int sCnt2 = GetStackCnt( obj2 );

        if( sCnt1 + sCnt2 > maxSCnt ) return false;
        NOTIFY( OnModify( obj1, KeySet::StackCntKey, TypeSet::ValueType( sCnt1 + sCnt2 ) ) );
        obj1->SetValue( KeySet::StackCntKey, TypeSet::ValueType( sCnt1 + sCnt2 ) );
        // destroy object2
        NOTIFY( OnDestroy( obj2 ) );
        Destroy( obj2 );

        return true;
    }

    bool MergeContainer::Split( TypeSet::IDType objID, int splitCnt )
    {
        Object *obj = Get( objID );
        if( !obj ) return false;
        int curCnt = GetStackCnt( obj );
        if( splitCnt >= curCnt ) return false;

        int retCnt = curCnt - splitCnt;
        NOTIFY( OnModify( obj, KeySet::StackCntKey, TypeSet::ValueType( retCnt ) ) );
        obj->SetValue( KeySet::StackCntKey, TypeSet::ValueType( retCnt ) );
        // clone a new object.
        Object *newObj = new Object( NULL );
        obj->Clone( newObj );
        NOTIFY( OnCreate( newObj ) );
        newObj->SetValue( KeySet::StackCntKey, TypeSet::ValueType( splitCnt ) );
        Add( newObj );
        return true;
    }

    bool MergeContainer::DecStack( TypeSet::IDType objID, int decCnt )
    {
        Object *obj = Get( objID );
        if( !obj ) return false;
        int curCnt = GetStackCnt( obj );
        if( curCnt <= decCnt ) return false;
        
        int retCnt = curCnt - decCnt;
        NOTIFY( OnModify( obj, KeySet::StackCntKey, TypeSet::ValueType( retCnt ) ) );
        obj->SetValue( KeySet::StackCntKey, TypeSet::ValueType( retCnt ) );
        return true;
    }

    int MergeContainer::GetStackCnt( Object *obj )
    {
        TypeSet::ValueType sVal = obj->GetValue( KeySet::StackCntKey );
        int sCnt = (int) TypeSet::ValueType::ToStackCnt( sVal );
        return sCnt;
    }
}
