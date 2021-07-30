#include "widget.h"
#include "ui_widget.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtCore>
#include <QTimer>
#include <iostream>
#include <QIcon>
#include <QDebug>
#include <QMessageBox>
using namespace std ;
static int sum,j,k,s,ss,b,c,d,q,a;
QString url,z;
QString url_prefix,url_suffix;
QNetworkAccessManager *manager = new QNetworkAccessManager();
class atiNet : public QObject
{
    Q_OBJECT
public:
    explicit atiNet();
     static QString  getHtml(QString url);
     static int checkNetWorkOnline(QString);

signals:
public slots:
     void replyFinished(QNetworkReply*);
};

int atiNet::checkNetWorkOnline(QString url)
{
    QNetworkRequest request;
    QEventLoop eventLoop;
    request.setUrl(QUrl(url));
    QNetworkReply* reply = manager->get(request);
    connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    int i=reply->error();
    reply->deleteLater();
    if (i==0)
        return 1;
    else
        return 0;
}
void atiNet::replyFinished(QNetworkReply*rply)
{

     rply->deleteLater();
}
QString  atiNet::getHtml(QString url)
   {
       QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
       reply->deleteLater();
       QByteArray responseData;
       QEventLoop eventLoop;
       connect(manager, SIGNAL(finished(QNetworkReply*)),&eventLoop, SLOT(quit()));
       eventLoop.exec();       //block until finish
       responseData = reply->readAll();
       reply->deleteLater();
       return QString(responseData);
   }
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{       ui->setupUi(this);
        connect(timer, &QTimer::timeout, this, [&](){
            ui->pushButton->click();
        });
        timer->start(10000);
        k=10,ss=0;
        connect(timer_0, SIGNAL(timeout()), this, SLOT(onTimerOut()));
        timer_0->start(1000);
        QFont f;
        f.setPointSize(20);
        ui->label->setFont(f);
        connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(yaoLaiLe()));
}
Widget::~Widget()
{
    delete ui;
}
void Widget::yaoLaiLe()
{
    QMessageBox::information(nullptr,"提示","在线人数发生变化\n请检查！");
}
void Widget::yaoLaiLe2()
{
    QMessageBox::warning(nullptr,"提示","check过于频繁\n请过段时间后\nremake检查！");
}
void Widget::onTimerOut()
{
     if(k>=0)
     {ui->lcdNumber->display(k);k--;}
     else
     {k=10;ss++;ui->lcdNumber_2->display(ss);}
}
void Widget::on_pushButton_clicked()
{
    if (atiNet::checkNetWorkOnline("https://www.baidu.com")){
    sum=0;url_prefix="https://api.bilibili.com/x/space/acc/info?mid=";
    a=0;b=0;c=0;d=0;q=0;s=0;url_suffix="&jsonp=jsonp";
    if (ui->checkBox->isChecked())
    {
        url=url_prefix+"672328094"+url_suffix;
        QString html= atiNet::getHtml(url);
        QString liveState="liveStatus";
        int i=html.lastIndexOf(liveState);        
        z = html.mid(i+21,34);ui->lineEdit->setText(z);
        QString y = html.mid(i+12, 1);
        j=y.toInt();
        if (j==1)
        {d=1;sum++;}}
    if(ui->checkBox_2->isChecked())
    {
        url=url_prefix+"351609538"+url_suffix;
        QString html= atiNet::getHtml(url);
        QString liveState="liveStatus";
        int i=html.lastIndexOf(liveState);
        z = html.mid(i+21,34);ui->lineEdit->setText(z);
        QString y = html.mid(i+12, 1);
        j=y.toInt();
        if (j==1)
        {c=1;sum++;}}
    if(ui->checkBox_3->isChecked())
    {
        url=url_prefix+"672346917"+url_suffix;
        QString html= atiNet::getHtml(url);
        QString liveState="liveStatus";
        int i=html.lastIndexOf(liveState);
        z = html.mid(i+21,34);ui->lineEdit->setText(z);
        QString y = html.mid(i+12, 1);
        j=y.toInt();
        if (j==1)
        {a=1;sum++;}}
    if(ui->checkBox_4->isChecked())
    {
        url=url_prefix+"672342685"+url_suffix;
        QString html= atiNet::getHtml(url);
        QString liveState="liveStatus";
        int i=html.lastIndexOf(liveState);
        z = html.mid(i+21,34);ui->lineEdit->setText(z);
        QString y = html.mid(i+12, 1);
        j=y.toInt();
        if (j==1)
        {q=1;sum++;}}
    if(ui->checkBox_5->isChecked())
    {
        url=url_prefix+"672353429"+url_suffix;
        QString html= atiNet::getHtml(url);
        QString liveState="liveStatus";
        int i=html.lastIndexOf(liveState);
        z = html.mid(i+21,34);ui->lineEdit->setText(z);
        QString y = html.mid(i+12, 1);
        j=y.toInt();
        if (j==1)
        {b=1;sum++;}}
    url=url_prefix+"434334701"+url_suffix;
    QString html= atiNet::getHtml(url);
    QString liveState="liveStatus";
    int i=html.lastIndexOf(liveState);
    z="";
    QString y = html.mid(i+12, 1);
    j=y.toInt();
    if(j==2)
    {   timer->stop();
        timer_0->stop();
       ui->label->setText("请求被拦截");
       yaoLaiLe2();
       ui->lineEdit_2->setText("在线人数：未知");
    }
    else if (j==1)
     {s=1;sum++;}
    QString str2="在线人数：";
    str2+=QString::number(a+b+c+d+q+s);
    if (sum)
    {
        QString str;
        str="还好有";
        if(d)str+="嘉然";
        if(a)str+="向晚";
        if(c)str+="珈乐";
        if(b)str+="贝拉";
        if(q)str+="乃琳";
        if(s)str+="七海";
        str+="在直播";
        ui->label->setText(str);
        ui->lineEdit_2->setText(str2);
        ui->lineEdit->setText(z);
    }
    else
    {
        ui->lineEdit_2->setText(str2);
        ui->label->setText("紫砂了");
        if (j!=2)
        ui->lineEdit_2->setText("在线人数：0");
    }
    }
else
    {timer->stop();timer_0->stop();
        QMessageBox::warning(nullptr,"提示","无法连接到互联网\n请检查电脑联网后双击remake！");
        }


}
void Widget::on_pushButton_2_clicked(bool checked)
{if (checked==0)
    {    ui->checkBox->setChecked(0);
        ui->checkBox_2->setChecked(0);
        ui->checkBox_3->setChecked(0);
        ui->checkBox_4->setChecked(0);
        ui->checkBox_5->setChecked(0);
    a=0;b=0;c=0;q=0;s=0;d=0;QIcon icon(":/i/0.png");
    setWindowIcon(icon);}
else
   { ui->checkBox->setChecked(1);
    ui->checkBox_2->setChecked(1);
    ui->checkBox_3->setChecked(1);
    ui->checkBox_4->setChecked(1);
    ui->checkBox_5->setChecked(1);
    if (!timer->isActive())
    {timer->start(10000);timer_0->start(1000);}
    QIcon icon(":/i/1.png");
    setWindowIcon(icon);
    }
    j=0;
}
