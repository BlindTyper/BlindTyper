/*

*/

#include "Player.hpp"

namespace tppo {
    //
    Player::Player(
        std::shared_ptr<PlayerStatComponent> &playerStatComponent
    )
        : playerStatComponent(playerStatComponent) {
        
    }
    
    //
    std::shared_ptr<PlayerStatComponent> &Player::GetPlayerStatComponent() {
        return playerStatComponent;
    }
}