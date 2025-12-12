/*

*/

#ifndef APPLICATION_TYPE_HEADER
#define APPLICATION_TYPE_HEADER

#include "Main.hpp"

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

namespace tppo{
    class Application {
        
    protected:
        //
        ComponentManager componentManager;
        
        //
        EntityManager entityManager;
        
        //
        SystemManager systemManager;
        
    public:
        //
        Application();
        
        //
        ~Application();
        
        //
        void Init();
        
        //
        void Run();
        
    };
}

#endif //APPLICATION_TYPE_HEADER
