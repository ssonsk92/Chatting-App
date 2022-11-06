#include "ChattingWindow.h"
#include "StyleManager.h"
#include <qguiapplication.h>
#include <qscreen.h>

namespace ChatApp
{
    ChattingWindow::ChattingWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        QScreen* screen = QGuiApplication::primaryScreen();
        QRect  screenGeometry = screen->geometry();
        int screenWidth = screenGeometry.width();
        int screenHeight = screenGeometry.height();
        Style s = StyleManager::GetInstance()->MainWindow;
        int windowWidth = s.size.width();
        int windowHeight = s.size.height();
        setGeometry(screenWidth / 2 - windowWidth / 2, screenHeight / 2 - windowHeight / 2, windowWidth, windowHeight);
        setStyleSheet(StyleManager::loadQSS(s.qssPath));
        
    }

    ChattingWindow::~ChattingWindow()
    {

    }
}