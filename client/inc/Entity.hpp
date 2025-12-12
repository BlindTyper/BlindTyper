/*

*/

#ifndef ENTITY_TYPE_HEADER
#define ENTITY_TYPE_HEADER

#include <cstdint>

namespace tppo {
    class Entity {
        
    protected:
        //
        static std::uint64_t counter;
        
        //
        std::uint64_t entityId;
        
    public:
        //
        static std::uint64_t UseCounter();
        
        //
        static std::uint64_t GetCounter();
    
        //
        Entity();
        
    };
}
#endif //ENTITY_TYPE_HEADER
