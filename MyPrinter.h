#ifndef MYPRINTER_H
#define MYPRINTER_H

#include <QObject>

#include <QPrinter>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrintDialog>
#include <QStringList>
#include <QPaintDevice>
#include <QPaintEvent>
#include <QPrinterInfo>
#include <QDebug>
#include <QPoint>
#include <QFileDialog>
#include <QMessageBox>

/**
 * @Title: MyPrinter
 * @FileName: MyPrinter
 * @Description: 打印机驱动类
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 10:31:09
 * @update_author
 * @update_time
 * @version V1.0
*/
class MyPrinter : public QObject
{
    Q_OBJECT
public:
    explicit MyPrinter(QObject *parent = nullptr);

    //纸张打印大小定义
    enum MyPageSize {
        // Existing Qt sizes
        A4,
        B5,
        Letter,
        Legal,
        Executive,
        A0,
        A1,
        A2,
        A3,
        A5,
        A6,
        A7,
        A8,
        A9,
        B0,
        B1,
        B10,
        B2,
        B3,
        B4,
        B6,
        B7,
        B8,
        B9,
        C5E,
        Comm10E,
        DLE,
        Folio,
        Ledger,
        Tabloid,
        Custom,

        // New values derived from PPD standard
        A10,
        A3Extra,
        A4Extra,
        A4Plus,
        A4Small,
        A5Extra,
        B5Extra,

        JisB0,
        JisB1,
        JisB2,
        JisB3,
        JisB4,
        JisB5,
        JisB6,
        JisB7,
        JisB8,
        JisB9,
        JisB10,
    };

    //以下是打印机的相关属性设置
    void setXscale(qint8 scale);
    void setYscale(qint8 scale);
    void setXcoordinate(qint8 startCoordinate);
    void setYcoordinate(qint8 startCoordinate);
    void setPrinterPageSize(MyPageSize size);
    void setPrinterDriverName(QString driverName);
    void setPageSize(QSizeF size);
    void setPrintImg(const QPixmap &pixmap);

    //以下是获取打印机的相关属性
    qint8 getXscale();
    qint8 getYscale();
    qint8 getXcoordinate();
    qint8 getYcoordinate();
    MyPageSize getPrinterPageSize();
    QStringList getPrinterDevice();
    QSizeF getPageSize();
    QPixmap getPrintImg() const;

    //以下是文件保存函数
    void saveToPdf(QPixmap &pixmap, QString fileName);

    //以下是打印文件函数
    bool printImg();
    bool printText(QString &str);

    //以下是预览图像函数
    void printerPreviewImg();


private slots:
    void previewSlot(QPrinter*printer);
private:
    QPrinter m_printer;
    QPixmap m_pixmap;
    qint8 m_xscale=1;
    qint8 m_yscale=1;
    qint8 m_xStartCoordinate=0;
    qint8 m_yStartCoordinate=0;
    QSizeF m_customPageSize;
    MyPageSize m_pagesize=MyPageSize::A4;
};

#endif // MYPRINTER_H
