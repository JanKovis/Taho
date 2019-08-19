// Quelle: http://tomtheprogrammer.wordpress.com/2013/05/27/qt-5-download-a-file/

#ifndef URLDOWNLOAD_H
#define URLDOWNLOAD_H
#include <QString>
#include <QDir>

class QNetworkReply;
class QAuthenticator;

class urlDownload
{
public:
    urlDownload();
    static int downloadFile(const QString &url, const QString &aPathInClient);
    static int downloadFile(const QString &url, const QDir &aPath, const QString &aFile);
};

class AuthenticationHandler : public QObject
{
    Q_OBJECT
public:
    explicit AuthenticationHandler(QObject * = nullptr);

    void setLogin(const QString &login);
    void setPassword(const QString &password);

public slots:
    void handleAuthentication(QNetworkReply* rep, QAuthenticator * auth);

private:
    QString m_login;
    QString m_password;
};

#endif // URLDOWNLOAD_H
