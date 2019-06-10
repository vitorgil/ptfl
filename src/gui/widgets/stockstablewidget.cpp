#include "stockstablewidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>

#include "utils/noneditabletablewidgetitem.h"
#include "utils/noneditabletextfield.h"

#include "ptflcore/databaseproxy.h"
#include "ptflcore/portfolio.h"

StocksTableWidget::StocksTableWidget(QWidget *parent)
    : QWidget(parent)
{
    setLayout(new QVBoxLayout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    mTableWidget = new QTableWidget();
    layout()->addWidget(mTableWidget);

    layout()->addWidget(new QLabel("Portfolio value", this));
    mPortfolioValue = new NonEditableTextField("Retrieving data...", this);
    layout()->addWidget(mPortfolioValue);
}

StocksTableWidget::~StocksTableWidget()
{
    delete mPortfolio;
}

void StocksTableWidget::initialize()
{
    mPortfolio = ptfl::DatabaseProxy::getPortfolio();

    const auto& transactions = mPortfolio->getTransactions();
    mTableWidget->setRowCount(transactions.size());
    mTableWidget->setColumnCount(4);

    int rowId = 0;
    for (const auto& transaction : transactions)
    {
        mTableWidget->setItem(rowId, 0, new NonEditableTableWidgetItem(transaction.mTicker));
        mTableWidget->setItem(rowId, 1, new NonEditableTableWidgetItem(QString::number(transaction.mVolume)));
        mTableWidget->setItem(rowId, 2, new NonEditableTableWidgetItem(QString::number(transaction.mPrice)));
        mTableWidget->setItem(rowId, 3, new NonEditableTableWidgetItem(transaction.mDate.toString()));
        ++rowId;
    }

    mPortfolio->calculateCurrentValue([this](double value) { mPortfolioValue->setText(QString::number(value)); });
}
