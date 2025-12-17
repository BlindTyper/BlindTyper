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
        
    public:
        Vec3d(
            long double x = 0, 
            long double y = 0,
            long double zw = 0
        ) : x(x), y(y), z(zw) {}
        
    };
}

#endif //VEC3D_TYPE_HEADER
