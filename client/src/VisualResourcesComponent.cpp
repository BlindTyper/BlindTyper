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
    void VisualResourcesComponent::AddFont(std::string &pathToFile, std::uint64_t fontSize) {
        ImGuiIO &io = ImGui::GetIO();
        fontSizeToFontNumber.emplace(fontSize, io.Fonts->Fonts.size());
        io.Fonts->AddFontFromFileTTF(pathToFile.c_str(), fontSize, &fontConfig);
    }
    
    //
    void VisualResourcesComponent::AddFont(std::string &&pathToFile, std::uint64_t fontSize) {
        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->Clear();
        fontSizeToFontNumber.emplace(fontSize, io.Fonts->Fonts.size());
        io.Fonts->AddFontFromFileTTF(pathToFile.c_str(), fontSize, &fontConfig);
    }
        
    //
    std::uint64_t VisualResourcesComponent::GetFontNum(std::uint64_t fontSize) {
        try {
            return fontSizeToFontNumber.at(fontSize);
        }
        catch (std::out_of_range &e) {
            std::cerr << "Error:\nGetting from VisualResourcesComponent std::uint64_t with fontSize: " << fontSize << std::endl;
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