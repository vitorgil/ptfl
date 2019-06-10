#pragma once

#include <QDateTime>
#include <QString>

#include <functional>

#include "prices/pricesapi.h"
#include "prices/transaction.h"

namespace ptfl
{

namespace prices
{
class CurrentPricesController;
}

class Portfolio
{
    Transactions mTransactions;
    prices::CurrentPricesController* mCurrentPricesController;

public:
    Portfolio();

    void addTransaction(const QString& ticker, double price, unsigned int volume, const QDateTime& date);
    inline const Transactions& getTransactions() const { return mTransactions; }

    double calculateInvestedCapital() const;
    void calculateCurrentValue(const prices::PriceUpdateCallback& callback);

private:
    void onAllPricesReceived(const Transactions& transactions);
};
}
