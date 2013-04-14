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

public slots:
	void search(QString criteria);
	void bindData();

signals:
	void searchResolved();

private:
	//bb::cascades::QmlDocument* my_root;
	bb::cascades::GroupDataModel* m_model;
};

#endif /* SEARCHCONTROLLER_H_ */
