#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "picview.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setDragEnabled(true);
    ui->label->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
   ui->lineEdit->setText(fileName);


   PicView picv;
//   picv.filepath = fileName;
//   qDebug(fileName.toLatin1());
//   qDebug(picv.filepath.toLatin1());
   picv.setModal(true);
   picv.displaypic(fileName);
   picv.exec();


}

void MainWindow::on_proc_button_clicked()
{
    QFile file("/home/abdur/Pictures/images/001_001_1.gt.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"info",file.errorString());
    }

    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());
}
