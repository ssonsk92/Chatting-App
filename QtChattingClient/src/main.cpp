#include "ChattingWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChattingWindow w;
    w.show();
    return a.exec();
}
