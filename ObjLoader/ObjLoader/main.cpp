#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "objloader.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string fileName = "C:\\Meine\\Works\\studia\\inz\\Obj\\cube2.obj";

    ObjLoader objLoader = ObjLoader();

    try {
        objLoader.load(fileName);
    } catch(Exception * e) {
        cout << e->getMessage();
    }

    try {
        vector<Vertex> polygon;

        while(objLoader.hasNextPolygon()){
            polygon = objLoader.nextPolygon();
            for(int i = 0; i < polygon.size(); i++){
                Vertex v = polygon.at(i);
                for(int j = 0; j < 3; j++){
                    cout << v.coordinates[j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    } catch (Exception * e) {
        cout << e->getMessage();
    }

    return a.exec();
}
