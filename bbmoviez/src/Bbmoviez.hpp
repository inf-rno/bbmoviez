// Navigation pane project template
#ifndef Bbmoviez_HPP_
#define Bbmoviez_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

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
};

#endif /* Bbmoviez_HPP_ */