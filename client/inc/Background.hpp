/*

*/

#ifndef BACKGROUND_TYPE_HEADER
#define BACKGROUND_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "SoundComponent.hpp"

namespace tppo {
    class Background : Entity {
        
    protected:
        VisualComponent *visual;
        SoundComponent *sound;
        
    public:
        
    };
}
#endif //BACKGROUND_TYPE_HEADER
