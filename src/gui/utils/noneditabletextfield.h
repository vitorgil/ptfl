#pragma once

#include <QLineEdit>

class NonEditableTextField : public QLineEdit
{
public:
    NonEditableTextField(const QString& text, QWidget* parent = nullptr);
};
