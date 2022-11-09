#include "StyleManager.h"
#include <qfile.h>

namespace ChatApp
{
    StyleManager* StyleManager::GetInstance()
    {
        static StyleManager manager;
        return &manager;
    }

    QString StyleManager::loadQSS(const QString& path)
    {
        QFile styleFile(path);
        bool result = styleFile.open(QFile::ReadOnly);
        if (false == result)
            return QString();

        QString styleSheet = styleFile.readAll();
        styleFile.close();

        return styleSheet;
    }

    StyleManager::StyleManager()
        : MainWindow(QSize(360, 590), ":qss/MainWindow.qss")
        , PushButton(QSize(16, 16), ":qss/PushButton.qss")
    {
        
    }

    StyleManager::~StyleManager()
    {

    }
}