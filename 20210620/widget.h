#ifndef WIDGET_H
#define WIDGET_H
#include <QFileSystemModel>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListView>
#include <QDir>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include<QListWidget>
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
 //   void onDoubleClick_listView(const QModelIndex& index);
 //   void selectChanged_listView(const QItemSelection& selection);
  //  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    QVBoxLayout* mainLayout;
    QStringListModel* m_string_list_model = new QStringListModel();
    QFileSystemModel *fm;
    QStringListModel *model;
    static QFileInfoList fileInfoList;
    QString curFileName;




  /*  QString m_dir_str;
    QLineEdit* m_input_edit;
    QListView* m_file_list_view;
    QStringListModel* m_string_list_model;
    QSortFilterProxyModel* m_proxy_model;*/
    Ui::Widget *ui;
};
#endif // WIDGET_H
