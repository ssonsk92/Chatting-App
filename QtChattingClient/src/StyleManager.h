#pragma once
#include <qfile.h>
#include <qsize.h>

namespace ChatApp
{
	struct Style
	{
		QSize size;
		QString qssPath;

		Style(QSize _size, const QString& _qssPath)
			: size(_size)
			, qssPath(_qssPath) {};
	};

	class StyleManager
	{
	public:
		static StyleManager* GetInstance();
		static QString loadQSS(const QString& path);

	private:
		StyleManager();
		~StyleManager();

	public:
		const Style MainWindow;
		const Style PushButton;
	};
}

