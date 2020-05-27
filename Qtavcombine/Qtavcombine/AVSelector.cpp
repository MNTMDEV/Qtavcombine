#include "pch.h"
#include "AVSelector.h"
#include "media.h"

AVSelector::AVSelector(QMainWindow* wnd)
{
    m_dlg.setDirectory(".");
    m_dlg.setViewMode(QFileDialog::Detail);
    m_dlg.setParent(wnd);
}

void AVSelector::setMode(QFileDialog::FileMode mode)
{
    m_dlg.setFileMode(mode);
    if (mode == QFileDialog::FileMode::ExistingFile) {
        m_dlg.setWindowTitle(QString::fromLocal8Bit("��"));
    }
    else if (mode == QFileDialog::FileMode::AnyFile) {
        m_dlg.setWindowTitle(QString::fromLocal8Bit("����"));
    }
}

void AVSelector::setMediaType(int type)
{
    if (type == TYPE_AUDIO) {
        m_dlg.setNameFilter(QString::fromLocal8Bit("��Ƶ�ļ�(*.mp3,*.mp4)\r\n�����ļ�(*.*)"));
    }
    else if (type == TYPE_VIDEO) {
        m_dlg.setNameFilter(QString::fromLocal8Bit("��Ƶ�ļ�(*.mp4,*.avi,*.flv)\r\n�����ļ�(*.*)"));
    }
}

QString AVSelector::execute()
{
    QStringList fileNames;
    if (m_dlg.exec())
    {
        fileNames = m_dlg.selectedFiles();
    }
    if (fileNames.length() == 0) {
        return QString();
    }
    else {
        return fileNames[0].replace("/","\\");
    }
}

void AVSelector::setFilter(QString str)
{
    m_dlg.setNameFilter(str);
}
