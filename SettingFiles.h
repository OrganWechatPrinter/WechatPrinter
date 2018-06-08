#ifndef SETTINGFILES_H
#define SETTINGFILES_H

#include <QObject>
#include <QSettings>
#include <QFile>
#include <QMap>
#include <QDebug>
#if defined(Q_OS_WIN)
#include <QApplication>
#define REG_RUN "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#endif

/***************************Class Use Case************************
 * @Define: SettingFiles setting;
 * @Define: SettingFiles *setting; settint->setIniFilePath("./config.ini");
 * @Define: SettingFiles setting("./config.ini");
 * @Operation: addCfgItem("key","value")
 * @Description: 写入键值对
 * @Operation: readCfgItem("key")
 * @Description: 查找key的值
 * @Operation: setIniFilePath("./config.ini")
 * @Description: 设置当前配置文件的保存路径
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 10:30:06
 * @version V1.1.0
 *
 *  SettingFiles set("./config.ini");
    set.addCfgItem("zhangsan","12");
    set.addCfgItem("lisi","34");
    set.addCfgItem("huangsan","32");
    set.saveCfg();
    qDebug()<< set.readCfgItem("zhangsan");
    qDebug()<< set.readCfgItem("huangsan");
    qDebug()<< set.readCfgItem("lisi");
 *
******************************************************************/

/**
 * @Title: SettingFiles
 * @FileName: SettingFiles
 * @Description: 用于读写配置文件
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 10:24:20
 * @update_author
 * @update_time
 * @version V1.0
*/
class SettingFiles : public QObject
{
    Q_OBJECT
public:
    explicit SettingFiles(QObject *parent = nullptr);
    SettingFiles(QString SettingFilePath);

    //setter
    void addCfgItem(const QString &itemName,const QString &itemValue);

    //getter
    QString readCfgItem(QString itemName) const;

    //operation
    void saveCfg();
    void emptyItems();
#if defined(Q_OS_WIN)
    void setAutoStart(bool isAutoStart);
#endif
private:
    QString m_filePath;
    QMap<QString,QString> m_map;
};

#endif // SETTINGFILES_H
