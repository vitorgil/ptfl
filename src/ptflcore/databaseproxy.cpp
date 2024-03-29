#include "databaseproxy.h"

#include "ptfldb/io.h"
#include "portfolio.h"

#include <QJsonObject>
#include <QDateTime>

namespace ptfl
{
DatabaseProxy::DatabaseProxy()
{
}

void DatabaseProxy::save(const Portfolio& portfolio)
{
    QJsonObject object;
    const auto& transactions = portfolio.getTransactions();
    int txid = 0;
    for (auto it = transactions.cbegin(); it != transactions.cend(); ++it)
    {
        QJsonObject valueObject;
        valueObject.insert("ticker", it->mTicker);
        valueObject.insert("price", it->mPrice);
        valueObject.insert("volume", QString::number(it->mVolume));
        valueObject.insert("date", it->mDate.toString());

        object.insert("tx" + QString::number(txid++), QJsonValue(valueObject));
    }

    jsondb::saveJson("portfolio.db", QJsonDocument(object));
}

Portfolio* DatabaseProxy::getPortfolio()
{
    Portfolio* p = new Portfolio;
    auto doc = jsondb::readJson("portfolio.db");
    const auto& object = doc.object();
    for (auto it = object.constBegin(); it != object.constEnd(); ++it)
    {
        auto valueObject = it->toObject();
        p->addTransaction(
            valueObject["ticker"].toString(),
            valueObject["price"].toDouble(),
            valueObject["volume"].toString().toUInt(),
            QDateTime::fromString(valueObject["date"].toString()));
    }
    return p;
}

void DatabaseProxy::createDefault()
{
    Portfolio p;
    p.addTransaction("NVDA", 123, 50, {});
    p.addTransaction("AMAT", 40, 150, {});
    save(p);
}
}
