/*

*/

#ifndef ENTITY_TYPE_HEADER
#define ENTITY_TYPE_HEADER

#include <cstdint>

namespace tppo {
    class Entity {
        
    protected:
        //
        static uint64_t counter;
        
        //
        uint64_t entityId;
        
    public:
        //
        static uint64_t UseCounter();
        
        //
        static uint64_t GetCounter();
    
        //
        Entity();
        
    };
}
#endif //ENTITY_TYPE_HEADER
