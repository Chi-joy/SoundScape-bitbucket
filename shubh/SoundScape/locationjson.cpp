#include "locationjson.h"
#include "QtCore/qfile.h"
#include "QtCore/qjsondocument.h"
#include "QtCore/qjsonobject.h"
#include "json.hpp"

locationJson::locationJson()
{

    QFile file("locations.json");

       // Read the contents of the JSON file
    QByteArray data = file.readAll();
    nlohmann::json myjson = nlohmann::json::parse(data);

       // Parse the JSON document
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

       // Get the root object of the JSON document
    QJsonObject rootObj = jsonDoc.object();

       // Get the array of values from the root object
    QJsonArray locationArray = rootObj.value("values").toArray();

       // Save the values in the input array
    jsonArray = valuesArray;

}
