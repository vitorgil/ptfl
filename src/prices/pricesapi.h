#pragma once

#include <QString>
#include <functional>

namespace ptfl
{
namespace prices
{
typedef std::function<void(double)> PriceUpdateCallback;
void getPrice(const QString& ticker, const PriceUpdateCallback& callback);
}
}
