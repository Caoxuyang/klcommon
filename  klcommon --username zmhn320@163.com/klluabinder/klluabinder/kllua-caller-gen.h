/// this file was generated by a tiny program.


/// 1 param(s).


template <typename R, typename P1 > class lua_caller<R ( P1 ) > { public: typedef R result_type; typedef P1 p1_type; typedef lua_caller<R( P1 )> self_type; enum { param_count = 1 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 2 param(s).


template <typename R, typename P1,typename P2 > class lua_caller<R ( P1,P2 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type; typedef lua_caller<R( P1,P2 )> self_type; enum { param_count = 2 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 3 param(s).


template <typename R, typename P1,typename P2,typename P3 > class lua_caller<R ( P1,P2,P3 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type; typedef lua_caller<R( P1,P2,P3 )> self_type; enum { param_count = 3 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 4 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4 > class lua_caller<R ( P1,P2,P3,P4 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type; typedef lua_caller<R( P1,P2,P3,P4 )> self_type; enum { param_count = 4 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 5 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5 > class lua_caller<R ( P1,P2,P3,P4,P5 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type; typedef lua_caller<R( P1,P2,P3,P4,P5 )> self_type; enum { param_count = 5 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 6 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6 > class lua_caller<R ( P1,P2,P3,P4,P5,P6 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6 )> self_type; enum { param_count = 6 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 7 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7 )> self_type; enum { param_count = 7 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 8 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8 )> self_type; enum { param_count = 8 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 9 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9 )> self_type; enum { param_count = 9 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 10 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10 )> self_type; enum { param_count = 10 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 11 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10,typename P11 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type;typedef P11 p11_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11 )> self_type; enum { param_count = 11 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10,p11_type p11 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 );::kl_common::lua::return_traits<p11_type>::set_result( _L, p11 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 12 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10,typename P11,typename P12 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type;typedef P11 p11_type;typedef P12 p12_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12 )> self_type; enum { param_count = 12 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10,p11_type p11,p12_type p12 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 );::kl_common::lua::return_traits<p11_type>::set_result( _L, p11 );::kl_common::lua::return_traits<p12_type>::set_result( _L, p12 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 13 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10,typename P11,typename P12,typename P13 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type;typedef P11 p11_type;typedef P12 p12_type;typedef P13 p13_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13 )> self_type; enum { param_count = 13 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10,p11_type p11,p12_type p12,p13_type p13 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 );::kl_common::lua::return_traits<p11_type>::set_result( _L, p11 );::kl_common::lua::return_traits<p12_type>::set_result( _L, p12 );::kl_common::lua::return_traits<p13_type>::set_result( _L, p13 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 14 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10,typename P11,typename P12,typename P13,typename P14 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type;typedef P11 p11_type;typedef P12 p12_type;typedef P13 p13_type;typedef P14 p14_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14 )> self_type; enum { param_count = 14 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10,p11_type p11,p12_type p12,p13_type p13,p14_type p14 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 );::kl_common::lua::return_traits<p11_type>::set_result( _L, p11 );::kl_common::lua::return_traits<p12_type>::set_result( _L, p12 );::kl_common::lua::return_traits<p13_type>::set_result( _L, p13 );::kl_common::lua::return_traits<p14_type>::set_result( _L, p14 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };

/// 15 param(s).


template <typename R, typename P1,typename P2,typename P3,typename P4,typename P5,typename P6,typename P7,typename P8,typename P9,typename P10,typename P11,typename P12,typename P13,typename P14,typename P15 > class lua_caller<R ( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15 ) > { public: typedef R result_type; typedef P1 p1_type;typedef P2 p2_type;typedef P3 p3_type;typedef P4 p4_type;typedef P5 p5_type;typedef P6 p6_type;typedef P7 p7_type;typedef P8 p8_type;typedef P9 p9_type;typedef P10 p10_type;typedef P11 p11_type;typedef P12 p12_type;typedef P13 p13_type;typedef P14 p14_type;typedef P15 p15_type; typedef lua_caller<R( P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15 )> self_type; enum { param_count = 15 }; public: lua_caller() : _L( 0 ) { } lua_caller( lua_State *L, const std::string &fn_name ) : _L( L ), _fn( fn_name ) { } lua_caller( const self_type &other ) : _L( other._L ), _fn( other._fn ) { } self_type &operator= ( const self_type &other ) { _L = other._L; _fn = other._fn; return *this; } void set( lua_State *L, const std::string &fn_name ) { _L = L; _fn = fn_name; } bool valid() const { return lua::func_exist( _L, _fn ); } result_type operator() ( p1_type p1,p2_type p2,p3_type p3,p4_type p4,p5_type p5,p6_type p6,p7_type p7,p8_type p8,p9_type p9,p10_type p10,p11_type p11,p12_type p12,p13_type p13,p14_type p14,p15_type p15 ) const { lua::get_func( _L, _fn ); ::kl_common::lua::return_traits<p1_type>::set_result( _L, p1 );::kl_common::lua::return_traits<p2_type>::set_result( _L, p2 );::kl_common::lua::return_traits<p3_type>::set_result( _L, p3 );::kl_common::lua::return_traits<p4_type>::set_result( _L, p4 );::kl_common::lua::return_traits<p5_type>::set_result( _L, p5 );::kl_common::lua::return_traits<p6_type>::set_result( _L, p6 );::kl_common::lua::return_traits<p7_type>::set_result( _L, p7 );::kl_common::lua::return_traits<p8_type>::set_result( _L, p8 );::kl_common::lua::return_traits<p9_type>::set_result( _L, p9 );::kl_common::lua::return_traits<p10_type>::set_result( _L, p10 );::kl_common::lua::return_traits<p11_type>::set_result( _L, p11 );::kl_common::lua::return_traits<p12_type>::set_result( _L, p12 );::kl_common::lua::return_traits<p13_type>::set_result( _L, p13 );::kl_common::lua::return_traits<p14_type>::set_result( _L, p14 );::kl_common::lua::return_traits<p15_type>::set_result( _L, p15 ); lua::call_func( _L, param_count, lua::return_number_traits<result_type>::count ); return lua::result<result_type>::get( _L ); } private: lua_State *_L; std::string _fn; };
