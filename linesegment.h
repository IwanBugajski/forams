#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "vertex.h"

class LineSegment{
private:
    Vertex a, b;

public:
    LineSegment();
    LineSegment(Vertex beg, Vertex end);
    Vertex closest(Vertex v);
};

#endif // LINESEGMENT_H
