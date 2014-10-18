#include "vector.h"
#include <math.h>
Vector::Vector(){}

Vector::Vector(Vertex v1, Vertex v2){
    this->x = v2.x - v1.x;
    this->y = v2.y - v1.y;
    this->z = v2.z - v1.z;
}

void Vector::normalize(){
    float l = length();
    x /= l;
    y /= l;
    z /= l;
}

Vector Vector::cross(Vector v){
    return Vector(
                this->y * v.z - this->z * v.y,
                this->z * v.x - this->x * v.z,
                this->x * v.y - this->y * v.x);
}

float Vector::dot(Vector v){
    return x * v.x + y * v.y + z * v.z;
}

float Vector::length(){
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
