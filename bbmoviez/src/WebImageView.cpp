#include "WebImageView.hpp"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkDiskCache>
#include <QtNetwork/QNetworkAccessManager>
#include <exception>
#include <QDebug>

using namespace bb::cascades;

const QString CACHE_FOLDER = "/Cache/";

QNetworkAccessManager * WebImageView::s_netManager = new QNetworkAccessManager();
QNetworkDiskCache * WebImageView::s_networkDiskCache = new QNetworkDiskCache();

void createDir(const QString& path) {
    // trim the file name out of the path if any
    QFileInfo fileInfo(path);
    QDir dir = fileInfo.dir();

    if (!dir.exists()) {
        dir.mkpath(dir.absolutePath());
    }
}

WebImageView::WebImageView()
: mCurrentRequestIndex(0) {

    QString folder = QDir::homePath() + CACHE_FOLDER;
    createDir(folder);

    if (s_networkDiskCache->cacheDirectory().isEmpty()) { // Initialize only once
        // Initialize network cache
        s_networkDiskCache->setCacheDirectory(folder);
        s_networkDiskCache->setMaximumCacheSize(1024 * 1024 * 50); // Set to 50 MB explicitly

        // Set cache in manager
        s_netManager->setCache(s_networkDiskCache);
    }
}

const QUrl& WebImageView::url() const {
    return mUrl;
}

void WebImageView::setUrl(const QUrl& url) {

    // Variables
    mUrl = url;
    mLoading = 0;

    QIODevice* device = s_networkDiskCache->data(url);
    if (device) {
        // If possible, set the image synchronously for smoother transition
        // helps on the app cover
        QByteArray imageData = device->readAll();
        //needs delete from our side (according to the doc.)
        delete device;
        setImage(Image(imageData));
        emit urlChanged();
        return;
    }

    // Reset the image
    resetImage();

    // Create request
    QNetworkRequest request;
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    mCurrentRequestIndex++;
    request.setAttribute(QNetworkRequest::User, mCurrentRequestIndex);
    request.setUrl(url);

    // Create reply
    QNetworkReply * reply = s_netManager->get(request);
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(imageLoaded()));
    QObject::connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(dowloadProgressed(qint64,qint64)));

    //
    // Note:
    // If you see Function "downloadProgress ( qint64 , qint64  ) is not defined"
    // Simply close this file, delete the error and compile the project
    //

    emit urlChanged();
}

double WebImageView::loading() const {
    return mLoading;
}

void WebImageView::imageLoaded() {

    // Get reply
    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

    // Check the reply for the attribute we set and if it's the same as our current
    // index, we can process, otherwise just delete the reply
    if (reply->request().attribute(QNetworkRequest::User, 0) == mCurrentRequestIndex) {
        // Process reply
        QByteArray imageData = reply->readAll();

        bool err = false;
        QNetworkReply::NetworkError error = reply->error();
        if (error != QNetworkReply::NoError) {
            qDebug() << "WebImageView::imageLoaded: error" << error;
            qDebug() << "WebImageView::imageLoaded: errorStr" << reply->errorString();
            err = true;
        }

        QVariant fromCache = reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute);
        if (fromCache.toBool() == false) {
        	qDebug() << "WebImageView::imageLoaded: - Image not from cache";
        }

        if(imageData.size() <= 0) {
        	qDebug() << "WebImageView::imageLoaded: - No data received";
        }

        // Set image from data
        if(!err)
            setImage(Image(imageData));
    }

    // Memory management
    reply->deleteLater();
}

void WebImageView::dowloadProgressed(qint64 bytes, qint64 total) {
    mLoading = double(bytes) / double(total);
    emit loadingChanged();
}
