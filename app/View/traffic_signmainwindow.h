#ifndef TRAFFIC_SIGNMAINWINDOW_H
#define TRAFFIC_SIGNMAINWINDOW_H

#include <QMainWindow>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <QtGui>
#include "Common/OpenCommandParam.hpp"
#include "Common/ICommand.hpp"
#include "Common/INotification.hpp"
#include <string>

namespace Ui {
class Traffic_signMainWindow;
}

class Traffic_signMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTimer *running_timer;
	boost::shared_ptr<QImage> GetImage();
    boost::shared_ptr<INotification> GetEvent();
    explicit Traffic_signMainWindow(QWidget *parent = 0);
    ~Traffic_signMainWindow();
    void SetOpenCommand(const boost::shared_ptr<ICommand> &ptr);
    void SetReadCommand(const boost::shared_ptr<ICommand> &ptr);
    void SetRunCommand(const boost::shared_ptr<ICommand> &ptr);
    void SetImage(const boost::shared_ptr<QImage> &ptr);    
    QLabel *GetLabel(const std::string &);
    
private slots:
    void on_VideoButton_clicked();
    void on_ExitButton_clicked();
    void on_RunButton_clicked();
    void run();

private:
    Ui::Traffic_signMainWindow *ui;
    boost::shared_ptr<ICommand> sp_OpenCommand;
    boost::shared_ptr<ICommand> sp_ReadCommand;
    boost::shared_ptr<ICommand> sp_RunCommand;
    boost::shared_ptr<QImage> sp_Image;
    boost::shared_ptr<INotification> sp_Event;
    bool init_flag;
};

#endif // TRAFFIC_SIGNMAINWINDOW_H
