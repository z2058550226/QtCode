#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <myclass.h>
#include <QDebug>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<MyClass>("MyClassLib", 1, 0, "MyClass");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root =engine.rootObjects().value(0);
    QObject* square = root->findChild<QObject *>("square");
    square->setProperty("color",QVariant("blue"));

    QObject* messageText=root->findChild<QObject *>("messageText");
    messageText->setProperty("text",QVariant("C++ is now in control!"));
    messageText->setProperty("color",QVariant("green"));

    return app.exec();
}
