#pragma once

#include <QDateTime>
#include <QString>
#include <QVector>

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

class Portfolio
{
    Transactions mTransactions;

public:
    Portfolio();

    void addTransaction(const QString& ticker, double price, unsigned int volume, const QDateTime& date);
    inline const Transactions& getTransactions() const { return mTransactions; }
};
}
