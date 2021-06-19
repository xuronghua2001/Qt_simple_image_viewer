#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QListView>
#include <QDir>
#include <QStringListModel>
#include <QMessageBox>
#include<QPaintEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_listView_doubleClicked(QModelIndex index);

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    QStringListModel *model;
    Ui::Widget *ui;
};
#endif // WIDGET_H
