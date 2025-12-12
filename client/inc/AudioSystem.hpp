/*

*/

#ifndef AUDIO_SYSTEM_TYPE_HEADER
#define AUDIO_SYSTEM_TYPE_HEADER

#include "System.hpp"

namespace tppo {
    class AudioSystem : System {
        
    protected:
        
        
    public:
        //
        AudioSystem(ComponentManager &componentManager, EntityManager &entityManager);
        
        //
        ~AudioSystem();
    
        //
        void Init();
    
        //
        void Update();
        
    };
}

#endif //AUDIO_SYSTEM_TYPE_HEADER