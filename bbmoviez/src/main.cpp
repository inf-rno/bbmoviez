// Navigation pane project template
#include "Bbmoviez.hpp"
#include "ListDataModel.hpp"
#include "WebImageView.hpp"

#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include <Qt/qdeclarativedebug.h>

using namespace bb::cascades;

void myMessageOutput(QtMsgType type, const char *msg) {
    //in this function, you can write the message to any stream!
    switch (type) {
        case QtDebugMsg:
            fprintf(stderr, "Debug: %s\n", msg);
            break;
            case QtWarningMsg:
            fprintf(stderr, "Warning: %s\n", msg);
            break;
            case QtCriticalMsg:
            fprintf(stderr, "Critical: %s\n", msg);
            break;
            case QtFatalMsg:
            fprintf(stderr, "Fatal: %s\n", msg);
            abort();
        }
    }

Q_DECL_EXPORT int main(int argc, char **argv)
{
	qmlRegisterType<ListDataModel>("bbmoviez.app", 1, 0, "ListDataModel");
	qmlRegisterType<WebImageView>("bbmoviez.app", 1, 0, "WebImageView");

    // this is where the server is started etc
    Application app(argc, argv);
#ifndef QT_NO_DEBUG
    qInstallMsgHandler(myMessageOutput);
#endif
    // localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "bbmoviez_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }

    // create the application pane object to init UI etc.
    new Bbmoviez(&app);

    // we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}
