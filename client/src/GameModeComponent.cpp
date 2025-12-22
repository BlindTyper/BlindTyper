/*

*/

#include "GameModeComponent.hpp"

namespace tppo {
    //
    GameModeComponent::GameModeComponent(
        std::uint64_t ownerId,
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &respawnSpace,
        std::pair<sf::Time, sf::Time> &respawnPeriodRange,
        std::uint64_t defaultLetterDamage
    ) 
        : Component(ownerId)
        , isActive(isActive)
        , resultState(resultState)
        , respawnSpace(respawnSpace)
        , respawnPeriodRange(respawnPeriodRange)
        , defaultLetterDamage(defaultLetterDamage)
    {
        
    }
    
    //
    GameModeComponent::GameModeComponent(
        std::uint64_t ownerId,
        bool isActive,
        std::function<void()> resultState,
        std::pair<long double, long double> &&respawnSpace,
        std::pair<sf::Time, sf::Time> &&respawnPeriodRange,
        std::uint64_t defaultLetterDamage
    ) 
        : Component(ownerId)
        , isActive(isActive)
        , resultState(resultState)
        , respawnSpace(respawnSpace)
        , respawnPeriodRange(respawnPeriodRange)
        , defaultLetterDamage(defaultLetterDamage)
    {
        
    }
        
    //
    bool GameModeComponent::IsActive() {
        return isActive;
    }
    
    //
    void GameModeComponent::Activate() {
        isActive = true;
    }
    
    //
    void GameModeComponent::Deactivate() {
        isActive = false;
    }
        
    //
    const std::pair<long double, long double> &GameModeComponent::GetRespawnSpace() {
        return respawnSpace;
    }
    
    //
    const std::pair<sf::Time, sf::Time> &GameModeComponent::GetRespawnPeriodRange() {
        return respawnPeriodRange;
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(sf::Time &respawnPeriod) {
        this->respawnPeriodRange = {respawnPeriod, respawnPeriod};
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(sf::Time &&respawnPeriod) {
        this->respawnPeriodRange = {respawnPeriod, respawnPeriod};
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(sf::Time &lowerRespawnPeriodRange, sf::Time &upperRespawnPeriodRange) {
        this->respawnPeriodRange = {lowerRespawnPeriodRange, upperRespawnPeriodRange};
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(sf::Time &&lowerRespawnPeriodRange, sf::Time &&upperRespawnPeriodRange) {
        this->respawnPeriodRange = {lowerRespawnPeriodRange, upperRespawnPeriodRange};
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(std::pair<sf::Time, sf::Time> &respawnPeriodRange) {
        this->respawnPeriodRange = respawnPeriodRange;
    }
        
    //
    void GameModeComponent::SetRespawnPeriodRange(std::pair<sf::Time, sf::Time> &&respawnPeriodRange) {
        this->respawnPeriodRange = respawnPeriodRange;
    }
    
    //
    sf::Clock &GameModeComponent::GetTimePassed() {
        return timePassed;
    }
        
    //
    std::function<void()> &GameModeComponent::GetResultState() {
        return resultState;
    }
    
    //
    void GameModeComponent::CallResultState() {
        resultState();
    }
}