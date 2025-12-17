/*

*/

#ifndef INTERACT_COMPONENT_TYPE_HEADER
#define INTERACT_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

namespace tppo {
    class InteractComponent : public Component {

    protected:
        //
        bool isSelected;
        
        //
        std::function<void()> onClick;
        
    public:
        //
        InteractComponent(uint64_t ownerId, std::function<void()> onClick);
        
    };
}

#endif //INTERACT_COMPONENT_TYPE_HEADER   
