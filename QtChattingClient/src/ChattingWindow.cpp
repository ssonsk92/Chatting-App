#include "ChattingWindow.h"
#include "StyleManager.h"
#include <QGuiApplication>
#include <QScreen>
#include "LoginPage.h"

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

        LoginPage* loginPage = new LoginPage(this);
        setCentralWidget(loginPage);
    }

    ChattingWindow::~ChattingWindow()
    {

    }
}