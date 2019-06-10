#include "pricesapi.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace
{
constexpr const char* AlphaAdvantageApiKey = "TJDWSWHQLVXLMVGT";
}

namespace ptfl
{
namespace prices
{
void getPrice(const QString& ticker, const PriceUpdateCallback& callback)
{
    static QNetworkAccessManager networkAccessManager;

    QNetworkRequest request(
        QUrl(QString("https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + ticker + "&apikey=" + AlphaAdvantageApiKey)));
    auto networkReply = networkAccessManager.get(request);

    QObject::connect(networkReply, &QNetworkReply::readyRead,
            [=]() {
                if (networkReply->error()) {
                    qDebug() << networkReply->errorString();
                    return;
                }

                auto jsonObject = QJsonDocument::fromJson(networkReply->readAll()).object();
                // Object contains one single child object.
                auto globalQuoteObject = jsonObject.constBegin()->toObject();
                // read the price field from the subobject
                auto res = globalQuoteObject["05. price"];
                callback(res.toString().toDouble());

                delete networkReply;
            }
        );
}
}
}
