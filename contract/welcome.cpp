#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT welcome : public contract {
    public:
        using contract::contract;

        ACTION hi( name user ) {
//            require_auth( user );
//            require_auth( get_self() );
            check( user != name( "strangers" ),
             " I don't say hi to strangers" );
            
            if ( has_auth( user ) ) {
            print( "Hello, ", user );
            print( "Num behind the name is: ", user.value );
            }else { 
                print( "No hello for you!" );
            }
        }
};