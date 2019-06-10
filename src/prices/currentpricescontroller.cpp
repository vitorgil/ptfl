#include "currentpricescontroller.h"

namespace ptfl
{
namespace prices
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
}
}
