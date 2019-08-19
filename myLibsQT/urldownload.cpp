#include "urldownload.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QEventLoop>
#include <QFileInfo>
#include <QFile>
#include <QAuthenticator>

urlDownload::urlDownload()
{
}

int urlDownload::downloadFile(const QString &url, const QDir &aPath,const QString &aFile)
{
    QFileInfo fi(aPath,aFile);
    return downloadFile(url,fi.filePath());
}

int urlDownload::downloadFile(const QString &url, const QString &aPathInClient)
{
    QNetworkAccessManager m_NetworkMngr;

    AuthenticationHandler authHandler;
    // introduce new parameters for the credentials or you need to transfer them here somehow
    authHandler.setLogin("dimitri");
    authHandler.setPassword("tptahod");
    QObject::connect(&m_NetworkMngr, &QNetworkAccessManager::authenticationRequired,
            &authHandler, &AuthenticationHandler::handleAuthentication);

    QNetworkReply * reply= m_NetworkMngr.get(QNetworkRequest(url));
    const QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> replyDestroyer(reply);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QUrl aUrl(url);
    QFileInfo fileInfo=aUrl.path();

//        QFile file(aPathInClient+"/"+fileInfo.fileName());
    QFile file(aPathInClient);
    file.open(QIODevice::WriteOnly);
    const auto ba=reply->readAll();
    file.write(ba);
    file.close();

    return 0;
}

//---------------------------------------------------------------------
AuthenticationHandler::AuthenticationHandler(QObject * p) : QObject(p)
{
}

void AuthenticationHandler::setLogin(const QString &login)
{
    m_login = login;
}

void AuthenticationHandler::setPassword(const QString &password)
{
    m_password = password;
}

void AuthenticationHandler::handleAuthentication(QNetworkReply *, QAuthenticator * auth)
{
    qDebug() << "Authenticating as " << m_login << "/" << m_password;
    auth->setUser(m_login);
    auth->setPassword(m_password);
}

