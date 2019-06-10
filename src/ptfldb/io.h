#pragma once

#include <QJsonDocument>
#include <QString>

namespace ptfl::jsondb
{
void saveJson(const QString& fileName, const QJsonDocument& doc);
QJsonDocument readJson(const QString& fileName);
}
