#include "MyPrinter.h"

MyPrinter::MyPrinter(QObject *parent) : QObject(parent)
{

}

/**
 * @Title: setXscale
 * @Class: MyPrinter
 * @Description: 设置横向压缩比率
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 10:57:25
 * @update_author
 * @update_time
 * @version V1.0
 * @param 横向压缩比
 * @return
*/
void MyPrinter::setXscale(qint8 scale)
{
    if(scale!=m_xscale)
    {
        m_xscale=scale;
    }
}

/**
 * @Title: setYscale
 * @Class: MyPrinter
 * @Description: 设置纵向压缩比率
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 10:58:39
 * @update_author
 * @update_time
 * @version V1.0
 * @param 纵向压缩比
 * @return
*/
void MyPrinter::setYscale(qint8 scale)
{
    if(scale!=m_yscale)
    {
        m_yscale=scale;
    }
}

/**
 * @Title: setXcoordinate
 * @Class: MyPrinter
 * @Description: 设置横向打印起始位置
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 10:59:36
 * @update_author
 * @update_time
 * @version V1.0
 * @param 横向打印起始位置
 * @return
*/
void MyPrinter::setXcoordinate(qint8 startCoordinate)
{
    if(startCoordinate!=m_xStartCoordinate)
    {
        m_xStartCoordinate=startCoordinate;
    }
}

/**
 * @Title: setYcoordinate
 * @Class: MyPrinter
 * @Description: 设置纵向打印起始位置
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 11:00:32
 * @update_author
 * @update_time
 * @version V1.0
 * @param 纵向打印起始位置
 * @return
*/
void MyPrinter::setYcoordinate(qint8 startCoordinate)
{
    if(startCoordinate!=m_yStartCoordinate)
    {
        m_yStartCoordinate=startCoordinate;
    }
}

/**
 * @Title: setPrinterPageSize
 * @Class: MyPrinter
 * @Description: 设置打印纸张的大小
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:25:59
 * @update_author
 * @update_time
 * @version V1.0
 * @param 纸张打印大小
 * @return
*/
void MyPrinter::setPrinterPageSize(MyPrinter::MyPageSize size)
{
    if(size!=m_pagesize)
    {
        m_pagesize = size;
    }
}

/**
 * @Title: setPrinterDriverName
 * @Class: MyPrinter
 * @Description: 设置打印机驱动
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 15:03:09
 * @update_author
 * @update_time
 * @version V1.0
 * @param 打印机驱动名字
 * @return
*/
void MyPrinter::setPrinterDriverName(QString driverName)
{
    m_printer.setPrinterName(driverName);
}

/**
 * @Title: setPageSize
 * @Class: MyPrinter
 * @Description: 设置当前纸张的大小
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 15:30:05
 * @update_author
 * @update_time
 * @version V1.0
 * @param 纸张大小
 * @return
*/
void MyPrinter::setPageSize(QSizeF size)
{
    m_printer.setPageSize(QPrinter::Custom);
    m_printer.setPageSizeMM(size);
}

/**
 * @Title: setPrintImg
 * @Class: MyPrinter
 * @Description: 设置打印位图
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 23:06:37
 * @update_author
 * @update_time
 * @version V1.0
 * @param 打印位图数据
 * @return
*/
void MyPrinter::setPrintImg(const QPixmap &pixmap)
{
    if(pixmap!=m_pixmap)
    {
        m_pixmap = pixmap;
    }
}

/**
 * @Title: getXscale
 * @Class: MyPrinter
 * @Description: 获取横向缩放比
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:15:42
 * @update_author
 * @update_time
 * @version V1.0
 * @return 横向缩放比
*/
qint8 MyPrinter::getXscale()
{
    return m_xscale;
}

/**
 * @Title: getYscale
 * @Class: MyPrinter
 * @Description: 获取纵向缩放比
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:16:24
 * @update_author
 * @update_time
 * @version V1.0
 * @return 纵向缩放比
*/
qint8 MyPrinter::getYscale()
{
    return m_yscale;
}

/**
 * @Title: setXcoordinate
 * @Class: MyPrinter
 * @Description: 获取横向起始打印坐标
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:16:56
 * @update_author
 * @update_time
 * @version V1.0
 * @return 横向起始打印坐标
*/
qint8 MyPrinter::getXcoordinate()
{
    return m_xStartCoordinate;
}

/**
 * @Title: setYcoordinate
 * @Class: MyPrinter
 * @Description: 获取纵向起始打印坐标
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:18:17
 * @update_author
 * @update_time
 * @version V1.0
 * @return 纵向起始打印坐标
*/
qint8 MyPrinter::getYcoordinate()
{
    return m_yStartCoordinate;
}

