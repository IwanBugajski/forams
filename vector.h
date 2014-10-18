#ifndef VECTOR_H
#define VECTOR_H

#include "vertex.h"

class Vector : public Vertex
{
public:
    Vector();
    Vector(Vertex v1, Vertex v2);
    Vector(float X, float Y, float Z) : Vertex(X, Y, Z) {}
    Vector cross(Vector v);
    float dot(Vector v);
    float length();
    void normalize();
};

#endif // VECTOR_H
