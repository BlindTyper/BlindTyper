/*

*/

#ifndef VISUAL_RESOURCES_COMPONENT_TYPE_HEADER
#define VISUAL_RESOURCES_COMPONENT_TYPE_HEADER

#include "Main.hpp"

#include "Component.hpp"

#include <iostream>
#include <unordered_map>

namespace tppo {
    class VisualResourcesComponent : public Component {

    protected:
        //
        std::unordered_map<std::string, sf::Texture> textures;
        
        //
        std::unordered_map<char, std::string> charToTextureName;
        
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
        
        //
        void AddCharToTextureName(char letter, std::string &pathToFile);
        
        //
        std::string &CharToTextureName(char letter);
        
    };
}

#endif //VISUAL_RESOURCES_COMPONENT_TYPE_HEADER   
