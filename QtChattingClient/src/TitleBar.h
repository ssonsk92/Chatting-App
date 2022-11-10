#pragma once
#include <QWidget>
#include <QMainWindow>
#include <QPoint>

namespace ChatApp
{
	class TitleBar : public QWidget
	{
		Q_OBJECT

	public:
		TitleBar(QWidget* parent, QMainWindow* mainWindow);
		~TitleBar();

	protected:
		void mousePressEvent(QMouseEvent* ev) override;
		void mouseMoveEvent(QMouseEvent* ev) override;

	private:
		QMainWindow* m_mainWindow;
		QPoint m_moveStartPos;
	};
}