#pragma once

#include <QWidget>

class QTableWidget;
class NonEditableTextField;

namespace ptfl
{
class Portfolio;
}

class StocksTableWidget : public QWidget
{
    Q_OBJECT

    // gui
    QTableWidget* mTableWidget = nullptr;
    NonEditableTextField* mPortfolioValue = nullptr;

    // ownership
    ptfl::Portfolio* mPortfolio = nullptr;

public:
    explicit StocksTableWidget(QWidget *parent = 0);
    ~StocksTableWidget();

    void initialize();

};
