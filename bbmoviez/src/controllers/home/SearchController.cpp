#include "SearchController.h"
#include "RESTClient.hpp"
#include <bb/cascades/GroupDataModel>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/ListView>
#include <QList>

SearchController::SearchController(bb::cascades::QmlDocument* rootQML)
:Controller(rootQML)
{
	m_root->documentContext()->setContextProperty("_searchController", this);

	QObject::connect(RESTClient::getInstance(), SIGNAL(downloadCompleted(QString)),
				SLOT(handleData(QString)));

	m_movieTitle = "New Movie";
	m_movieYear = "1990";
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

void SearchController::searchMovieDetails(QString movieName) {
	fprintf(stderr, QString(" -------movieName: "+movieName+"----------\n").toStdString().c_str());
	RESTClient::getInstance()->movieDetails(movieName);
}

void SearchController::handleData(QString data) {
	fprintf(stderr, QString(" -------data received----------\n").toStdString().c_str());

	bb::data::JsonDataAccess jda;
	const QVariantMap& map = jda.loadFromBuffer(data).value<QVariantMap>();
	QList<QVariant> theList = map["movies"].toList();
	//m_movieDetails = theList[0].toMap();
	fprintf(stderr, "\n -----------movie data List: %d -----------\n",theList.size());//m_movieDetails
	/*foreach (const QVariant& item, theList) {
		//QVariantMap map = item.toMap();
		QVariantMap map = QVariantMap();
		map["title"] = item.toMap()["title"].toString();
		map["year"] = item.toMap()["year"].toString();
		map["rating"] = item.toMap()["mpaa_rating"].toString();
		map["runtime"] = item.toMap()["runtime"].toString();
		map["criticsConsensus"] = item.toMap()["critics_consensus"].toString();
		map["runtime"] = item.toMap()["runtime"].toString();

		fprintf(stderr, QString(" -------title: "+item.toMap()["title"].toString()+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------year: "+item.toMap()["year"].toString()+"----------\n").toStdString().c_str());
		m_movieDetails.append(map);
	}*/
	foreach (const QVariant& item, theList) {
		QVariantMap details = item.toMap();
		m_movieTitle = details["title"].toString();
		m_movieYear = details["year"].toString();
		m_movieRating = details["mpaa_rating"].toString();
		m_movieRuntime = details["runtime"].toString();
		m_movieCriticsConsensus = details["critics_consensus"].toString();

		fprintf(stderr, QString(" -------m_movieTitle: "+m_movieTitle+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieYear: "+m_movieYear+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieRating: "+m_movieRating+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieRuntime: "+m_movieRuntime+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieCriticsConsensus: "+m_movieCriticsConsensus+"----------\n").toStdString().c_str());

		//const QVariantMap& map = item.toMap()["ratings"];
		const QVariantMap& ratings = details["ratings"].toMap();

		m_movieCR = ratings["critics_rating"].toString();
		m_movieCS = ratings["critics_score"].toString();
		m_movieAR = ratings["audience_rating"].toString();
		m_movieAS = ratings["audience_score"].toString();

		fprintf(stderr, QString(" -------m_movieCR: "+m_movieCR+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieCS: "+m_movieCS+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieAR: "+m_movieAR+"----------\n").toStdString().c_str());
		fprintf(stderr, QString(" -------m_movieAS: "+m_movieAS+"----------\n").toStdString().c_str());

		m_movieSynopsis = details["synopsis"].toString();

		fprintf(stderr, QString(" -------m_movieSynopsis: "+m_movieSynopsis+"----------\n").toStdString().c_str());

		QList<QVariant> castList = details["abridged_cast"].toList();

		m_movieCast = "";
		foreach (const QVariant& member, castList) {
			QVariantMap castMember = member.toMap();

			m_movieCast += castMember["name"].toString() + ", ";
		}
		m_movieCast.remove(m_movieCast.size()-2,2);
		fprintf(stderr, QString(" -------m_movieCast: "+m_movieCast+"----------\n").toStdString().c_str());
	}
	emit movieDetailsReady();
}
