#include "Download.h"

void Download::setUrl()
{
    sUrl = "http://ichart.yahoo.com/table.csv?s=" + stockID;
}

void Download::setFilePath()
{
    QDir d;

    if (!d.exists("stock_data"))
        d.mkdir("stock_data");

    if (stockID.length())
        filePathName = d.currentPath() +  tr("/stock_data/") + stockID;
    else
        filePathName = d.currentPath() + tr("/stock_data/index.csv");


}

void Download::writeFile()
{
    QFile file(filePathName);

    if(!file.open(QIODevice::WriteOnly))
        return;

    QTextStream out(&file);

    out<<sData;

    file.close();
}

bool Download::getData()
{
    bool isVaildID=true;
    QNetworkRequest request(sUrl);
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    networkManager->connect(networkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotGetFinish(QNetworkReply*)));

    QEventLoop loop;
    loop.connect(networkManager,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    networkManager->get(request);
    loop.exec();


    if( !sData.length()>0 || sData.length() == 3231 )
    {
        isVaildID=false;
    }

    return isVaildID;
}

void Download::slotGetFinish(QNetworkReply *reply)
{
    sData=QString::fromUtf8(reply->readAll());
}

Download::Download(QObject *parent, QString ID) : QObject(parent), stockID(ID)
{

    setUrl();

    setFilePath();

}
