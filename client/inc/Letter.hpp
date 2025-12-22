//
// Created by anna_ on 07.12.2025.
//

#ifndef LETTER_TYPE_HEADER
#define LETTER_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "TransformComponent.hpp"
#include "BodyComponent.hpp"
#include "MovementComponent.hpp"
#include "GlyphComponent.hpp"
#include "DamageComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo {
    class Letter : public Entity {
        
    protected:
        //
        std::shared_ptr<VisualComponent> visual;
        
        //
        std::shared_ptr<TransformComponent> transform;
        
        //
        std::shared_ptr<BodyComponent> body;
        
        //
        std::shared_ptr<MovementComponent> movement;
        
        //
        std::shared_ptr<GlyphComponent> glyph;
        
        //
        std::shared_ptr<DamageComponent> damage;
        
        //
        std::shared_ptr<SoundComponent> sound;
        
    public:
        //
        Letter(
            std::shared_ptr<VisualComponent> &visual,
            std::shared_ptr<TransformComponent> &transform,
            std::shared_ptr<BodyComponent> &body,
            std::shared_ptr<MovementComponent> &movement,
            std::shared_ptr<GlyphComponent> &glyph,
            std::shared_ptr<DamageComponent> &damage
        );
        
        //
        std::shared_ptr<VisualComponent> &GetVisual();
        
        //
        std::shared_ptr<TransformComponent> &GetTransform();
        
        //
        std::shared_ptr<BodyComponent> &GetBody();
        
        //
        std::shared_ptr<MovementComponent> &GetMovement();
        
        //
        std::shared_ptr<GlyphComponent> &GetGlyph();
        
        //
        std::shared_ptr<DamageComponent> &GetDamage();
        
    };
}
#endif //LETTER_TYPE_HEADER
