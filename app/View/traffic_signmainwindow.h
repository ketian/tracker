#ifndef TRAFFIC_SIGNMAINWINDOW_H
#define TRAFFIC_SIGNMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Traffic_signMainWindow;
}

class Traffic_signMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Traffic_signMainWindow(QWidget *parent = 0);
    ~Traffic_signMainWindow();

private slots:
    void on_VideoButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Traffic_signMainWindow *ui;
};

#endif // TRAFFIC_SIGNMAINWINDOW_H
