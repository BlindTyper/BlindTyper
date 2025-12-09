/*

*/

#ifndef VEC3D_TYPE_HEADER
#define VEC3D_TYPE_HEADER

namespace tppo {
    class Vec3d {
    
    public:
        long double x, y;
        union {
            long double z;
            long double w;
        };
        
    };
}

#endif //VEC3D_TYPE_HEADER
