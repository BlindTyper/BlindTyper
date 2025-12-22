/*

*/

#ifndef VISUAL_COMPONENT_TYPE_HEADER
#define VISUAL_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

namespace tppo {
    class VisualComponent : public Component {

    protected:
        //
        sf::Texture &texture;
        
        //
        sf::Sprite sprite;
        
        //
        bool isVisible;
        
    public:
        //
        VisualComponent(
            std::uint64_t ownerId, 
            sf::Texture &texture,
            bool isVisible = true
        );
        
        //
        sf::Texture &GetTexture();
        
        //
        sf::Sprite &GetSprite();
        
        //
        void Show();
        
        //
        void Hide();
        
        //
        bool &IsVisible();
    };
}

#endif //VISUAL_COMPONENT_TYPE_HEADER   
