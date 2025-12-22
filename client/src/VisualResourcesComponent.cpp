/*

*/

#include "VisualResourcesComponent.hpp"

namespace tppo {
    //
    VisualResourcesComponent::VisualResourcesComponent(uint64_t ownerId) 
        : Component(ownerId) {
        
    }
    
    //
    void VisualResourcesComponent::AddTexture(std::string &pathToFile) {
        textures.emplace(pathToFile, pathToFile);
    }
        
    //
    sf::Texture &VisualResourcesComponent::GetTexture(std::string &pathToFile) {
        try {
            return textures.at(pathToFile);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from VisualResourcesComponent sf::Texture with pathName: " << pathToFile << std::endl;
            exit(1);
        }
    }
        
    //
    sf::Texture &VisualResourcesComponent::GetTexture(std::string &&pathToFile) {
        try {
            return textures.at(pathToFile);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from VisualResourcesComponent sf::Texture with pathName: " << pathToFile << std::endl;
            exit(1);
        }
    }
        
    //
    ImFontConfig &VisualResourcesComponent::GetFontConfig() {
        return fontConfig;
    }
        
    //
    void VisualResourcesComponent::AddCharToTextureName(char letter, std::string &pathToFile) {
        charToTextureName.emplace(letter, pathToFile);
    }
    
    //
    std::string &VisualResourcesComponent::CharToTextureName(char letter) {
        try {
            return charToTextureName.at(letter);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from VisualResourcesComponent std::string with letter: " << letter << std::endl;
            exit(1);
        } 
    }
}