#include "MainWindow.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "GameScreen/VideoStreamContent.h"
#include "../Interfaces/GuiInterface.hpp"
#include "InterfaceWrapper.h"

//#include "PlayMenu/DancesModel.h"

void GUI::run(int argc, char** argv)
{
    Q_INIT_RESOURCE(qml);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext(); // view is the QDeclarativeView

    // Register Types
    qmlRegisterType<VideoStreamContent>("Game", 1, 0, "VideoStreamContent");

    Interface::InterfaceWrapper intfWrap(m_intf);
    context->setContextProperty("intfWrap", &intfWrap);

    // Dances Model into Qml Context
    // DancesModel dancesModel();
    /*
    DancesModel dancesModel = new DancesModel();
    QQmlContext* context = engine.rootContext(); // view is the QDeclarativeView
    context->setContextProperty("_rosterItemModel", dancesModel);
    */

    // Build UI
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    app.exec();
}