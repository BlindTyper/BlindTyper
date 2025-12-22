/*

*/

#ifndef BACKGROUND_TYPE_HEADER
#define BACKGROUND_TYPE_HEADER

#include <memory>

#include "Entity.hpp"

#include "VisualComponent.hpp"
#include "ApplicationSettingsComponent.hpp"

namespace tppo {
    class Background : public Entity {
        
    protected:
        //
        std::shared_ptr<VisualComponent> visual;
        
    public:
        //
        Background(
            std::shared_ptr<VisualComponent> &visual,
            std::shared_ptr<ApplicationSettingsComponent> &settings
        );
        
        //
        std::shared_ptr<VisualComponent> &GetVisual();
    };
}
#endif //BACKGROUND_TYPE_HEADER
