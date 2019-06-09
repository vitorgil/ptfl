#include "portfolio.h"

namespace ptfl
{
Portfolio::Portfolio()
{

}

void Portfolio::addTransaction(const QString& ticker, double price, unsigned int volume, const QDateTime& date) {
    mTransactions.push_back({ ticker, price, volume, date });
}

}
