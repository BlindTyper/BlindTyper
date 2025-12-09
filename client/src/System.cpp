/*

*/

#include <System.hpp>

namespace tppo {
    //
    System::System(ComponentManager &componentManager, EntityManager &entityManager) 
        : componentManager(componentManager)
        , entityManager(entityManager) {
        
    }
}