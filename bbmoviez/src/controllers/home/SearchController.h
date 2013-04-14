#ifndef SEARCHCONTROLLER_H_
#define SEARCHCONTROLLER_H_

#include "Controller.hpp"
#include <QObject>
#include <QList>
#include <bb/cascades/GroupDataModel>

namespace bb { namespace cascades { class QmlDocument; class AbstractPane; }}

class SearchController : public Controller {
	Q_OBJECT

public:

	explicit SearchController(bb::cascades::QmlDocument* rootQML);
	virtual ~SearchController();
	void bindDataModel(const QString& listVewName, QVariantList& dataSet);
	Q_INVOKABLE void handleMoviePicked(){emit moviePicked();}

public slots:
	void search(QString criteria);
	void bindData(QString list);

signals:
	void searchResolved();
	void moviePicked();

private:
	//bb::cascades::QmlDocument* my_root;
	bb::cascades::AbstractPane* m_rootPage;
	bb::cascades::GroupDataModel* m_model;

	QVariantList m_myMovies;
};

#endif /* SEARCHCONTROLLER_H_ */
