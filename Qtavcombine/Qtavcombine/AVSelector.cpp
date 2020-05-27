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
        m_dlg.setWindowTitle(QString::fromLocal8Bit("打开"));
    }
    else if (mode == QFileDialog::FileMode::AnyFile) {
        m_dlg.setWindowTitle(QString::fromLocal8Bit("保存"));
    }
}

void AVSelector::setMediaType(int type)
{
    if (type == TYPE_AUDIO) {
        m_dlg.setNameFilter(QString::fromLocal8Bit("音频文件(*.mp3,*.mp4)\r\n所有文件(*.*)"));
    }
    else if (type == TYPE_VIDEO) {
        m_dlg.setNameFilter(QString::fromLocal8Bit("视频文件(*.mp4,*.avi,*.flv)\r\n所有文件(*.*)"));
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
