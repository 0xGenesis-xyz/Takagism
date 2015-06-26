#ifndef Takagism_Object_h
#define Takagism_Object_h

class Object {
public:
    float x;
    float y;
    float z;
    float direct;
    float size;
public:
    Object() {}
    Object(float x, float y, float z, float direct, float size) :
        x(x), y(y), z(z), direct(direct), size(size)
    {}
};

#endif
