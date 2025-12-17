/*

*/

#ifndef COMPONENT_TYPE_HEADER
#define COMPONENT_TYPE_HEADER

#include <cstdint>

namespace tppo {
    class Component {
        
    protected:
        //
        static uint64_t counter;
        
        //
        std::uint64_t componentId;
        
        //
        std::uint64_t ownerId;
        
    public:
        //
        static uint64_t UseCounter();
        
        //
        static uint64_t GetCounter();
        
        //
        Component(uint64_t ownerId);
        
        //
        std::uint64_t GetId();
        
    };
}

#endif //COMPONENT_TYPE_HEADER
