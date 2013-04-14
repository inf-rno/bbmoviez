#include "SearchController.h"
#include <bb/cascades/GroupDataModel>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/ListView>
#include <QList>

SearchController::SearchController(bb::cascades::QmlDocument* rootQML)
:Controller(rootQML)
{
	m_root->documentContext()->setContextProperty("_searchController", this);
}

SearchController::~SearchController() {
}

void SearchController::search(QString criteria) {
	//this is temporary. We need to emit the searchResolved signal once we've found something based on the search criteria
	if(criteria == "P") {
		fprintf(stderr, QString("\n -------correct----------\n").toStdString().c_str());
		emit searchResolved();
	}
}

void SearchController::bindData() {
	//bb::cascades::ListView* listView = new ListView;
	QVariantList dataSet;
	m_model = new bb::cascades::GroupDataModel(QStringList() << "firstName"<< "lastName");
	bb::data::JsonDataAccess jda;
	QVariant list = jda.load(QDir::currentPath() + "/app/native/assets/contacts.json");//"/app/native/assets/employees.json"
	m_model->insertList(list.value<QVariantList>());
	dataSet = list.toList();

	fprintf(stderr, QString("\n -------test data: "+dataSet[0].toString()+"----------\n").toStdString().c_str());
	fprintf(stderr, "\n -----------list: %d -----------\n",dataSet.size());
	//listView->setDataModel(model);
}
