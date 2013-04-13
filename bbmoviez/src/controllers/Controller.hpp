#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <QObject>
#include <QVariant>

#include <QMap>
#include <QSet>

namespace bb { namespace cascades { class QmlDocument; class AbstractPane; }}
/**
 * define the interfaces to be implemented by all the controllers
 */

class Controller: public QObject
{
	Q_OBJECT

public:
	/**
	 * Constructor
	 */
	Controller(bb::cascades::QmlDocument* rootQML);

	/**
	 * destructor
	 */
	virtual ~Controller(){}



protected:

	bb::cascades::AbstractPane* m_rootPage;
	bb::cascades::QmlDocument* m_root;

protected:

private slots:

protected:
};



#endif /* CONTROLLER_HPP_ */
