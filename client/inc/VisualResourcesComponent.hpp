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
        std::unordered_map<std::uint64_t, std::uint64_t> fontSizeToFontNumber;
        
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
        void AddFont(std::string &pathToFile, std::uint64_t fontSize);
        
        //
        void AddFont(std::string &&pathToFile, std::uint64_t fontSize);
        
        //
        std::uint64_t GetFontNum(std::uint64_t fontSize);
        
        //
        void AddCharToTextureName(char letter, std::string &pathToFile);
        
        //
        std::string &CharToTextureName(char letter);
        
    };
}

#endif //VISUAL_RESOURCES_COMPONENT_TYPE_HEADER   
