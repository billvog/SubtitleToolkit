#include "MainWindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  // Show splash image while loading
  QPixmap splashImage(":/Assets/splash.svg");
  QSplashScreen splash(splashImage);
  splash.show();

  a.processEvents();

  MainWindow w;
  w.show();

  splash.finish(&w);

  return a.exec();
}
