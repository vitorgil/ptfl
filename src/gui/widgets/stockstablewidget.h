#pragma once

#include <QWidget>

class QTableWidget;

class StocksTableWidget : public QWidget
{
    Q_OBJECT

    QTableWidget* mTableWidget;

public:
    explicit StocksTableWidget(QWidget *parent = 0);

    void initialize();

signals:

public slots:
};
