#include "ChattingWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatApp::ChattingWindow w;
    w.show();
    return a.exec();
}
