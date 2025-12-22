/*

*/

#ifndef GAME_MODE_COMPONENT_TYPE_HEADER
#define GAME_MODE_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include <string>
#include <unordered_map>

#include "Component.hpp"

namespace tppo {
    class GameModeComponent : public Component {
        
    protected:
        //
        bool isActive;
        
        //
        std::function<void()> resultState;
    
        //
        std::pair<long double, long double> respawnSpace;
    
        //
        std::pair<sf::Time, sf::Time> respawnPeriodRange;
        
        //
        std::uint64_t defaultLetterDamage;
        
        //
        sf::Clock timePassed;
        
        
        
    public:
        //
        GameModeComponent(
            std::uint64_t ownerId,
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &respawnSpace,
            std::pair<sf::Time, sf::Time> &respawnPeriodRange,
            std::uint64_t defaultLetterDamage = 1
        );
        
        //
        GameModeComponent(
            std::uint64_t ownerId,
            bool isActive,
            std::function<void()> resultState,
            std::pair<long double, long double> &&respawnSpace,
            std::pair<sf::Time, sf::Time> &&respawnPeriodRange,
            std::uint64_t defaultLetterDamage = 1
        );
        
        //
        bool IsActive();
        
        //
        void Activate();
        
        //
        void Deactivate();
        
        //
        const std::pair<long double, long double> &GetRespawnSpace();
        
        //
        const std::pair<sf::Time, sf::Time> &GetRespawnPeriodRange();
        
        //
        void SetRespawnPeriodRange(sf::Time &respawnPeriod);
        
        //
        void SetRespawnPeriodRange(sf::Time &&respawnPeriod);
        
        //
        void SetRespawnPeriodRange(sf::Time &lowerRespawnPeriodRange, sf::Time &upperRespawnPeriodRange);
        
        //
        void SetRespawnPeriodRange(sf::Time &&lowerRespawnPeriodRange, sf::Time &&upperRespawnPeriodRange);
        
        //
        void SetRespawnPeriodRange(std::pair<sf::Time, sf::Time> &respawnPeriodRange);
        
        //
        void SetRespawnPeriodRange(std::pair<sf::Time, sf::Time> &&respawnPeriodRange);
        
        //
        sf::Clock &GetTimePassed();
        
        //
        std::function<void()> &GetResultState();
        
        //
        void CallResultState();
        
    };
}

#endif //GAME_MODE_COMPONENT_TYPE_HEADER
