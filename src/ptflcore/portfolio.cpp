#include "portfolio.h"

#include "prices/currentpricescontroller.h"

namespace
{
std::function<void(double)> gCallback;
}

namespace ptfl
{
Portfolio::Portfolio()
{
    mCurrentPricesController = new prices::CurrentPricesController([this]() { onAllPricesReceived(mTransactions); });
}

void Portfolio::addTransaction(const QString& ticker, double price, unsigned int volume, const QDateTime& date)
{
    mTransactions.push_back({ ticker, price, volume, date });
}

double Portfolio::calculateInvestedCapital() const
{
    double value = 0.0;
    for (const Transaction& transaction : mTransactions)
    {
        value += transaction.mPrice * transaction.mVolume;
    }
    return value;
}

void Portfolio::calculateCurrentValue(const prices::PriceUpdateCallback& callback)
{
    gCallback = callback;

    for (const auto& transaction : mTransactions)
    {
        prices::getPrice(transaction.mTicker,
            [this, transaction](double price)
            {
                if (mCurrentPricesController->isDone())
                {
                    mCurrentPricesController->reset(mTransactions.size());
                }
                mCurrentPricesController->priceReceived(transaction.mTicker, price);
            }
        );
    }
}

void Portfolio::onAllPricesReceived(const Transactions& transactions)
{
    double value = 0.0;
    for (const auto& transaction : transactions)
    {
        value += transaction.mVolume * mCurrentPricesController->getPrice(transaction.mTicker);
    }
    gCallback(value);
}
}
