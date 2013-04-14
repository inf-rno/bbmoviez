// Navigation pane project template
#ifndef Bbmoviez_HPP_
#define Bbmoviez_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; class QmlDocument; class AbstractPane; class Page;class Container;}}
//namespace controller{}

using namespace bb::cascades;

//class Controller;
/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Bbmoviez : public QObject
{
    Q_OBJECT

public:
    Bbmoviez(bb::cascades::Application *app);
    virtual ~Bbmoviez() {}

public Q_SLOTS:
    void doStuff(QString);
    void showNodePage();

private:
    QmlDocument* m_root;
    AbstractPane* m_rootPane;
    Page* m_nodePane;
    QList<Container *> m_containerList;
    /**
	 * initialize the controllers.
	 */
	void initializeControllers();
	void physics ();
	float convertToRange(float value, float* srcRange, float* dstRange);


};

#endif /* Bbmoviez_HPP_ */
