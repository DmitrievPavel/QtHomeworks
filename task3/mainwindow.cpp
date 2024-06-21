#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_1->setText("Кнопка 1");
    ui->rb_2->setText("Кнопка 2");
    for (int i = 1; i <= 10; ++i){
        ui->cb_list->addItem(QString("Элемент списка %1").arg(i));
    }
    ui->pb_button->setText("Большая кнопка");
    ui->pb_button->setCheckable(true);
    ui->prb_prog->setMinimum(0);
    ui->prb_prog->setMaximum(10);
    ui->prb_prog->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_button_toggled(bool checked)
{
    int prog = ui->prb_prog->value();
    if(prog == 10) {
       ui->prb_prog->setValue(0);
    }else {
        ui->prb_prog->setValue(++prog);
    }
}

