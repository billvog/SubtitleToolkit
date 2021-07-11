#include "MainWindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	// Show splash image while loading
	QPixmap splashImage(":/assets/splash.svg");
	QSplashScreen splash(splashImage);
	splash.show();

	a.processEvents();

	MainWindow w;
	
	try {
		w.show();
	} catch (const QString) {
		QMessageBox::critical(nullptr, "Error", "An unexpected error occured.");
	}

	splash.finish(&w);

	return a.exec();
}
