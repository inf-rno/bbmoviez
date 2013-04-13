// Navigation pane project template
#include "Bbmoviez.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include "SearchController.h"

using namespace bb::cascades;

Bbmoviez::Bbmoviez(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("_controller", this);

    m_root = qml;
    // create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
    initializeControllers();
}

void Bbmoviez::initializeControllers() {

	Controller* controller;
	controller = new SearchController(m_root);
	m_root->setContextProperty("_searchController", controller);
}
