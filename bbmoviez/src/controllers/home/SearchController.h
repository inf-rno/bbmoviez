#ifndef SEARCHCONTROLLER_H_
#define SEARCHCONTROLLER_H_

#include "Controller.hpp"
#include <QObject>

namespace bb { namespace cascades { class QmlDocument; class AbstractPane; }}

class SearchController : public Controller {
	Q_OBJECT

public:

	explicit SearchController(bb::cascades::QmlDocument* rootQML);
	virtual ~SearchController();

public slots:
	void search(QString criteria);

signals:
	void searchResolved();

private:
	//bb::cascades::QmlDocument* my_root;
};

#endif /* SEARCHCONTROLLER_H_ */
