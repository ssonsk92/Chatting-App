#include "TitleBar.h"
#include <QPushButton>
#include <QLayout>
#include "StyleManager.h"
#include <QMouseEvent>
#include <QDebug>

namespace ChatApp
{
	TitleBar::TitleBar(QWidget* parent, QMainWindow* mainWindow)
		: QWidget(parent)
		, m_mainWindow(mainWindow)
		, m_moveStartPos()
	{
		setStyleSheet(StyleManager::loadQSS(":qss/TitleBar.qss"));
		setFixedHeight(24);

		QHBoxLayout* layout = new QHBoxLayout;
		layout->setAlignment(Qt::AlignRight);
		layout->setContentsMargins(0, 8, 8, 0);
		layout->setSpacing(5);

		QPushButton* minimumButton = new QPushButton(this);
		minimumButton->setObjectName("minimum-button");
		
		QPushButton* closeButton = new QPushButton(this);
		closeButton->setObjectName("close-button");
		connect(closeButton, SIGNAL(clicked()), mainWindow, SLOT(close()));

		layout->addWidget(minimumButton);
		layout->addWidget(closeButton);
		
		setLayout(layout);
	}

	TitleBar::~TitleBar()
	{

	}

	void TitleBar::mousePressEvent(QMouseEvent* ev)
	{
		if (ev->buttons() & Qt::LeftButton)
		{
			m_moveStartPos = ev->globalPos();
		}
	}

	void TitleBar::mouseMoveEvent(QMouseEvent* ev)
	{
		if (ev->buttons() & Qt::LeftButton)
		{
			QPoint diff = ev->globalPos() - m_moveStartPos;
			QPoint pos = m_mainWindow->pos();
			pos += diff;
			m_mainWindow->move(pos);
			m_moveStartPos = ev->globalPos();
		}
	}
}
