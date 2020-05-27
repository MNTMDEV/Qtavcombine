#pragma once

#include "ui_Qtavcombine.h"

class Qtavcombine : public QMainWindow
{
    Q_OBJECT

public:
    Qtavcombine(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtavcombineClass ui;
private slots:
    void on_audio_click();
    void on_video_click();
    void on_confirm_click();
    void on_quit_click();
};
