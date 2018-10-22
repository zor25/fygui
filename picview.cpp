#include "picview.h"
#include "ui_picview.h"
#include <QPixmap>

PicView::PicView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PicView)
{
    ui->setupUi(this);
//    qDebug(this->filepath.toLatin1());
//    QPixmap currpic(this->filepath);
//    ui->label->setPixmap(currpic);
//    ui->label->setScaledContents(true);


}

void PicView::displaypic(QString fl) {
    qDebug(fl.toLatin1());
    QPixmap currpic(fl);
    ui->label->setPixmap(currpic);
}

PicView::~PicView()
{
    delete ui;
}
