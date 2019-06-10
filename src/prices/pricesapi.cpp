#include "pricesapi.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace
{
constexpr const char* AlphaAdvantageApiKey = "TJDWSWHQLVXLMVGT";

QUrl buildUrl(const QString& ticker)
{
    return QUrl(
        QString("https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + ticker + "&apikey=" + AlphaAdvantageApiKey));
}
}

namespace ptfl
{
namespace prices
{
void getPrice(const QString& ticker, const PriceUpdateCallback& callback)
{
    static QNetworkAccessManager networkAccessManager;

    const QNetworkRequest request(buildUrl(ticker));

    QNetworkReply* networkReply = networkAccessManager.get(request);
    QObject::connect(networkReply, &QNetworkReply::readyRead,
        [=]()
        {
            if (networkReply->error())
            {
                qDebug() << networkReply->errorString();
                return;
            }

            QJsonObject jsonObject = QJsonDocument::fromJson(networkReply->readAll()).object();
            // Object contains one single child object.
            QJsonObject globalQuoteObject = jsonObject.constBegin()->toObject();
            // read the price field from the subobject
            QJsonValue res = globalQuoteObject.value("05. price");
            callback(res.toString().toDouble());

            delete networkReply;
        }
    );
}
}
}
