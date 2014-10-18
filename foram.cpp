#include "foram.h"
#include "triangle.h"
#include <iostream>
Foram::Foram(){}

void Foram::setChamberModel(std::vector<Vertex> chamberModel){
    this->chamber = chamberModel;
}

void Foram::setAperture(Vertex apertue){
    this->currentAperture = apertue;
}

void Foram::addChamber(float vx, float vy, float vz, float horizontalAngle, float verticalAngle){

}

Vertex Foram::calculateAperture(){
    Vertex result;
    std::vector<Vertex> closest;
    float minDistance = 0.0f;
    int minDistanceIndex = -1;

    //find closest point of each triangle
    for(int i = 0; i < chamber.size(); i += 3){
        Triangle t = Triangle(chamber[i], chamber[i + 1], chamber[i + 2]);
        Vertex v = t.closest(currentAperture);
        closest.push_back(v);
        if((minDistanceIndex == -1) || (minDistance > currentAperture.distance(v))){
            minDistance = currentAperture.distance(v);
            minDistanceIndex = closest.size() - 1;
        }
    }

    return closest[minDistanceIndex];
}
