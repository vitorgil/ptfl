#include "noneditabletablewidgetitem.h"

NonEditableTableWidgetItem::NonEditableTableWidgetItem(const QString &text)
    : QTableWidgetItem(text)
{
    setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}
