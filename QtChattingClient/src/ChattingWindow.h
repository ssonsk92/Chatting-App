#pragma once

#include <QtWidgets/QMainWindow>

class ChattingWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChattingWindow(QWidget *parent = nullptr);
    ~ChattingWindow();
};
