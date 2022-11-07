#include "LoginPage.h"

namespace ChatApp
{
	LoginPage::LoginPage(QWidget* parent)
        : QWidget(parent)
	{
        QVBoxLayout* layout = new QVBoxLayout;
        layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        layout->setSpacing(0);
        layout->setContentsMargins(QMargins(60, 0, 60, 0));
        QLabel* labelTalkImage = new QLabel(this);
        labelTalkImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        labelTalkImage->setPixmap(QPixmap(":/image/talk.png"));
        QLineEdit* editID = new QLineEdit(this);
        editID->setFixedHeight(40);
        QLineEdit* editPW = new QLineEdit(this);
        editPW->setFixedHeight(40);
        editPW->setEchoMode(QLineEdit::Password);
        editPW->setPlaceholderText(tr("PASSWORD"));
        QPushButton* buttonLogin = new QPushButton(tr("LOGIN"), this);
        buttonLogin->setFixedHeight(40);
        layout->addWidget(labelTalkImage);
        layout->addSpacing(25);
        layout->addWidget(editID);
        layout->addWidget(editPW);
        layout->addSpacing(5);
        layout->addWidget(buttonLogin);
        setLayout(layout);
	}

	LoginPage::~LoginPage()
	{

	}
}
