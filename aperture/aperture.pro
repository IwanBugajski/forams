TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vertex.cpp \
    foram.cpp \
    chamber.cpp \
    vector.cpp \
    triangle.cpp \
    linesegment.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vertex.h \
    foram.h \
    chamber.h \
    vector.h \
    triangle.h \
    linesegment.h

