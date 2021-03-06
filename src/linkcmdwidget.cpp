// =====================================================================================
// 
//       Filename:  LinkCmdWidget.cpp
//
//    Description:  cmd 管理标签 Widget
//
//        Version:  1.0
//        Created:  2013年03月11日 09时34分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "LinkCmdWidget.h"

LinkCmdWidget::LinkCmdWidget()
{
	createMainWeiget();
}

LinkCmdWidget::~LinkCmdWidget()
{

}

void LinkCmdWidget::createMainWeiget()
{
	cmdTextEdit = new QTextEdit();
	cmdTextEdit->setReadOnly(true);
	cmdLabel = new QLabel(tr("命令输入"));
	cmdInputEdit = new QLineEdit();
	sendButton = new QPushButton(tr("远程执行"));

	cmdLayout = new QVBoxLayout();
	cmdButtonLayout = new QHBoxLayout();

	cmdButtonLayout->addWidget(cmdLabel);
	cmdButtonLayout->addWidget(cmdInputEdit);
	cmdButtonLayout->addWidget(sendButton);

	cmdLayout->addWidget(cmdTextEdit);
	cmdLayout->addLayout(cmdButtonLayout);

	setLayout(cmdLayout);
}
