#ifndef FORAM_H
#define FORAM_H

#include <vector>
#include "vertex.h"
#include "chamber.h"

class Foram{
private:
    std::vector<Vertex> chamber;
    std::vector<Vertex> model;
    std::vector<Chamber> chambers;
    Vertex currentAperture;

public:
    Foram();
    void setChamberModel(std::vector<Vertex> chamberModel);
    void setAperture(Vertex apertue);
    void addChamber(float vx, float vy, float vz, float horizontalAngle, float verticalAngle);
    Vertex calculateAperture();
};

#endif // FORAM_H
