#include <QApplication>
#include <QQmlApplicationEngine>

#include "egapplication.h"
#include "eghistoricalchart.h"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  EgApplication myApp;

  engine.rootContext()->setContextProperty("myApp", &myApp);

  qmlRegisterType<EgHistoricalChart>("EgChart", 1, 0, "EgHistoricalChart");

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
