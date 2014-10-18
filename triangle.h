#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"

class Triangle
{
private:
    Vertex * vertices = new Vertex[3];

public:
    Triangle();
    Triangle(Vertex a, Vertex b, Vertex c);
    Vertex closest(Vertex v);
    bool contains(Vertex v);
};

#endif // TRIANGLE_H
