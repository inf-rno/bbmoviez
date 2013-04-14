#include "ListDataModel.hpp"
#include <bb/data/JsonDataAccess>

ListDataModel::ListDataModel(QObject* parent) : GroupDataModel(parent)
{
	bb::data::JsonDataAccess jda;
	QVariant json = jda.load(QDir::currentPath() + "/app/native/assets/contacts.json");//"/app/native/assets/employees.json"
	insertList(json.value<QVariantList>());
}
