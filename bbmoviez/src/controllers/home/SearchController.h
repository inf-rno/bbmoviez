#ifndef SEARCHCONTROLLER_H_
#define SEARCHCONTROLLER_H_

#include "Controller.hpp"
#include <QObject>
#include <QList>
#include <bb/cascades/GroupDataModel>

namespace bb { namespace cascades { class QmlDocument; class AbstractPane; }}

class SearchController : public Controller {
	Q_OBJECT

	Q_PROPERTY(QVariant movieTitle READ movieTitle)
	Q_PROPERTY(QVariant movieYear READ movieYear)
	Q_PROPERTY(QVariant movieRating READ movieRating)
	Q_PROPERTY(QVariant movieRuntime READ movieRuntime)
	Q_PROPERTY(QVariant movieCritics READ movieCritics)

	Q_PROPERTY(QVariant movieCR READ movieCR)
	Q_PROPERTY(QVariant movieCS READ movieCS)
	Q_PROPERTY(QVariant movieAR READ movieAR)
	Q_PROPERTY(QVariant movieAS READ movieAS)

	Q_PROPERTY(QVariant movieS READ movieS)

	Q_PROPERTY(QVariant movieCast READ movieCast)

	Q_PROPERTY(QVariant movieThumbnail READ movieThumbnail)

	Q_PROPERTY(QVariant movieFullScreen READ movieFullScreen)

public:

	explicit SearchController(bb::cascades::QmlDocument* rootQML);
	virtual ~SearchController();
	void bindDataModel(const QString& listVewName, QVariantList& dataSet);
	Q_INVOKABLE void handleMoviePicked(){emit moviePicked();}

public slots:
	void search(QString criteria);
	void bindData(QString list);
	void searchMovieDetails(QString movieId);
	void handleData(QString data);

	const QString& movieTitle()const {return m_movieTitle;}
	const QString& movieYear()const {return m_movieYear;}
	const QString& movieRating()const {return m_movieRating;}
	const QString& movieRuntime()const {return m_movieRuntime;}
	const QString& movieCritics()const {return m_movieCriticsConsensus;}

	const QString& movieCR()const {return m_movieCR;}
	const QString& movieCS()const {return m_movieCS;}
	const QString& movieAR()const {return m_movieAR;}
	const QString& movieAS()const {return m_movieAS;}

	const QString& movieS()const {return m_movieSynopsis;}

	const QString& movieCast()const {return m_movieCast;}

	const QString& movieThumbnail()const {return m_movieThumnail;}
	const QString& movieFullScreen()const {return m_movieFullScreenImage;}

	Q_INVOKABLE QVariantList getMovieDetails(){
		return m_movieDetails;
	}

signals:
	void searchResolved();
	void movieDetailsReady();
	void moviePicked();


private:
	//bb::cascades::QmlDocument* my_root;
	bb::cascades::AbstractPane* m_rootPage;
	bb::cascades::GroupDataModel* m_model;

	QVariantList m_myMovies;
	QVariantList m_movieDetails;

	QString m_movieTitle;
	QString m_movieYear;
	QString m_movieRating;
	QString m_movieCriticsConsensus;
	QString m_movieRuntime;

	QString m_movieCR;
	QString m_movieCS;
	QString m_movieAR;
	QString m_movieAS;

	QString m_movieSynopsis;

	QString m_movieCast;
	QString m_movieThumnail;

	QString m_movieFullScreenImage;

	//QVariantMap m_movieDetails;
};

#endif /* SEARCHCONTROLLER_H_ */
