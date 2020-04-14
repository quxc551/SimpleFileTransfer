#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include <qthread.h>
#include <QList>
#include <qfiledialog.h>
#include "md5.h"
using namespace std;

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
	~QtGuiApplication1();
	void CloseWindows();
private:
	QStringList getFiles(QString path, QString attachPath = ".");
	Ui::QtGuiApplication1Class ui;
	QThread receiveFiles;
	QThread sendFiles;
public slots:
	void StopReceiving();
	void showFileList();
	void ShowSendingMsg(unsigned short id,QString msg);
	void ShowRecvingMsg(QString filePath);
	void SendFiles();
	void ShowRecvingMsgById(unsigned short id, QString msg);
	void selectRecvFloder();
	void clearRecvTable();
signals:
	void BeginSending(QString basepath, QStringList filename);
	void updateRecvFloder(QString floder);
};
