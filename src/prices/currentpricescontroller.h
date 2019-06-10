#pragma once

#include <QMap>

#include <functional>

namespace ptfl
{
namespace prices
{
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
}
}
