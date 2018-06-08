#include "HttpDownloadImg.h"

/**
 * @Title: downloadFileFromURL
 * @Class: HttpDownloadImg
 * @Description: http下载图片
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:43:42
 * @update_author
 * @update_time
 * @version V1.0
 * @param 图片地址 ep:"http://images.rosy.net.cn/4a2f8b7c1b6b09f312cf06cbd8f89f7f.jpg"
 * @param 文件存放路径，ep:"C:/Users/Administrator/Desktop/"
 * @return
*/
void HttpDownloadImg::downloadFileFromURL(const QString &url, const QString &filePath)
{
    if (!m_isReady)
        return;
    m_isReady = false;

    //        QDateTime  time = QDateTime::currentDateTime();
    //        //QString time_str= time.toString("yyyy-MM-dd-hh:mm:ss");
    //        QString time_str= time.toString("MM-dd-hh:mm:ss");

    //        QString fileName = filePath + time_str + url.right(url.size() - url.lastIndexOf("/")-1);
    QString fileName = filePath + url.right(url.size() - url.lastIndexOf("/")-1);
    qDebug() << fileName;
    m_file = new QFile();
    m_file->setFileName(fileName);
    m_file->open(QIODevice::WriteOnly);
    if (!m_file->isOpen()) {
        m_isReady = true;
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QNetworkRequest request;
    request.setUrl(QUrl(url));

    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onDownloadFileCompleteSlot(QNetworkReply *)));

    manager->get(request);
}

void HttpDownloadImg::onDownloadFileCompleteSlot(QNetworkReply *reply)
{
    if (!m_file->isWritable()) {
        m_isReady = true;
        return;
    }
    m_file->write(reply->readAll());
    m_file->close();
    m_isReady = true;
}
