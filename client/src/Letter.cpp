/*

*/

#include "Letter.hpp"

namespace tppo {
    //
    Letter::Letter(
        std::shared_ptr<VisualComponent> &visual,
        std::shared_ptr<TransformComponent> &transform,
        std::shared_ptr<BodyComponent> &body,
        std::shared_ptr<MovementComponent> &movement,
        std::shared_ptr<GlyphComponent> &glyph,
        std::shared_ptr<DamageComponent> &damage
    ) 
        : visual(visual)
        , transform(transform)
        , body(body)
        , movement(movement)
        , glyph(glyph)
        , damage(damage)
    {
        
    }
    
    //
    std::shared_ptr<VisualComponent> &Letter::GetVisual() {
        return visual;
    }
    
    //
    std::shared_ptr<TransformComponent> &Letter::GetTransform() {
        return transform;
    }
    
    //
    std::shared_ptr<BodyComponent> &Letter::GetBody() {
        return body;
    }
    
    //
    std::shared_ptr<MovementComponent> &Letter::GetMovement() {
        return movement;
    }
    
    //
    std::shared_ptr<GlyphComponent> &Letter::GetGlyph() {
        return glyph;
    }
    
    //
    std::shared_ptr<DamageComponent> &Letter::GetDamage() {
        return damage;
    }
}