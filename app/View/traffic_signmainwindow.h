#ifndef TRAFFIC_SIGNMAINWINDOW_H
#define TRAFFIC_SIGNMAINWINDOW_H

#include <QMainWindow>
#include <memory>
namespace Ui {
class Traffic_signMainWindow;
}

class Traffic_signMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Traffic_signMainWindow(QWidget *parent = 0);
    ~Traffic_signMainWindow();
    void SetOpenCommand(std::shared_ptr <ICommand> & ptr)
    {
    	sp_OpenCommand = std::dynamic_pointer_cast<OpenCommand> ptr;
    }
private slots:
    void on_VideoButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Traffic_signMainWindow *ui;
    std::shared_ptr <OpenCommand> sp_OpenCommand;
};

#endif // TRAFFIC_SIGNMAINWINDOW_H
