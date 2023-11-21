#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using namespace rapidjson;

std::string jsonToXml(const Value& value, const char* rootName = "root") {
    StringBuffer xmlBuffer;
    Writer<StringBuffer> xmlWriter(xmlBuffer);

    xmlWriter.StartObject();
    xmlWriter.Key(rootName);
    value.Accept(xmlWriter);
    xmlWriter.EndObject();

    return xmlBuffer.GetString();
}

int main() {
    const char* jsonString = R"({
        "name": "John",
        "age": 30,
        "city": "New York"
    })";

    Document jsonDocument;
    jsonDocument.Parse(jsonString);

    if (!jsonDocument.HasParseError()) {
        std::string xmlString = jsonToXml(jsonDocument);
        std::cout << xmlString << std::endl;
    } else {
        std::cerr << "Error parsing JSON" << std::endl;
    }

    return 0;
}

