/*

*/

#ifndef APPLICATION_STATES_TYPE_HEADER
#define APPLICATION_STATES_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "ApplicationStateComponent.hpp"

namespace tppo {
    class ApplicationStates : public Entity {
        
    protected:
        //
        std::shared_ptr<ApplicationStateComponent> currentState;
        
        
    public:
        //
        ApplicationStates();
        
        //
        void SetCurrentState(std::shared_ptr<ApplicationStateComponent> &newState);
        
        //
        std::shared_ptr<ApplicationStateComponent> &GetCurrentState();
        
    };
}
#endif //APPLICATION_STATES_TYPE_HEADER
