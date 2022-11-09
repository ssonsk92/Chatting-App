#pragma once
#include <QWidget>
#include <QMainWindow>

namespace ChatApp
{
	class TitleBar : public QWidget
	{
		Q_OBJECT

	public:
		TitleBar(QWidget* parent, QMainWindow* mainWindow);
		~TitleBar();
	};
}