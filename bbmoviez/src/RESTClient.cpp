// Navigation pane project template
#include "RESTClient.hpp"

#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

static const char *REQUEST_URL =
		"http://aeba659c7.hosted.neo4j.org:7265/db/data/";
static const char *USER = "f8440e611";
static const char *PASSWORD = "cfae570c0";

RESTClient::RESTClient() {

	m_network = new QNetworkAccessManager(this);
	QObject::connect(m_network, SIGNAL(finished(QNetworkReply *)),
			SLOT(slotRequestFinished(QNetworkReply *)));
}

RESTClient* RESTClient::getInstance() {
	static RESTClient client;
	return &client;
}

void RESTClient::slotRequestFinished(QNetworkReply *reply) {
	QString data;
	if (reply->error() > 0) {
		data = "Error number = " + reply->errorString();
	} else {
		data = reply->readAll();
	}
	emit downloadCompleted(data);
}

QString RESTClient::requestJson() {
	QNetworkRequest request;
	request.setRawHeader("Authorization",
			"Basic "
					+ QByteArray(
							QString("%1:%2").arg(USER).arg(PASSWORD).toAscii()).toBase64());
	request.setUrl(QUrl(REQUEST_URL));
	QNetworkReply *reply = m_network->get(request);
}
