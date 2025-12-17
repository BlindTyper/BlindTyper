/*

*/

#include "ApplicationStates.hpp"

namespace tppo {
    //
    ApplicationStates::ApplicationStates() 
        : currentState(nullptr) {
        
    }
        
    //
    void ApplicationStates::SetCurrentState(std::shared_ptr<ApplicationStateComponent> &newState) {
        currentState = newState;
    }
        
    //
    std::shared_ptr<ApplicationStateComponent> &ApplicationStates::GetCurrentState() {
        return currentState;
    }
}