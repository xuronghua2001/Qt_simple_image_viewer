#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QPainter>
#include<QPixmap>
#include<QFileInfo>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::~Widget()
{
    delete ui;
}
static int r,real_w,real_h,row;
static int w=0,h=0,j=0;
QString name=":/image/img/0.jpg";
void Widget::on_pushButton_clicked()
{
    QFileInfo f("image.qrc");
    QString qrc_path=f.absolutePath();
    QStringList fileNameList;
    QString filename=QFileDialog::getExistingDirectory(this,"选源文件夹",qrc_path);
    name=nullptr;
    QDir *fileDir=new QDir(filename);
    if (!fileDir->isEmpty()){
    QFileInfoList list=fileDir->entryInfoList();
    for(int i= 0; i != list.size(); i++)
        {
         QFileInfo f;
         f=list.at(i);
         QString  fi;
         fi=f.suffix();
             if( (fi!="jpg")&&(fi!="jpeg")&&(fi!="png")&&(fi!="bmp")&&(fi!="gif")&&(fi!="JPG")&&(fi!="JPEG")&&(fi!="PNG")&&(fi!="BMP")&&(fi!="GIF"))
             {
                 continue;
             }
             name = list.at(i).absoluteFilePath();
             fileNameList<<name;
         }
     model = new QStringListModel(fileNameList);
     ui->listView->setModel(model);
     ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     j=1;QModelIndex Index=ui->listView->model()->index(1,0);
     r=Index.row();
     row=ui->listView->model()->rowCount();}
     if (name==nullptr)
        QMessageBox::information(nullptr,"错误提示","指定目录中没有图片\n请重试！");
}

void Widget::on_listView_doubleClicked(QModelIndex index)
{
     w=0,h=0;
     name=index.data().toString();
     r=index.row();
     update();
}
void Widget::paintEvent(QPaintEvent *)
{
    if(name!=nullptr)
    {QPainter painter(this);
    QImage image(name);
    real_w=image.width();
    real_h=image.height();
    QPixmap pixmap=QPixmap::fromImage(image);
    pixmap=pixmap.scaled(real_w+w,real_h+h,Qt::KeepAspectRatio);
    painter.drawPixmap(260,10,pixmap);}
}
void Widget::on_pushButton_4_clicked()
{
    QString infoList;
    QFileInfo info(name);
           if (info.exists())
            {
              infoList += tr("文件格式: %1 \n").arg(info.suffix());
              infoList += tr("文件名称: %1 \n").arg(info.fileName());
              infoList += tr("文件大小: %1 KB\n").arg(info.size()/1024);
              infoList += tr("修改时间: %1 \n").arg(info.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
              infoList += tr("读取时间: %1 \n").arg(info.lastRead().toString("yyyy-MM-dd hh:mm:ss"));
              infoList += tr("图片尺寸: %1 \n").arg(QString::number(real_w,'i',0) +"*"+ QString::number(real_h,'i',0));
              ui->label->setText(infoList);
           }
}
void Widget::on_pushButton_2_clicked()
{
    if(j&&r!=0){
   QModelIndex lastIndex=ui->listView->model()->index(r-1,0);
   if(r>0) r--;
   name=lastIndex.data().toString();
    update();}
}
void Widget::on_pushButton_3_clicked()
{
    if(j&&r!=row-1){
   QModelIndex nextIndex=ui->listView->model()->index(r+1,0);

    if(r<row) r++;
    name=nextIndex.data().toString();
     update();}

}
void Widget::on_pushButton_5_clicked()
{
    w+=20;
    h+=20;
    update();
}
void Widget::on_pushButton_6_clicked()
{
    w-=20;
    h-=20;
    update();
}
void Widget::on_pushButton_8_clicked()
{
    w=0;h=0;
    update();
}
void Widget::on_pushButton_7_clicked()
{
    w=this->width()-275-real_w;
    h=this->height()-real_h-25;
    update();
}
