#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QtCore>
#include <QDir>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <iostream>


class Download : public QObject
{
    Q_OBJECT

    QString filePathName;

    QString stockID;

    QFile* file;

    QString sUrl;

    QString sData;

public:
    explicit Download(QObject *parent = 0, QString ID= "");

    void setUrl();

    void setFilePath();

    void writeFile();

    bool getData();

signals:

public slots:
    void slotGetFinish(QNetworkReply *reply);
};

#endif // DOWNLOAD_H
