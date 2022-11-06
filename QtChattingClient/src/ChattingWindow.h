#pragma once

#include <QtWidgets/QMainWindow>

namespace ChatApp
{
    class ChattingWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        ChattingWindow(QWidget* parent = nullptr);
        ~ChattingWindow();
    };
}

