// =====================================================================================
// 
//       Filename:  FileTreeView.cpp
//
//    Description:  文件浏览显示
//
//        Version:  1.0
//        Created:  2013年03月06日 11时12分01秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "FileTreeView.h"

FileTreeView::FileTreeView()
{
	fileModel = new QFileSystemModel();
	fileModel->setRootPath("");

	this->setModel(fileModel);
	this->setAnimated(false);
	this->setIndentation(20);
}

FileTreeView::~FileTreeView()
{

}
