#include "vertex.h"
#include <math.h>

Vertex::Vertex()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

Vertex::Vertex(float X, float Y, float Z){
    this->x = X;
    this->y = Y;
    this->z = Z;
}

float Vertex::distance(Vertex v){
    return (float) sqrt(pow(this->x-v.x, 2) + pow(this->y-v.y, 2) + pow(this->z-v.z, 2));
}
