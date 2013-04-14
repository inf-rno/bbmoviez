// Navigation pane project template
#ifndef Bbmoviez_HPP_
#define Bbmoviez_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; class QmlDocument;}}
//namespace controller{}

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

private:
    bb::cascades::QmlDocument* m_root;
    /**
	 * initialize the controllers.
	 */
	void initializeControllers();
};

#endif /* Bbmoviez_HPP_ */
