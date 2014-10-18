#include "objloader.h"

ObjLoader::ObjLoader(){
    index = 0;
    vertices = vector<Vertex>();
    polygons = vector<vector<Vertex> >();
}

void ObjLoader::load(string path){
    //clear current data
    vertices.clear();
    polygons.clear();

    //opening give file
    ifstream objFile;
    objFile.open(path.c_str());

    //throwing file not found exception
    if(! objFile.is_open()) throw new FileNotFoundException("Unable to open file: " + path);

    //reading file line by line
    string line, type;
    unsigned int cnt = 1, i;

    while(getline(objFile, line)){
        //get type of a line
        type = line.substr(0, 2);

        //vertex
        if(type == "v "){
            //spliting line by space
            QString s = QString(line.substr(2).c_str());
            QStringList splitList = s.split(" ", QString::SkipEmptyParts);
            //creating new vertex
            Vertex v;
            bool successfulConversion;

            for(i = 0; i < min(3, splitList.count()); i++){
                v.coordinates[i] = splitList.at(i).toFloat(&successfulConversion);
                //check if conversion was successful
                if(!successfulConversion) throw new InvalidFileFormatException("Wrong vertex definition at line " + QString::number(cnt).toStdString());
            }
            //check if vertex definition consists of 3 numbers0
            if(i != 3) throw new InvalidFileFormatException("Wrong vertex definition at line " + QString::number(cnt).toStdString());
            //if ok - add new vertex
            vertices.push_back(v);
        }

        //polygon
        else if(type == "f "){
            //spliting line by space
            QString s = QString(line.substr(2).c_str());
            QStringList splitList = s.split(" ", QString::SkipEmptyParts);
            int vertexId;
            //creating new polygon
            polygons.push_back(vector<Vertex>());
            bool successfulConversion;
            for(i = 0; i < splitList.count(); i++){
                //determine if vertex is recorded as "n" or "n/n"
                if(splitList.at(i).contains("/")) s = splitList.at(i).left(splitList.at(i).indexOf("/"));
                else s = splitList.at(i);
                vertexId = s.toInt(&successfulConversion);
                //check if conversion was successful
                if(!successfulConversion) throw new InvalidFileFormatException("Wrong polygon definition at line " + QString::number(cnt).toStdString());
                //check if vertex id isn't aout of bound
                if((vertexId > vertices.size()) || (vertexId < 1)) throw new InvalidFileFormatException("Wrong polygon definition at line " + QString::number(cnt).toStdString());
                //if everything is ok - add vertex
                polygons.at(polygons.size() - 1).push_back(vertices.at(vertexId - 1));
            }
        }
        //anything else - ignore
        cnt++;
    }

    //count loaded data
    if(vertices.size() == 0) throw new InvalidFileFormatException("File has no vertex declarations");
    if(polygons.size() == 0) throw new InvalidFileFormatException("File has no polygon declarations");

    objFile.close();

    //rescale to 1.0
    rescale();
}

void ObjLoader::rescale(){
    //find maximum value on each axis
    float maxValues[] = {1.0f, 1.0f, 1.0f};
    Vertex current;

    for(int i = 0; i < vertices.size(); i++){
        current = vertices.at(i);
        //check each coordinate
        for(int j = 0; j < 3; j++){
            if(maxValues[j] < fabs(current.coordinates[j])) maxValues[j] = float(fabs(current.coordinates[j]));
        }
    }

    //rescale multiply each value by 1.0 / max

    //rescale vertices
    for(int i = 0; i < vertices.size(); i++){
        vertices.at(i).rescale(maxValues);
    }

    //rescale polygons
    for(int i = 0; i < polygons.size(); i++){
        for(int j = 0; j < polygons.at(j).size(); j++){
            polygons.at(i).at(j).rescale(maxValues);
        }
    }
}

void ObjLoader::rewind(){
    index = 0;
}

bool ObjLoader::hasNextPolygon(){
    return (index < polygons.size());
}

vector <Vertex> ObjLoader::nextPolygon(){
    if(! hasNextPolygon()) throw new IndexOutOfBoundsException("Index out of bound");
    return polygons.at(index++);
}
