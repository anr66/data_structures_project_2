// Alycia Riese
// empdriver.cpp

// includes
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

// using statements
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::string;
using std::list;
using std::ifstream;
using std::istringstream;


int main()
{
    ifstream input_file;
    string file_name;

    cout << "Please enter a file name to process\n";
    cin >> file_name;

    input_file.open(file_name.c_str());

    if (input_file.fail())
    {
        cout << "Error opening file, try again" << "\n";
        return 0;
    }

    string line;

    while(getline(input_file, line))
    {
        istringstream iss(line);

        string sub;
        iss >> sub;
        cout << "Substrings: " << sub << "\n";
    }

    return 0;
}
