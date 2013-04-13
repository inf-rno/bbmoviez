#include "SearchController.h"
#include <bb/cascades/QmlDocument>

SearchController::SearchController(bb::cascades::QmlDocument* rootQML)
:Controller(rootQML)
{
	m_root->documentContext()->setContextProperty("_searchController", this);
}

SearchController::~SearchController() {
}

void SearchController::search(QString criteria) {
	//this is temporary. We need to emit the searchResolved signal once we've found something based on the search criteria
	if(criteria == "pass") {
		emit searchResolved();
	}
}
