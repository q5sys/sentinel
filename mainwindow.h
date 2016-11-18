#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    static QString BytesToDisplaySize(qint64 ibytes);
    void addProc();
    void updateProcs();
    void getActiveConnections();
    void getPID();
    void getProcessName();
    void getRoute();
    void getDevice();
    void sumOut();
    void sumIn();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


/*
 * net.inet.tcp.pcblist

#define	KERN_IPC_MB_STAT	"kern.ipc.mb_stat"
#include <sys/sysctl.h>
*/
class Proc{
private:
        QString i_pid, i_user, i_route, i_device, i_out, i_in; //internal vars
public:
        Proc(QString pid="", QString user="", QString route="", QString device="", QString out="", QString in=""){
          i_pid=pid; i_user=user; i_route=route; i_device=device; i_out=out; i_in=in;
        }
        ~Proc(){
          i_pid.clear(); i_user.clear(); i_route.clear(); i_device.clear(); i_out.clear(); i_in.clear();
        }
        //Main info functions
        const QString pid() const { return i_pid; }
        const QString user() const { return i_user; }
        const QString route() const { return i_route; }
        const QString device() const { return i_device; }
        const QString out() const { return i_out; }
        const QString in() const { return i_in; }

};

//General class for loading/saving/finding proc information
class ProcList : public QList<Proc>{
};
extern ProcList PROCS;
