#include "QML_MyPrinter.h"


QML_MyPrinter::QML_MyPrinter(QObject *parent = 0)
{
	qDebug() << "[QML] QML_MyPrinter";
	myPrinter = new MyPrinter(this);
}
QML_MyPrinter::~QML_MyPrinter()
{
	qDebug() << "[QML] ~QML_MyPrinter";
	if (myPrinter != NULL){
		delete myPrinter;
		myPrinter = NULL;
	}
}
	
//保存为pdf
void QML_MyPrinter::QML_saveToPdf(QPixmap &pixmap, QString fileName)
{
	qDebug() << "[QML] QML_saveToPdf";
	myPrinter.saveToPdf(pixmap, fileName);
}

//以下是打印文件函数
bool QML_MyPrinter::QML_printImg()
{
	qDebug() << "[QML] QML_printImg";
	myPrinter.printImg();
}

bool QML_MyPrinter::QML_printText(QString &str)
{
	qDebug() << "[QML] QML_printText";
	myPrinter.printText(str);
}
    //以下是预览图像函数
void QML_MyPrinter::QML_printerPreviewImg()
{
	qDebug() << "[QML] QML_printerPreviewImg";
	myPrinter.printerPreviewImg();
}
	
/* get set 方法 */
//以下是打印机的相关属性设置
void QML_MyPrinter::QML_setXscale(qint8 scale)
{
	qDebug() << "[QML] QML_setXscale";
	myPrinter.setXscale(scale);
}

void QML_MyPrinter::QML_setYscale(qint8 scale)
{
	qDebug() << "[QML] QML_setYscale";
	myPrinter.setYscale(scale);
}

void QML_MyPrinter::QML_setXcoordinate(qint8 startCoordinate)
{
	qDebug() << "[QML] QML_setXcoordinate";
	myPrinter.setXcoordinate(startCoordinate);
}

void QML_MyPrinter::QML_setYcoordinate(qint8 startCoordinate)
{
	qDebug() << "[QML] QML_setYcoordinate";
	myPrinter.setYcoordinate(startCoordinate);
}

void QML_MyPrinter::QML_setPrinterPageSize(QML_MyPageSize size)
{
	qDebug() << "[QML] QML_setPrinterPageSize";
	myPrinter.setPrinterPageSize(size);
}

void QML_MyPrinter::QML_setPrinterDriverName(QString driverName)
{
	qDebug() << "[QML] QML_setPrinterDriverName";
	myPrinter.setPrinterDriverName(driverName);
}

void QML_MyPrinter::QML_setPageSize(QSizeF size)
{
	qDebug() << "[QML] QML_setPageSize";
	myPrinter.setPageSize(size);
}

void QML_MyPrinter::QML_setPrintImg(const QPixmap &pixmap)
{
	qDebug() << "[QML] QML_setPrintImg";
	myPrinter.setPrintImg(pixmap);
}

//以下是获取打印机的相关属性
qint8 QML_MyPrinter::QML_getXscale()
{
	qDebug() << "[QML] QML_getXscale";
	myPrinter.getXscale();
	
}

qint8 QML_MyPrinter::QML_getYscale()
{
	qDebug() << "[QML] QML_getYscale";
	myPrinter.getYscale();
	
}

qint8 QML_MyPrinter::QML_getXcoordinate()
{
	qDebug() << "[QML] QML_getXcoordinate";
	myPrinter.getXcoordinate();
}

qint8 QML_MyPrinter::QML_getYcoordinate()
{
	qDebug() << "[QML] QML_getYcoordinate";
	myPrinter.getYcoordinate();
}

QML_MyPageSize QML_MyPrinter::QML_getPrinterPageSize()
{
	qDebug() << "[QML] QML_getPrinterPageSize";
	myPrinter.getPrinterPageSize();
}

QStringList QML_MyPrinter::QML_getPrinterDevice()
{
	qDebug() << "[QML] QML_getPrinterDevice";
	myPrinter.getPrinterDevice();
}

QSizeF QML_MyPrinter::QML_getPageSize()
{
	qDebug() << "[QML] QML_getPageSize";
	myPrinter.getPageSize();
}

QPixmap QML_MyPrinter::QML_getPrintImg() const
{
	qDebug() << "[QML] QML_getPrintImg";
	myPrinter.getPrintImg();
}
	
	
	
	