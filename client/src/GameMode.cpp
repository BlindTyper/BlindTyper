/*

*/

#include "GameMode.hpp"

namespace tppo {
    //
    GameMode::GameMode(std::shared_ptr<GameModeComponent> &gameMode) 
        : gameMode(gameMode) {
        
    }
        
    //
    void GameMode::SetGameMode(std::shared_ptr<GameModeComponent> &gameMode) {
        this->gameMode = gameMode;
    }
        
    //
    std::shared_ptr<GameModeComponent> &GameMode::GetGameMode() {
        return gameMode;
    }
}