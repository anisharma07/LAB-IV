#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("/home/anirudh/Desktop/c programs/CS_lab/rest/details.json");
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(file, actualJson);
    // now the actualJson will have the json data
    cout << "Total json data:\n"
         << actualJson << endl;

    // // accessing individual parameter
    // cout << "name: " << actualJson[0].name << endl;
    // cout << "Dob:" << actualJson[0] << endl;
    // cout << "College:" << actualJson[0] << endl;
    return 0;
}