/**
 * @Title: getPrinterPageSize
 * @Class: MyPrinter
 * @Description: TODO
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 13:27:48
 * @update_author
 * @update_time
 * @version V1.0
 * @return 返回纸张打印大小
*/
MyPrinter::MyPageSize MyPrinter::getPrinterPageSize()
{
    return m_pagesize;
}

/**
 * @Title: getPrinterDevice
 * @Class: MyPrinter
 * @Description: 获取当前系统中的打印机列表
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 15:28:22
 * @update_author
 * @update_time
 * @version V1.0
 * @return 打印机列表
*/
QStringList MyPrinter::getPrinterDevice()
{
    QStringList list = QPrinterInfo::availablePrinterNames();
    return list;
}

/**
 * @Title: getPageSize
 * @Class: MyPrinter
 * @Description: 获取当前打印纸张的大小
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 15:29:06
 * @update_author
 * @update_time
 * @version V1.0
 * @return 打印纸张的大小
*/
QSizeF MyPrinter::getPageSize()
{
    return m_customPageSize;
}

/**
 * @Title: getPrintImg
 * @Class: MyPrinter
 * @Description: 返回打印位图
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 23:04:39
 * @update_author
 * @update_time
 * @version V1.0
 * @return 返回打印位图
*/
QPixmap MyPrinter::getPrintImg() const
{
    return m_pixmap;
}

/**
 * @Title: saveToPdf
 * @Class: MyPrinter
 * @Description: 将图片保存为pdf文件
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-06 16:52:14
 * @update_author
 * @update_time
 * @version V1.0
 * @param 图片文件
 * @return
*/
void MyPrinter::saveToPdf(QPixmap &pixmap,QString fileName)
{

    if (!fileName.isEmpty())
    {
        // 如果文件后缀为空，则默认使用.pdf
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printerPixmap(QPrinter::HighResolution);
        //自定义纸张大小，这里要打印的内容都在stackedWidget上
        printerPixmap.setPageSize(QPrinter::Custom);
        printerPixmap.setPaperSize(m_customPageSize, QPrinter::Point);
        //设置纸张大小为A4，这里注释掉了，建议自定义纸张 ，否则保存的就会有很多空白
        //printerPixmap.setPageSize(QPrinter::A4);
        //纵向打印
        printerPixmap.setOrientation(QPrinter::Portrait);
        //设置输出格式为pdf
        printerPixmap.setOutputFormat(QPrinter::PdfFormat);
        //设置输出路径
        printerPixmap.setOutputFileName(fileName);

        QPainter painterPixmap;
        painterPixmap.begin(&printerPixmap);
        QRect rect = painterPixmap.viewport();
        int x = rect.width() / pixmap.width();
        int y = rect.height() / pixmap.height();
        //将图像(所有要画的东西)在pdf上按比例尺缩放,如果想展示原始图，就讲x和y设置为1就可以了
        painterPixmap.scale(x, y);
        //画图
        painterPixmap.drawPixmap(0, 0, pixmap);
        painterPixmap.end();
    }
}

bool MyPrinter::printImg()
{
    //pixmap = QPixmap::grabWidget(ui->lab_img, ui->lab_img->rect());  //获取界面的图片
    m_printer.setOrientation(QPrinter::Portrait);//纵向：Portrait 横向：Landscape
    //m_printer.setPageSize(QPrinter::A4);//设置纸张大小
    QPainter painterPixmap;
    painterPixmap.begin(&m_printer);
    painterPixmap.scale(m_xscale, m_yscale);//设置图像长宽是原图的多少倍
    painterPixmap.drawPixmap(m_xStartCoordinate, m_yStartCoordinate , m_pixmap);//设置图像在纸张中的开始坐标
    painterPixmap.end();
    return true;
}

bool MyPrinter::printText(QString &str)
{

    return true;
}

void MyPrinter::printerPreviewImg()
{
    QPrintPreviewDialog preview(&m_printer);
    preview.setMinimumSize(1000,600);
    connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(previewSlot(QPrinter*)));
    preview.exec ();
}

void MyPrinter::previewSlot(QPrinter *printer)
{
    QPainter painterPixmap;
    painterPixmap.begin(printer);
    QRect rect = painterPixmap.viewport();
    int x = rect.width() / m_pixmap.width();
    int y = rect.height() / m_pixmap.height();
    painterPixmap.scale(x, y);
    painterPixmap.drawPixmap(0, 0, m_pixmap);
    painterPixmap.end();
}
