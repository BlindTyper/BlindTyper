/*

*/

#ifndef PLAYER_TYPE_HEADER
#define PLAYER_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "PlayerStatComponent.hpp"

namespace tppo {
    class Player : public Entity {
        
    protected:
        //
        std::shared_ptr<PlayerStatComponent> playerStatComponent;
        
    public:
        //
        Player(
            std::shared_ptr<PlayerStatComponent> &playerStatComponent
        );
        
        //
        std::shared_ptr<PlayerStatComponent> &GetPlayerStatComponent();
        
        
    };
}
#endif //PLAYER_TYPE_HEADER
