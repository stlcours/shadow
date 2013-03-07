// =====================================================================================
// 
//       Filename:  tabwidget.cpp
//
//    Description:  标签显示管理
//
//        Version:  1.0
//        Created:  2013年03月07日 14时05分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "tabwidget.h"
#include "filetreeview.h"

TabWidget::TabWidget()
{
	createActions();
	createToolBars();
	createMainWeiget();

	this->setTabPosition(QTabWidget::South);	// 设置标签显示在窗口下端
	this->setDocumentMode(false);				// 设置是否显示边框
	
	this->addTab(fileListWidget, tr("远程文件管理"));
	this->addTab(processWidget, tr("远程进程管理"));
	this->addTab(serverWidget, tr("远程服务管理"));
	this->addTab(portWidget, tr("远程端口管理"));
	this->addTab(linkControlWidget, tr("远程控制命令"));
	this->addTab(cmdWidget, tr("远程cmd控制"));
}

TabWidget::~TabWidget()
{

}

void TabWidget::createActions()
{
	fileListView = new FileTreeView();

	cutAction = new QAction(tr("剪切"), this);
	cutAction->setIcon(QIcon(":/res/images/file_cut.png"));
	cutAction->setStatusTip(tr("剪切选中的文件"));

	copyAction = new QAction(tr("复制"), this);
	copyAction->setIcon(QIcon(":/res/images/file_copy.png"));
	copyAction->setStatusTip(tr("复制选中的文件"));

	pasteAction = new QAction(tr("粘贴"), this);
	pasteAction->setIcon(QIcon(":/res/images/file_paste.png"));
	pasteAction->setStatusTip(tr("粘贴剪贴板中的文件"));

	deleteAction = new QAction(tr("删除"), this);
	deleteAction->setIcon(QIcon(":/res/images/file_delete.png"));
	deleteAction->setStatusTip(tr("删除选中的文件"));

	uploadAction = new QAction(tr("文件上传"), this);
	uploadAction->setIcon(QIcon(":/res/images/file_upload.png"));
	uploadAction->setStatusTip(tr("从本地上传文件到目标当前目录"));

	downloadAction = new QAction(tr("文件下载"), this);
	downloadAction->setIcon(QIcon(":/res/images/file_download.png"));
	downloadAction->setStatusTip(tr("下载选中的文件到本地磁盘"));
}

void TabWidget::createToolBars()
{
	fileToolBar = new QToolBar();
	fileToolBar->setIconSize(QSize(20, 20));
	fileToolBar->addSeparator();
	fileToolBar->addAction(cutAction);
	fileToolBar->addAction(copyAction);
	fileToolBar->addAction(pasteAction);
	fileToolBar->addAction(deleteAction);
	fileToolBar->addSeparator();
	fileToolBar->addAction(uploadAction);
	fileToolBar->addAction(downloadAction);
}

void TabWidget::createMainWeiget()
{
	fileListWidget = new QWidget();
	processWidget = new QWidget();
	serverWidget = new QWidget();
	portWidget = new QWidget();
	linkControlWidget = new QWidget();
	cmdWidget = new QWidget();

	cmdTextEdit = new QTextEdit();
	cmdTextEdit->setReadOnly(true);
	cmdLabel = new QLabel(tr("命令输入"));
	cmdInputEdit = new QLineEdit();
	sendButton = new QPushButton(tr("远程执行"));

	fileListLayout = new QVBoxLayout();
	buttomCmdLayout = new QHBoxLayout();
	cmdLayout = new QVBoxLayout();

	fileListLayout->addWidget(fileToolBar);
	fileListLayout->addWidget(fileListView);

	fileListWidget->setLayout(fileListLayout);

	buttomCmdLayout->addWidget(cmdLabel);
	buttomCmdLayout->addWidget(cmdInputEdit);
	buttomCmdLayout->addWidget(sendButton);

	cmdLayout->addWidget(cmdTextEdit);
	cmdLayout->addLayout(buttomCmdLayout);

	cmdWidget->setLayout(cmdLayout);
}