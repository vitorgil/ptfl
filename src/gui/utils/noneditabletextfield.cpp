#include "noneditabletextfield.h"

NonEditableTextField::NonEditableTextField(const QString& text, QWidget* parent)
    : QLineEdit(text, parent)
{
    setReadOnly(true);
}
