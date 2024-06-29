#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"
#include <vector>
typedef struct ray
{
    Vector3 origin;
    Vector3 dir;
    bool hit;
    Vector3 hitpoint;
} Ray;


class Camera
{
    public:
        Vector3 pos;
        Vector3 dir;
        float FOV;
        std::vector<std::vector<Ray>> rays;
        Camera(Vector3 pos = Vector3(), Vector3 dir = Vector3(1,0,0), float FOV = 60);
};

#endif