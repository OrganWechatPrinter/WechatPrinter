#include "QML_HttpDownloadImg.h"

QML_HttpDownloadImg::QML_HttpDownloadImg(QObject *parent = 0)
{
	qDebug() << "[QML] HttpDownloadImg";
	hdImg = new HttpDownloadImg(this);
}

QML_HttpDownloadImg::~QML_HttpDownloadImg() 
{
	qDebug() << "[QML] ~HttpDownloadImg";
	if (hdImg != NULL){
		delete hdImg;
		hdImg = NULL;
	}
}
	
void QML_HttpDownloadImg::QML_downloadFileFromURL(const QString &url, const QString &filePath)
{
	qDebug() << "[QML] downloadFileFromURL";
	hdImg.downloadFileFromURL(url, filePath);
}
	