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

void SearchController::bindData(QString list) {
	bb::cascades::ListView* listView = new bb::cascades::ListView();

	QVariantList dataSet;
	m_model = new bb::cascades::GroupDataModel(QStringList() << "firstName"<< "lastName");
	bb::data::JsonDataAccess jda;
	QVariant json = jda.load(QDir::currentPath() + "/app/native/assets/contacts.json");//"/app/native/assets/employees.json"
	m_model->insertList(json.value<QVariantList>());
	dataSet = json.toList();

	const QVariantMap& var = json.toMap();
	QList<QVariant> theList = json.toList();

	foreach (const QVariant& item, theList) {
		//QVariantMap map = item.toMap();
		QVariantMap map = QVariantMap();
		map["type"]  = "movies";
		map["name"] = item.toMap()["firstName"].toString();
		map["details"] = item.toMap()["employeeNumber"].toString();
		map["pictureUrl"] = "url";
		fprintf(stderr, QString(" -------firstName: "+item.toMap()["firstName"].toString()+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------employeeNumber: "+item.toMap()["employeeNumber"].toString()+"----------\n").toStdString().c_str());
		m_myMovies.append(map);
	}
	m_model->insertList(m_myMovies);

	//fprintf(stderr, QString("\n -------test data: "+dataSet[0].toString()+"----------\n").toStdString().c_str());
	fprintf(stderr, "\n -----------list: %d -----------\n",theList.size());
	listView->setDataModel(m_model);

}

void SearchController::bindDataModel(const QString& listVewName, QVariantList& dataSet) {
	//bb::cascades::ListView* listView = m_rootPage->findChild<
		//	bb::cascades::ListView*>(listVewName);


	//check if the given listView is for app cover
	/*if(!listView && bb::cascades::Application::instance()->cover()){

		listView = bb::cascades::Application::instance()->cover()->findChild<
						bb::cascades::ListView*>(listVewName);
	}

	if (listView) {
		DataModel* currentListViewDataModel = dynamic_cast<DataModel*>(listView->dataModel());

		// if this listView doesn't have a data model we'll need to Create even if caller asked for Append or Prepend
		if (currentListViewDataModel == NULL && (preferredDataInsertMode == Append || preferredDataInsertMode == Prepend)) {
			preferredDataInsertMode = Create;
		}

		// The caller asked for Create, but we only need to create a new datamodel if there is none in the view.
		// the "setDataModelData" will try to purge old data anyway.
		bool createNewDataModel = false;
		if (preferredDataInsertMode == Create) {
			if (!currentListViewDataModel) {
				currentListViewDataModel = new DataModel(dataModelId);
				createNewDataModel = true;
			}

		}

		// finally add the data set based on caller, or overriden, preference
		switch (preferredDataInsertMode) {
		case Append:
			if(currentListViewDataModel->lastItem()==GHOSTITEM_END)
				currentListViewDataModel->deleteLastItem();
			appendDataModelData(currentListViewDataModel, dataSet);
			break;
		case Prepend:
			prependDataModelData(currentListViewDataModel, dataSet);
			break;
		case Create:
		default:
			setDataModelData(currentListViewDataModel, dataSet, infinitelyScrollable);
			break;
		}

		tryAddListEnding(currentListViewDataModel);

		if(preferredDataInsertMode ==Create || createNewDataModel)
			listView->setDataModel(currentListViewDataModel); //listView take the ownership;

	}*/
}

