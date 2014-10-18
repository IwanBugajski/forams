#include "foramsmainwindow.h"
#include "ui_foramsmainwindow.h"
#include <QtOpenGL>

ForamsMainWindow::ForamsMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForamsMainWindow)
{
    ui->setupUi(this);
}

ForamsMainWindow::~ForamsMainWindow()
{
    delete ui;
}
