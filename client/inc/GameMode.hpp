/*

*/

#ifndef GAME_MODE_TYPE_HEADER
#define GAME_MODE_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "GameModeComponent.hpp"

namespace tppo {
    class GameMode : public Entity {
        
    protected:
        //
        std::shared_ptr<GameModeComponent> gameMode;
        
    public:
        //
        GameMode(
            std::shared_ptr<GameModeComponent> &gameMode
        );
        
        //
        void SetGameMode(std::shared_ptr<GameModeComponent> &gameMode);
        
        //
        std::shared_ptr<GameModeComponent> &GetGameMode();
    };
}
#endif //GAME_MODE_TYPE_HEADER
