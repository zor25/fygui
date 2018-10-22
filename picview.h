#ifndef PICVIEW_H
#define PICVIEW_H

#include <QDialog>

namespace Ui {
class PicView;
}

class PicView : public QDialog
{
    Q_OBJECT

public:
    explicit PicView(QWidget *parent = 0);
    ~PicView();
    void displaypic(QString fl);

private:
    Ui::PicView *ui;
};

#endif // PICVIEW_H
