#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QPixmap>
#include <QQmlContext>
#include "GameScreen/VideoStreamContent.h"
#include "PlayMenu/DancesModel.h"
#include <Interface.hpp>
#include <InterfaceWrapper.h>
#include <QTimer>
#include <QCamera>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext(); // view is the QDeclarativeView

    // Register Types
    qmlRegisterType<VideoStreamContent>("Game", 1, 0, "VideoStreamContent");

    Interface::Interface intf;
    Interface::InterfaceWrapper intfWrap(intf);
    context->setContextProperty("intfWrap", &intfWrap);

    // Dances Model into Qml Context
    //DancesModel dancesModel();
    /*
    DancesModel dancesModel = new DancesModel();
    QQmlContext* context = engine.rootContext(); // view is the QDeclarativeView
    context->setContextProperty("_rosterItemModel", dancesModel);
    */

    // Build UI
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    
    return app.exec();
}
