/*

*/

#ifndef DAMAGE_COMPONENT_TYPE_HEADER
#define DAMAGE_COMPONENT_TYPE_HEADER

#include "Component.hpp"

namespace tppo {
    class DamageComponent : public Component {
        
    protected:
        //
        std::uint64_t damage;
        
    public:
        //
        DamageComponent(
            std::uint64_t ownerId,
            std::uint64_t damage
        );
        
        std::uint64_t GetDamage();
        
    };
}

#endif //DAMAGE_COMPONENT_TYPE_HEADER
