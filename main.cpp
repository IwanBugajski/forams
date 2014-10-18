#include <iostream>
#include <vector>
#include "vertex.h"
#include "foram.h"
#include "vector.h";

using namespace std;

int main()
{
    Foram foram;
    vector<Vertex> chamberModel;
//    chamberModel.push_back(Vertex(-1.0, 1.0, 0.0));
//    chamberModel.push_back(Vertex(1.0, 1.0, 0.0));
//    chamberModel.push_back(Vertex(0.0, 1.0, 1.0));
//    chamberModel.push_back(Vertex(1.0, 1.0, -3.0));
//    chamberModel.push_back(Vertex(2.0, -1.0, 0.0));
//    chamberModel.push_back(Vertex(1.0, -1.0, 1.0));
    chamberModel.push_back(Vertex(1.0, 0.0, 0.0));
    chamberModel.push_back(Vertex(0.0, 1.0, 0.0));
    chamberModel.push_back(Vertex(0.0, 0.0, 1.0));
    foram.setAperture(Vertex(4, 5, 4));
    foram.setChamberModel(chamberModel);

    Vertex aperture = foram.calculateAperture();
    cout << endl << aperture.x << endl << aperture.y << endl << aperture.z << endl;
    return 0;
}

