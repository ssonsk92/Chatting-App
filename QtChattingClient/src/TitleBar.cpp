#include "TitleBar.h"
#include <QPushButton>
#include <QLayout>
#include "StyleManager.h"

namespace ChatApp
{
	TitleBar::TitleBar(QWidget* parent, QMainWindow* mainWindow)
		: QWidget(parent)
	{
		setFixedHeight(24);
		QHBoxLayout* layout = new QHBoxLayout;
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setSpacing(0);

		Style s = StyleManager::GetInstance()->PushButton;
		int buttonWidth = s.size.width();
		int buttonHeight = s.size.height();

		QPushButton* minimumButton = new QPushButton(QIcon(":image/minimum.png"), "", this);
		minimumButton->setFixedSize(buttonWidth, buttonHeight);
		minimumButton->setStyleSheet(StyleManager::loadQSS(s.qssPath));
		layout->addWidget(minimumButton);
		QPushButton *closeButton = new QPushButton(QIcon(":image/close.png"), "", this);
		closeButton->setFixedSize(buttonWidth, buttonHeight);
		closeButton->setStyleSheet(StyleManager::loadQSS(s.qssPath));
		connect(closeButton, SIGNAL(clicked()), mainWindow, SLOT(close()));
		layout->addWidget(closeButton);
		setLayout(layout);
	}

	TitleBar::~TitleBar()
	{

	}
}
