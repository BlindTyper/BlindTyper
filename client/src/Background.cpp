/*

*/

#include "Background.hpp"

namespace tppo {
    //
    Background::Background(
        std::shared_ptr<VisualComponent> &visual,
        std::shared_ptr<ApplicationSettingsComponent> &settings
    ) 
        : visual(visual) {
        sf::Texture &texture = this->visual->GetTexture();
        sf::Sprite &sprite = this->visual->GetSprite();
        
        float x = float(settings->GetWindowVideoMode().size.x) / float(texture.getSize().x);
        float y =  float(settings->GetWindowVideoMode().size.y) / float(texture.getSize().y);
        
        sprite.setScale({x, y});
    }
}