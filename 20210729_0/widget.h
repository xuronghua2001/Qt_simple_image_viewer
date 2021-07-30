#ifndef WIDGET_H
#define WIDGET_H
#include<QFont>
#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *timer=new QTimer;
    QTimer *timer_0=new QTimer;

private slots:
    void on_pushButton_clicked();
    void onTimerOut();
    void yaoLaiLe();
    void yaoLaiLe2();
    void on_pushButton_2_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
