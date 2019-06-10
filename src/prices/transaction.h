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
}
