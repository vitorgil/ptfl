#pragma once

#include <QDateTime>
#include <QMap>
#include <QObject>
#include <QString>
#include <QVector>

#include <functional>

#include "prices/pricesapi.h"

namespace ptfl
{
typedef struct
{
    QString mTicker;
    double mPrice;
    unsigned int mVolume;
    QDateTime mDate;
} Transaction;
typedef QVector<Transaction> Transactions;

class CurrentPricesController
{
    size_t mNumberOfTickers;
    bool mDone = true;

    typedef std::function<void()> AllPricesReceivedCallback;
    const AllPricesReceivedCallback mCallback;

    typedef QMap<QString, double> CurrentPrices;
    CurrentPrices mCurrentPrices;


public:
    explicit CurrentPricesController(const AllPricesReceivedCallback& callback);

    bool isDone() const { return mDone; }
    double getPrice(const QString& ticker) const;

    void reset(size_t numberOfTickers);
    void priceReceived(const QString& ticker, double price);
};

class Portfolio
{
    Transactions mTransactions;
    CurrentPricesController* mCurrentPricesController;

public:
    Portfolio();

    void addTransaction(const QString& ticker, double price, unsigned int volume, const QDateTime& date);
    inline const Transactions& getTransactions() const { return mTransactions; }

    double calculateInvestedCapital() const;
    void calculateCurrentValue(const prices::PriceUpdateCallback& callback);

private:
    void onAllPricesReceived(const ptfl::Transactions& transactions);
};
}
