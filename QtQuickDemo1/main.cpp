#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQml>
#include "colorMaker.h"

ColorMaker::ColorMaker(QObject *parent) : QObject(parent)
{

}

int main(int argc, char *argv[])
{
//#if defined(Q_OS_WIN)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

    QGuiApplication app(argc, argv);
    QQuickView viewer;
    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.rootContext()->setContextProperty("colorMaker", new ColorMaker);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

    return app.exec();
}
