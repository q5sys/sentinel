#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addProc(){
//  Host proc(ui->line_conn_ip->text(), ui->line_conn_name->text(), ui->line_conn_user->text(), ui->line_conn_pass->text());
//  PROCS << proc;
  updateProcs();
}
//PROCLIST FORMAT
// PID, USER, ROUTE, DEVICE, SENT, RECEIVED


void MainWindow::updateProcs(){
  ui->tree_procs->clear();
for(int i=0; i<PROCS.length(); i++){
    QTreeWidgetItem *it = new QTreeWidgetItem(ui->tree_procs);

    it->setText(0, PROCS[i].pid());
    it->setText(1, PROCS[i].user());
    it->setText(2, PROCS[i].route());
    it->setText(3, PROCS[i].device());
    it->setText(4, PROCS[i].out());
    it->setText(5, PROCS[i].in());
    ui->tree_procs->addTopLevelItem(it);
  }

  //sort the tree widget
  for(int i=0; i < ui->tree_procs->columnCount(); i++){
    ui->tree_procs->resizeColumnToContents(i);
  }
}

void MainWindow::getActiveConnections(){;}
void MainWindow::getPID(){;}
void MainWindow::getProcessName(){;}
void MainWindow::getRoute(){;}
void MainWindow::getDevice(){;}
void MainWindow::sumOut(){;}
void MainWindow::sumIn(){;}
