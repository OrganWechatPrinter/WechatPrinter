#include "MyPrinter.h"
#include <qDebug>

class QML_MyPrinter : public QObject
{
    Q_OBJECT
	Q_ENUMS(QML_MyPageSize)
	//scale
	Q_PROPERTY(qint8 QML_getXscale READ QML_getXscale WRITE QML_setXscale)
    Q_PROPERTY(qint8 QML_getYscale READ QML_getYscale WRITE QML_setYscale) 
    //coordinate
    Q_PROPERTY(qint8 QML_getXcoordinate READ QML_getXcoordinate WRITE QML_setXcoordinate)
    Q_PROPERTY(qint8 QML_getYcoordinate READ QML_getYcoordinate WRITE QML_setYcoordinate)	
	//PrinterPageSize
	Q_PROPERTY(QML_MyPageSize QML_getPrinterPageSize READ QML_getPrinterPageSize WRITE QML_setPrinterPageSize)
    //PrinterDevice
	Q_PROPERTY(QStringList QML_getPrinterDevice READ QML_getPrinterDevice WRITE QML_setPrinterDriverName)	
	//PageSize
	Q_PROPERTY(QSizeF QML_getPageSize READ QML_getPageSize WRITE QML_setPageSize)	
	//PrintImg
	Q_PROPERTY(QPixmap QML_getPrintImg() READ QML_getPrintImg WRITE QML_setPrintImg)
	
public:
    QML_MyPrinter(QObject *parent = 0);
	~QML_MyPrinter();

    //纸张打印大小定义,QML调用
    enum QML_MyPageSize {
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
	
	//以下是文件保存为PDF函数
    Q_INVOKABLE void QML_saveToPdf(QPixmap &pixmap, QString fileName);
    //以下是打印文件函数
    Q_INVOKABLE bool QML_printImg();
    Q_INVOKABLE bool QML_printText(QString &str);
    //以下是预览图像函数
    Q_INVOKABLE void QML_printerPreviewImg();
	
	/* get set 方法 */
	//以下是打印机的相关属性设置
    void QML_setXscale(qint8 scale);
    void QML_setYscale(qint8 scale);
    void QML_setXcoordinate(qint8 startCoordinate);
    void QML_setYcoordinate(qint8 startCoordinate);
    void QML_setPrinterPageSize(QML_MyPageSize size);
    void QML_setPrinterDriverName(QString driverName);
    void QML_setPageSize(QSizeF size);
    void QML_setPrintImg(const QPixmap &pixmap);

    //以下是获取打印机的相关属性
    qint8 QML_getXscale();
    qint8 QML_getYscale();
    qint8 QML_getXcoordinate();
    qint8 QML_getYcoordinate();
    QML_MyPageSize QML_getPrinterPageSize();
    QStringList QML_getPrinterDevice();
    QSizeF QML_getPageSize();
    QPixmap QML_getPrintImg() const;
	
private:
	MyPrinter *myPrinter = NULL;
}