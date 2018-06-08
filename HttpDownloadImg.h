#ifndef HTTPDOWNLOADIMG_H
#define HTTPDOWNLOADIMG_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QEventLoop>
#include <QUrl>
#include <QDateTime>
/*********************************************************
 * 下载文件使用教程
 * #include <HttpDownloadImg.h>
 * HttpDownloadImg downlower;
 * downlower.downloadFileFromURL("http://images.rosy.net.cn/4a2f8b7c1b6b09f312cf06cbd8f89f7f.jpg",
                                    "C:/Users/Administrator/Desktop/");
*********************************************************/

class HttpDownloadImg : public QObject {
    Q_OBJECT

public:
    explicit HttpDownloadImg(QObject *parent = 0) : QObject(parent) {m_isReady = true;}
    virtual ~HttpDownloadImg() {}

    void downloadFileFromURL(const QString &url, const QString &filePath);

private slots:
    void onDownloadFileCompleteSlot(QNetworkReply *reply);

private:
    QFile *m_file;
    bool m_isReady;
};

#endif // HTTPDOWNLOADIMG_H
