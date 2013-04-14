// Navigation pane project template
#ifndef RESTClient_HPP_
#define RESTClient_HPP_

#include <QObject>

#include <QtNetwork/QNetworkReply>

//RESTClient Singleton
class RESTClient: public QObject {
Q_OBJECT

private Q_SLOTS:
	void slotRequestFinished(QNetworkReply *);

public:
	virtual ~RESTClient() {
	}
	// Returns class instance
	static RESTClient* getInstance();
	void requestJson();
	void movieDetails(QString url);

Q_SIGNALS:
	void downloadCompleted(QString);

private:
	RESTClient();
	QNetworkAccessManager *m_network;
};

#endif /* RESTClient_HPP_ */
