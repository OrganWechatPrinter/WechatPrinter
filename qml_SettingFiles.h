#include "SettingFiles.h"
#include <qDebug>

class QML_SettingFiles : public QObject
{
    Q_OBJECT
public:
    QML_SettingFiles(QObject *parent = 0);
    QML_SettingFiles(QString SettingFilePath);
	~QML_SettingFiles();

    //setter
     Q_INVOKABLE void QML_addCfgItem(const QString &itemName,const QString &itemValue);

    //getter
     Q_INVOKABLE QString QML_readCfgItem(QString itemName) const;

    //operation
     Q_INVOKABLE void QML_saveCfg();
     Q_INVOKABLE void QML_emptyItems();
#if defined(Q_OS_WIN)
     Q_INVOKABLE void QML_setAutoStart(bool isAutoStart);
#endif
private:
    SettingFiles *stFiles = NULL;
};