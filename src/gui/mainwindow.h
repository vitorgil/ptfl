#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class AccountsWidget;
class StocksTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StocksTableWidget* mStocksTableWidget;
    AccountsWidget* mAccountsWidget;
};
