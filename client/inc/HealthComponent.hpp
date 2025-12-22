/*

*/

#ifndef HEALTH_COMPONENT_TYPE_HEADER
#define HEALTH_COMPONENT_TYPE_HEADER

#include "Component.hpp"

namespace tppo{
    class HealthComponent : Component {
        
    protected:
        //
        std::uint64_t currentHealth;
        
        //
        std::uint64_t maxHealth;
        
    public:
        //
        HealthComponent(
            std::uint64_t ownerId,
            std::uint64_t currentHealth,
            std::uint64_t maxHealth
        );
        
        //
        std::uint64_t &GetCurrentHealth();
        
        //
        std::uint64_t &GetMaxHealth();
        
    };
}
#endif //HEALTH_COMPONENT_TYPE_HEADER
