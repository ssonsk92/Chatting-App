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

	public slots:
		void slotChangedID(const QString& text);
		void slotChangedPW(const QString& text);
		void slotLoginClicked();

	private:
		void enableLoginButton();

	private:
		QLineEdit* m_editID;
		QLineEdit* m_editPW;
		QPushButton* m_buttonLogin;

		const int minIDLength;
		const int minPWLength;
	};
}

