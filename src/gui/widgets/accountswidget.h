#pragma once

#include <QWidget>

class AccountsWidget : public QWidget
{
    Q_OBJECT

public:
    AccountsWidget(QWidget* parent = nullptr);

    void initialize();
};
