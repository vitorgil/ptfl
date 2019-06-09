#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/accountswidget.h"
#include "widgets/stockstablewidget.h"

#include <QTabWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTabWidget* tabWidget = new QTabWidget();
    setCentralWidget(tabWidget);

    mAccountsWidget = new AccountsWidget(this);
    mAccountsWidget->initialize();
    tabWidget->addTab(mAccountsWidget, "Accounts");

    mStocksTableWidget = new StocksTableWidget(this);
    mStocksTableWidget->initialize();
    tabWidget->addTab(mStocksTableWidget, "Portfolio");
}

MainWindow::~MainWindow()
{
    delete ui;
}
