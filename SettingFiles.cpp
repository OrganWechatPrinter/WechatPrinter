#include "SettingFiles.h"

SettingFiles::SettingFiles(QObject *parent) : QObject(parent)
{

}


/**
 * @Title: SettingFiles
 * @Class: SettingFiles
 * @Description: 构造函数，需要提供文件路径才可以正常使用
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:42:11
 * @update_author
 * @update_time
 * @version V1.0
 * @param 文件路径
 * @return
*/
SettingFiles::SettingFiles(QString SettingFilePath)
{
    m_filePath = SettingFilePath;
}

/**
 * @Title: addCfgItem
 * @Class: SettingFiles
 * @Description: 添加待写入的配置项
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:35:58
 * @update_author
 * @update_time
 * @version V1.0
 * @param 项名字
 * @param 项值
 * @return
*/
void SettingFiles::addCfgItem(const QString &itemName, const QString &itemValue)
{
    m_map.insert(itemName,itemValue);
}

/**
 * @Title: readCfgItem
 * @Class: SettingFiles
 * @Description: 根据项名字读取配置文件
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:36:57
 * @update_author
 * @update_time
 * @version V1.0
 * @param 项名字
 * @return 项值
*/
QString SettingFiles::readCfgItem(QString itemName) const
{
    QSettings *cfgIO = new QSettings(m_filePath,QSettings::IniFormat);
    QString key="/Configure/"+itemName;
    QString value = cfgIO->value(key).toString();
    delete cfgIO;
    return value;
}

/**
 * @Title: saveCfg
 * @Class: SettingFiles
 * @Description: 保存当前缓存中所有的配置项
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:37:44
 * @update_author
 * @update_time
 * @version V1.0
 * @return
*/
void SettingFiles::saveCfg()
{
    QSettings *cfgIO = new QSettings(m_filePath,QSettings::IniFormat);
    QMap<QString,QString>::ConstIterator itr=m_map.constBegin();
    for(;itr!=m_map.end();itr++)
    {
        cfgIO->setValue("/Configure/"+itr.key(),itr.value());
        //qDebug()<<"key:"<<itr.key()<<" value:"<<itr.value();
    }
    delete cfgIO;
}

/**
 * @Title: emptyItems
 * @Class: SettingFiles
 * @Description: 删除当前缓冲区所有的配置项
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 11:39:51
 * @update_author
 * @update_time
 * @version V1.0
 * @return
*/
void SettingFiles::emptyItems()
{
    m_map.clear();
}
#if defined(Q_OS_WIN)
/**
 * @Title: setAutoStart
 * @Class: SettingFiles
 * @Description: 设置程序是否开机自动启动
 * @author ZhangHao kinderzhang@foxmail.com
 * @date 2018-06-07 14:19:17
 * @update_author
 * @update_time
 * @version V1.0
 * @param
 * @param
 * @return
*/
void SettingFiles::setAutoStart(bool isAutoStart)
{
    QString applicationName = QApplication::applicationName();
    QSettings *settings = new QSettings(REG_RUN, QSettings::NativeFormat);
    if(isAutoStart)
    {
        QString applicationPath = QApplication::applicationFilePath();
        settings->setValue(applicationName, applicationPath.replace("/", "\\"));
    }
    else
    {
        settings->remove(applicationName);
    }
    delete settings;
}
#endif
