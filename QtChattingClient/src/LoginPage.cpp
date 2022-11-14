#include "LoginPage.h"

namespace ChatApp
{
    LoginPage::LoginPage(QWidget* parent)
        : QWidget(parent)
        , m_editID(nullptr)
        , m_editPW(nullptr)
        , m_buttonLogin(nullptr)
        , minIDLength(1)
        , minPWLength(4)
    {
        QVBoxLayout* layout = new QVBoxLayout;
        layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        layout->setSpacing(0);
        layout->setContentsMargins(QMargins(60, 0, 60, 0));
        QLabel* labelTalkImage = new QLabel(this);
        labelTalkImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        labelTalkImage->setPixmap(QPixmap(":image/talk.png"));
        m_editID = new QLineEdit(this);
        m_editID->setFixedHeight(40);
        connect(m_editID, SIGNAL(textChanged(const QString&)), this, SLOT(slotChangedID(const QString&)));
        m_editPW = new QLineEdit(this);
        m_editPW->setFixedHeight(40);
        m_editPW->setEchoMode(QLineEdit::Password);
        m_editPW->setPlaceholderText(tr("PASSWORD"));
        connect(m_editPW, SIGNAL(textChanged(const QString&)), this, SLOT(slotChangedPW(const QString&)));
        m_buttonLogin = new QPushButton(tr("LOGIN"), this);
        connect(m_buttonLogin, SIGNAL(clicked()), this, SLOT(slotLoginClicked()));
        m_buttonLogin->setFixedHeight(40);
        m_buttonLogin->setEnabled(false);
        layout->addWidget(labelTalkImage);
        layout->addSpacing(25);
        layout->addWidget(m_editID);
        layout->addWidget(m_editPW);
        layout->addSpacing(5);
        layout->addWidget(m_buttonLogin);
        setLayout(layout);
    }

    LoginPage::~LoginPage()
    {
        
    }

    void LoginPage::slotChangedID(const QString& text)
    {
        enableLoginButton();
    }

    void LoginPage::slotChangedPW(const QString& text)
    {
        enableLoginButton();
    }

    void LoginPage::slotLoginClicked()
    {
        QString id = m_editID->text();
        QString pw = m_editPW->text();

        qDebug() << id << pw;
    }

    void LoginPage::enableLoginButton()
    {
        int lengthID = m_editID->text().length();
        int lengthPW = m_editPW->text().length();

        if (minIDLength <= lengthID && minPWLength <= lengthPW)
            m_buttonLogin->setEnabled(true);
        else
            m_buttonLogin->setEnabled(false);
    }
}
