#ifndef TRAFFIC_SIGNMAINWINDOW_H
#define TRAFFIC_SIGNMAINWINDOW_H

#include <QMainWindow>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <QtGui/QLabel>
#include "Common/OpenCommandParam.hpp"
#include "ViewModel/OpenCommand.hpp"
#include "ViewModel/TrafficSignViewModel.hpp"
#include <string>

namespace Ui {
class Traffic_signMainWindow;
}

class Traffic_signMainWindow : public QMainWindow
{
    Q_OBJECT

public:
	QLabel * GetLabel(const std::string &);
	boost::shared_ptr<QImage> GetImage();
    explicit Traffic_signMainWindow(QWidget *parent = 0);
    ~Traffic_signMainWindow();
    void SetOpenCommand(const boost::shared_ptr<ICommand> &ptr);
    void SetImage(const boost::shared_ptr<QImage> &ptr);

private slots:
    void on_VideoButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Traffic_signMainWindow *ui;
    boost::shared_ptr <OpenCommand> sp_OpenCommand;
    //boost::shared_ptr <TrafficSignViewModel> sp_ViewModel;
    boost::shared_ptr <QImage> sp_Image;
};

#endif // TRAFFIC_SIGNMAINWINDOW_H
