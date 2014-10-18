#include <math.h>
#include <iostream>
#include "triangle.h"
#include "linesegment.h"
#include "vector.h"
Triangle::Triangle(){}

Triangle::Triangle(Vertex a, Vertex b, Vertex c){
    this->vertices[0] = a;
    this->vertices[1] = b;
    this->vertices[2] = c;
}

bool Triangle::contains(Vertex v){
    //create vectors between vertex v and each vertices of the triangle
    Vector va = Vector(v, vertices[0]);
    Vector vb = Vector(v, vertices[1]);
    Vector vc = Vector(v, vertices[2]);
    //calculate dot products between pairs of vectors
    float dotVaVb = va.dot(vb);
    float dotVbVc = vb.dot(vc);
    float dotVcVa = vc.dot(va);
    //calculate cosinuses of angles
    //cos(a) = (va * vb) / (|va| + |vb|)
    float cosAVB = dotVaVb / (va.length() * vb.length());
    float cosBVC = dotVbVc / (vb.length() * vc.length());
    float cosCVA = dotVcVa / (vc.length() * va.length());
    //calculate angles between vectors and convert to degrees
    float angleAVB = acos(cosAVB)*(180.0/M_PI);
    float angleBVC = acos(cosBVC)*(180.0/M_PI);
    float angleCVA = acos(cosCVA)*(180.0/M_PI);
    //if sum of 3 angles is equal 360 then point belongs to the triangle
    return (360 - fabs(angleAVB + angleBVC + angleCVA)) < 0.0001f;
}

Vertex Triangle::closest(Vertex v){
    Vertex result;
    //1.find the projections of Vertex v on plane
    //2.if projection belongs to the triangle return it
    //3.else find the closest point on the edge

    //find the form of the plane - calculate normal vector
    //the form of the plane is equal to ax + by + cz + d = 0
    //where [a, b, c] is normal vector
    Vector ab = Vector(vertices[0], vertices[1]);
    Vector ac = Vector(vertices[0], vertices[2]);
    Vector normal = ab.cross(ac);
    float d = - (normal.x * vertices[0].x + normal.y *  vertices[0].y + normal.z * vertices[0].z);

    //the line perpendicular to the plane:
    //x(t) = v.x + a*t
    //y(t) = v.y + b*t
    //z(t) = v.z + c*t
    //projection point belongs to both line and plane
    //so a*x(t) + b*y(t) + c*z(t) + d = 0
    //a*(v.x + a*t) + b*(v.y + b*t) + c*(v.z + c*t) + d = 0
    float a = normal.x, b = normal.y, c = normal.z;
    //find t:
    //a*v.x + a*a*t + b*v.y + b*b*t + c*v.z + c*c*t + d = 0
    //t * (a*a + b*b + c*c) = - (a*v.x + b*v.y + c*v.z + d)
    float t = -(a*v.x + b*v.y + c*v.z + d) / (a*a + b*b + c*c);
    //x(t) = v.x + a*t, etc..
    float x = v.x + a*t;
    float y = v.y + b*t;
    float z = v.z + c*t;
    result = Vertex(x, y, z);

    //now we check if projections point belongs to the triangle
    if(contains(result)) return result;

    //if projection point does not belong to the triangle - find the closest point on edge
    //we only check 2 closest edges - the ones containing the closest vertex of triangle
    float distanceA = vertices[0].distance(v);
    float distanceB = vertices[1].distance(v);
    float distanceC = vertices[2].distance(v);

    LineSegment edge1, edge2;

    //find closest vertex
    if(distanceA <= fmin(distanceB, distanceC)){
        edge1 = LineSegment(vertices[0], vertices[1]);
        edge2 = LineSegment(vertices[0], vertices[2]);
    }
    else if(distanceB <= fmin(distanceA, distanceC)){
        edge1 = LineSegment(vertices[1], vertices[2]);
        edge2 = LineSegment(vertices[1], vertices[0]);
    }
    else {
        edge1 = LineSegment(vertices[2], vertices[1]);
        edge2 = LineSegment(vertices[2], vertices[0]);
    }

    //find closest points on the edges
    Vertex closest1 = edge1.closest(v);
    Vertex closest2 = edge2.closest(v);

    if(closest1.distance(v) < closest2.distance(v)) return closest1;
    return closest2;
}
