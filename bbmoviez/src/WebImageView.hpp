/**
 * Forked from https://github.com/RileyGB/BlackBerry10-Samples/tree/master/WebImageViewSample
 */

#ifndef WEBIMAGEVIEW_H_
#define WEBIMAGEVIEW_H_

#include <bb/cascades/ImageView>

class QNetworkAccessManager;
class QNetworkDiskCache;

class WebImageView: public bb::cascades::ImageView {
Q_OBJECT

Q_PROPERTY (QUrl url READ url WRITE setUrl NOTIFY urlChanged)
Q_PROPERTY (float loading READ loading NOTIFY loadingChanged)

public:
    WebImageView();
    const QUrl& url() const;
    double loading() const;

public Q_SLOTS:
    void setUrl(const QUrl& url);

private Q_SLOTS:
    void imageLoaded();
    void dowloadProgressed(qint64, qint64);

signals:
    void urlChanged();
    void loadingChanged();

private:
    static QNetworkAccessManager* s_netManager;
    static QNetworkDiskCache* s_networkDiskCache;
    QUrl mUrl;
    float mLoading;

    // We need to track our image requests so that we can cancel any that are already pending
    int mCurrentRequestIndex;
};

#endif /* WEBIMAGEVIEW_H_ */
