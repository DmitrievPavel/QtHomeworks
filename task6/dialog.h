#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QCustomPlot* get_ptr();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
