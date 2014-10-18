#ifndef FORAMSMAINWINDOW_H
#define FORAMSMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ForamsMainWindow;
}

class ForamsMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForamsMainWindow(QWidget *parent = 0);
    ~ForamsMainWindow();

private:
    Ui::ForamsMainWindow *ui;
};

#endif // FORAMSMAINWINDOW_H
