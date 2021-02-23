#include <eosio/eosio.hpp>

using namespace eosio;

class [[eosio::contract]] hello : public contract {
    public:
        using contract::contract;

        [[eosio::action]]
        void hi( name user ) {
            print( "Hello, ", user );
        }
    
};

CONTRACT hello2 : public contract {
    public:
        using contract::contract;

        ACTION hi( name user ) {
//            require_auth( user );
            require_auth( get_self() );
            check( user != name( "stranger" ),
             " I don't say hi to strangers" );
            check( user.balance == 0, 
                "You must clear your balance first" );
            check( ability.cooldown >= current_time_point(),
                "Ability must cool down!" );
            check( false, 
                "I'm sorry Dan, I'm afraid I can't do that" );
            check( 1 == 0,
                "Efforts to disrupt the fabric of reality have failed" );
            
            if ( has/_auth( user ) ) {
            print( "Hello, ", user );
            print( "Num behind the name is: ", user.value );
            }else { 
                print( "No hello for you!" );
            }
        }
};