/*

*/

#ifndef ENTITY_MANAGER_TYPE_HEADER
#define ENTITY_MANAGER_TYPE_HEADER

#include "Main.hpp"

#include <cstdint>
#include <unordered_map>

#include "Manager.hpp"
#include "ComponentManager.hpp"

#include "Entity.hpp"
#include "SystemResources.hpp"
#include "Letter.hpp"
#include "Floor.hpp"
#include "Player.hpp"
#include "Background.hpp"
//#include "GameMode.hpp"

namespace tppo{
    class EntityManager : Manager{
        
    protected:
        //
        ComponentManager &componentManager;
    
        //
        std::shared_ptr<SystemResources> systemResources;
        
        //
        std::unordered_map<uint64_t, Letter> letters;
        
        //
        std::unordered_map<uint64_t, Floor> floors;
        
        //
        std::unordered_map<uint64_t, Player> players;
        
        //
        std::unordered_map<uint64_t, Background> backgrounds;
        
        //
        //std::unordered_map<uint64_t, GameMode> GameModes;
        
    public:
        //
        EntityManager(ComponentManager &componentManager);
        
        //
        ~EntityManager();
        
        //
        void Init();
        
        //
        SystemResources &GetSystemResources();
        
    };
}
#endif //ENTITY_MANAGER_TYPE_HEADER
