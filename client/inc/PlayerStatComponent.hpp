/*

*/

#ifndef PLAYER_STAT_COMPONENT_TYPE_HEADER
#define PLAYER_STAT_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

namespace tppo {
    class PlayerStatComponent : public Component {
        
    protected:
        //
        std::uint64_t totalLettersDestroyed;
        
        //
        long double lettersDestroyedPerMinute;
        
        //
        std::uint64_t timePassed; //asSeconds
        
    public:
        //
        PlayerStatComponent(
            std::uint64_t ownerId
        );
        
        //
        std::uint64_t &GetTotalLettersDestroyed();
        
        //
        long double &GetLettersDestroyedPerMinute();
        
        //
        std::uint64_t &GetTimePassed();
        
    };
}

#endif //PLAYER_STAT_COMPONENT_TYPE_HEADER
