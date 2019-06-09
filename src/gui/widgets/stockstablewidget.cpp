#include "stockstablewidget.h"

#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "utils/noneditabletablewidgetitem.h"

#include "dbcomm/databaseproxy.h"
#include "dbcomm/portfolio.h"

StocksTableWidget::StocksTableWidget(QWidget *parent)
    : QWidget(parent)
{
    setLayout(new QHBoxLayout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    mTableWidget = new QTableWidget();
    layout()->addWidget(mTableWidget);
}

void StocksTableWidget::initialize()
{
    const auto portfolio = ptfl::DatabaseProxy::getPortfolio();
    const auto& transactions = portfolio.getTransactions();
    mTableWidget->setRowCount(transactions.size());
    mTableWidget->setColumnCount(4);

    int rowId = 0;
    for (const ptfl::Transaction& transaction : transactions)
    {
        mTableWidget->setItem(rowId, 0, new NonEditableTableWidgetItem(transaction.mTicker));
        mTableWidget->setItem(rowId, 1, new NonEditableTableWidgetItem(QString::number(transaction.mVolume)));
        mTableWidget->setItem(rowId, 2, new NonEditableTableWidgetItem(QString::number(transaction.mPrice)));
        mTableWidget->setItem(rowId, 3, new NonEditableTableWidgetItem(transaction.mDate.toString()));
        ++rowId;
    }
}
