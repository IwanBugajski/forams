#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <QString>
#include <QStringList>
#include <math.h>
#include "exception.h"
using namespace std;

struct Vertex{
    float coordinates[3];
    float normal[3];

    Vertex() {}

    Vertex(float x, float y, float z){
        coordinates[0] = x; coordinates[1] = y; coordinates[2] = z;
    }

    void rescale(float * scale){
        for(int i = 0; i < 3; i++){
            coordinates[i] *= 1.0 / scale[i];
        }
    }
};


class ObjLoader {
private:
    unsigned int index;
    vector<Vertex> vertices;
    vector<vector <Vertex> > polygons;
    void rescale();

public:
    ObjLoader();
    void load(string path);
    void rewind();
    bool hasNextPolygon();
    vector<Vertex> nextPolygon();
};

#endif // OBJLOADER_H
