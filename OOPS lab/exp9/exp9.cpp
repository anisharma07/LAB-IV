#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<string> names;
    ifstream file("/home/anirudh/Desktop/c programs/CS_lab/exp9/names.txt");
    string name;
    while (getline(file, name))
    {
        names.insert(name);
    }
    file.close();

    cout << "Names in alphabetical order are: " << endl;
    for (auto i : names)
    {
        cout << i << endl;
    }
    return 0;
}
