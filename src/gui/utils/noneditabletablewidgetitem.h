#pragma once

#include <QTableWidgetItem>

class NonEditableTableWidgetItem : public QTableWidgetItem
{
public:
    explicit NonEditableTableWidgetItem(const QString &text);
};
