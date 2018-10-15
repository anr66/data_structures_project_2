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
#include <ctime>
#include "Employee.h"
#include "empmaps.h"

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
    clock_t start;
    clock_t stop;

    vector<Employee> emps = employees();

    start = clock();
    map<int,vector<Employee>> map1 = mapEmpDept(emps);
    stop = clock();
    cout << "clock ticks for mapEmpDept: " << double(stop - start) << "\n";

    start = clock();
    map<int, vector<Employee>> map2 = mapSalRange(emps);
    stop = clock();
    cout << "clock ticks for mapSalRange: " << double(stop - start) << "\n";

    printSalRange(map2);

    start = clock();
    unordered_map<int,vector<Employee>> map3 = umapEmpDept(emps);
    stop = clock();
    cout << "clock ticks for unordered mapEmpDept: " << double(stop - start) << "\n";

    start = clock();
    unordered_map<int, vector<Employee>> map4 = umapSalRange(emps);
    stop = clock();
    cout << "clock ticks for unordered mapSalRange: " << double(stop - start) << "\n";

    return 0;
}