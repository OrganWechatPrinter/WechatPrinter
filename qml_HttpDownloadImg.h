#include "HttpDownloadImg.h"

class QML_HttpDownloadImg : public QObject
{
	Q_OBJECT
public:
    QML_HttpDownloadImg(QObject *parent = 0);
	~QML_HttpDownloadImg();
	
	Q_INVOKABLE void QML_downloadFileFromURL(const QString &url, const QString &filePath);
	
private:
    HttpDownloadImg *hdImg = NULL;
}