#include "ChattingWindow.h"
#include "StyleManager.h"
#include <QGuiApplication>
#include <QScreen>
#include "LoginPage.h"
#include "TitleBar.h"

namespace ChatApp
{
    ChattingWindow::ChattingWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
        QScreen* screen = QGuiApplication::primaryScreen();
        QRect  screenGeometry = screen->geometry();
        int screenWidth = screenGeometry.width();
        int screenHeight = screenGeometry.height();
        Style s = StyleManager::GetInstance()->MainWindow;
        int windowWidth = s.size.width();
        int windowHeight = s.size.height();
        setGeometry(screenWidth / 2 - windowWidth / 2, screenHeight / 2 - windowHeight / 2, windowWidth, windowHeight);
        setStyleSheet(StyleManager::loadQSS(s.qssPath));
        
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *centralLayout = new QVBoxLayout;
        centralLayout->setSpacing(0);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        TitleBar* titleBar = new TitleBar(centralWidget, this);
        centralLayout->addWidget(titleBar);
        LoginPage *loginPage = new LoginPage(centralWidget);
        centralLayout->addWidget(loginPage);
        centralWidget->setLayout(centralLayout);
        setCentralWidget(centralWidget);
    }

    ChattingWindow::~ChattingWindow()
    {

    }
}