#include "portfolio.h"

namespace
{
std::function<void(double)> gCallback;

}

namespace ptfl
{

CurrentPricesController::CurrentPricesController(const AllPricesReceivedCallback& callback)
    : mCallback(callback)
{}

double CurrentPricesController::getPrice(const QString& ticker) const
{
    return mCurrentPrices.value(ticker);
}

void CurrentPricesController::reset(size_t numberOfTickers)
{
    mNumberOfTickers = numberOfTickers;
    mDone = false;
}

void CurrentPricesController::priceReceived(const QString& ticker, double price)
{
    mCurrentPrices[ticker] = price;

    if (--mNumberOfTickers == 0)
    {
        mDone = true;
        mCallback();
    }
}

Portfolio::Portfolio()
{
    mCurrentPricesController = new CurrentPricesController([this]() { onAllPricesReceived(mTransactions); });
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

void Portfolio::onAllPricesReceived(const ptfl::Transactions& transactions)
{
    double value = 0.0;
    for (const auto& transaction : transactions)
    {
        value += transaction.mVolume * mCurrentPricesController->getPrice(transaction.mTicker);
    }
    gCallback(value);
}
}
