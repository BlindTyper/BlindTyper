/*

*/

#ifndef GLYPH_COMPONENT_TYPE_HEADER
#define GLYPH_COMPONENT_TYPE_HEADER

#include "Component.hpp"

namespace tppo {
    class GlyphComponent : public Component {
        
    protected:
        //
        char glyph;
        
    public:
        //
        GlyphComponent(
            std::uint64_t ownerId,
            char glyph
        );
        
        //
        char GetGlyph();
    };
}

#endif //GLYPH_COMPONENT_TYPE_HEADER
