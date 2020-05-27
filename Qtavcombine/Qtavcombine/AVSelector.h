#pragma once
class AVSelector
{
public:
	AVSelector(QMainWindow* wnd);
	void setMode(QFileDialog::FileMode mode);
	void setMediaType(int type);
	QString execute();
	void setFilter(QString str);
private:
	QFileDialog m_dlg;
};

