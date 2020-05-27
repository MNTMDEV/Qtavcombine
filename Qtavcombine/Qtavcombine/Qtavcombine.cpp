#include "pch.h"
#include "Qtavcombine.h"
#include"AVSelector.h"
#include"media.h"

Qtavcombine::Qtavcombine(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void Qtavcombine::on_audio_click() {
    AVSelector sel(this);
    sel.setMediaType(TYPE_AUDIO);
    sel.setMode(QFileDialog::FileMode::ExistingFile);
    QString text = sel.execute();
    if (text != "")
        ui.txAudio->setText(text);
}

void Qtavcombine::on_video_click()
{
    AVSelector sel(this);
    sel.setMediaType(TYPE_VIDEO);
    sel.setMode(QFileDialog::FileMode::ExistingFile);
    QString text = sel.execute();
    if (text != "")
        ui.txVideo->setText(text);
}

void Qtavcombine::on_confirm_click()
{
    AVSelector sel(this);
    sel.setMediaType(TYPE_VIDEO);
    sel.setMode(QFileDialog::FileMode::AnyFile);
    QByteArray audio = ui.txAudio->text().toLocal8Bit();
    QByteArray video = ui.txVideo->text().toLocal8Bit();
    QString text = sel.execute();
    if (text != "") {
        //执行保存
        AVCom com;
        QByteArray out = text.toLocal8Bit();
        com.setAudio(audio);
        com.setVideo(video);
        com.setOutPath(out);
        if (com.OpenStream()) {
            if (com.WriteFile()) {
                QMessageBox::information(this, APP_TITLE, QString::fromLocal8Bit("文件写入成功"), QMessageBox::Yes, QMessageBox::Yes);
            }
            else {
                QMessageBox::critical(this, APP_TITLE, QString::fromLocal8Bit("文件写入失败"), QMessageBox::Yes, QMessageBox::Yes);
            }
        }
        else {
            QMessageBox::critical(this, APP_TITLE, QString::fromLocal8Bit("输入文件不合法或打开失败"), QMessageBox::Yes, QMessageBox::Yes);
        }
    }
}

void Qtavcombine::on_quit_click() {
    this->close();
}