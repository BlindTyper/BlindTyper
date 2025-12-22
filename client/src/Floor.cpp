/*

*/

#include "Floor.hpp"

namespace tppo {
    //
    Floor::Floor(
        std::shared_ptr<VisualComponent> &visual,
        std::shared_ptr<TransformComponent> &transform,
        std::shared_ptr<BodyComponent> &body,
        std::shared_ptr<HealthComponent> &health
    ) 
        : visual(visual)
        , transform(transform)
        , body(body)
        , health(health)
    {
        
    }
    
    //
    std::shared_ptr<VisualComponent> &Floor::GetVisual() {
        return visual;
    }
    
    //
    std::shared_ptr<TransformComponent> &Floor::GetTransform() {
        return transform;
    }
    
    //
    std::shared_ptr<BodyComponent> &Floor::GetBody() {
        return body;
    }
    
    //
    std::shared_ptr<HealthComponent> &Floor::GetHealth() {
        return health;
    }
}