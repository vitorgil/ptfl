#ifndef NONEDITABLETEXTFIELD_H
#define NONEDITABLETEXTFIELD_H

#include <QLineEdit>

class NonEditableTextField : public QLineEdit
{
public:
    NonEditableTextField(const QString& text, QWidget* parent = nullptr);
};

#endif // NONEDITABLETEXTFIELD_H
