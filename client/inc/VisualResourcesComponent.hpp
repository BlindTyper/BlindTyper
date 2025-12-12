/*

*/

#ifndef VISUAL_RESOURCES_COMPONENT_TYPE_HEADER
#define VISUAL_RESOURCES_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

#include <iostream>
#include <unordered_map>

namespace tppo {
    class VisualResourcesComponent : Component {

    protected:
        //
        std::unordered_map<std::string, sf::Texture> textures;
        
        //
        ImFontConfig fontConfig;
        
    public:
        //
        VisualResourcesComponent(uint64_t ownerId);
    
        //
        void AddTexture(std::string &pathToFile);
        
        //
        sf::Texture &GetTexture(std::string &pathToFile);
        
        //
        sf::Texture &GetTexture(std::string &&pathToFile);
        
        //
        ImFontConfig &GetFontConfig();
        
    };
}

#endif //VISUAL_RESOURCES_COMPONENT_TYPE_HEADER   
