#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
    float x, y, z;
    Vertex();
    Vertex(float X, float Y, float Z);
    float distance(Vertex v);
};

#endif // VERTEX_H
