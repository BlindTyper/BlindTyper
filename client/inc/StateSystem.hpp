/*

*/

#ifndef STATE_SYSTEM_TYPE_HEADER
#define STATE_SYSTEM_TYPE_HEADER

#include "System.hpp"

#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace tppo {
    class StateSystem : public System {

    protected:
        
        
    public:
        //
        StateSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~StateSystem();
    
        //
        void Init();
    
        //
        void Update();
    
        //
        void MainMenuInit();
    
        //
        void CampanyGameMenuInit();
    
        //
        void InChapter1GameInit();
    
        //
        void Chapter1GameResultsInit();
    
        //
        void InChapter2GameInit();
    
        //
        void Chapter2GameResultsInit();
    
        //
        void InChapter3GameInit();
    
        //
        void Chapter3GameResultsInit();
    
        //
        void InEndlessGameInit();
    
        //
        void EndlessGameResultsInit();
    
        //
        void MainMenuState();
    
        //
        void CampanyGameMenuState();
    
        //
        void InChapter1GameState();
    
        //
        void Chapter1GameResultsState();
    
        //
        void InChapter2GameState();
    
        //
        void Chapter2GameResultsState();
    
        //
        void InChapter3GameState();
    
        //
        void Chapter3GameResultsState();
    
        //
        void InEndlessGameState();
    
        //
        void EndlessGameResultsState();
        
    };
}

#endif //STATE_SYSTEM_TYPE_HEADER