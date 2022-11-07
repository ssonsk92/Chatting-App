#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>

namespace ChatApp
{
	class LoginPage : public QWidget
	{
		Q_OBJECT
	public:
		LoginPage(QWidget* parent);
		~LoginPage();
	};
}

