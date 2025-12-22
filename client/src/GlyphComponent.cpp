/*

*/

#include "GlyphComponent.hpp"

namespace tppo {
    //
    GlyphComponent::GlyphComponent(
        std::uint64_t ownerId,
        char glyph
    )
        : Component(ownerId)
        , glyph(glyph)
    {
        
    }
    
    //
    char GlyphComponent::GetGlyph() {
        return glyph;
    }
}