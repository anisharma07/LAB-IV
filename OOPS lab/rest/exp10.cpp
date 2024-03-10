#include <iostream>
#include <fstream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <string>

using namespace std;

void displayJSON(const Json::Value &node, const string &prefix = "")
{
    if (node.isObject())
    {
        for (const auto &key : node.getMemberNames())
        {
            const Json::Value &value = node[key];
            cout << prefix << key << ":\n";
            displayJSON(value, prefix + "  ");
        }
    }
    else if (node.isArray())
    {
        for (int i = 0; i < node.size(); ++i)
        {
            cout << prefix << "[" << i << "]:\n";
            displayJSON(node[i], prefix + "  ");
        }
    }
    else
    {
        cout << prefix << node << "\n";
    }
}

int main()
{
    string filename = "/home/anirudh/Desktop/c programs/CS_lab/rest/details.json";
    Json::Value root;

    // Read and parse the JSON data from the file
    Json::CharReaderBuilder reader;
    ifstream file(filename);

    if (!file)
    {
        cerr << "Failed to open the file: " << filename << endl;
        return 1;
    }

    string errs;
    Json::parseFromStream(reader, file, &root, &errs);

    if (!errs.empty())
    {
        cerr << "JSON parse error: " << errs << endl;
        return 1;
    }

    cout << "JSON data from file '" << filename << "':\n";
    displayJSON(root);

    return 0;
}
