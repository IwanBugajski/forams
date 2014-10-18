#include "linesegment.h"

LineSegment::LineSegment(){}

LineSegment::LineSegment(Vertex beg, Vertex end){
    this->a = beg;
    this->b = end;
}

Vertex LineSegment::closest(Vertex v){
    Vertex result, tmp;
    float min = -1.0f;

    for(float t = 0.0f; t <= 1.0f; t += 0.01f){
        tmp = Vertex(a.x+(b.x-a.x)*t, a.y+(b.y-a.y)*t, a.z+(b.z-a.z)*t);
        if((min == -1.0f) || (min > tmp.distance(v))) {
            result = tmp;
            min = tmp.distance(v);
        }
    }

    return result;
}
