// Alycia Riese
// empmaps.cpp


// includes
#include "empmaps.h"
#include "Employee.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// using statements
using std::vector;
using std::map;
using std::unordered_map;
using std::istringstream;
using std::cout;
using std::string;
using std::ifstream;
using std::cin;


vector<Employee> employees()
{
    vector<Employee> employee_vec;

    // get the data from the input file
    vector<string> data = get_input_data();

    // iterate through it to get what we want
    for(vector<string>::iterator it = data.begin(); it != data.end(); it++)
    {
        istringstream iss(*it);

        string id;
        iss >> id;

        string name;
        iss >> name;

        string salary;
        iss >> salary;

        Employee emp(stoi(id), name, stoi(salary));
        employee_vec.push_back(emp);
    }

}


// Creates a map of employees based on 4 digit deptartment numbers
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp)
{
    map<int, vector<Employee>> dept;

    for(int i = 0; i <= emp.size(); i++)
    {
        int dept_num = emp[i].id() / 100;
        dept[dept_num].push_back(emp[i]);
    }

}


// Creates a map of employees based on salary ranges
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
    map<int, vector<Employee>> sal;

    for(int i = 0; i <= emp.size(); i++)
    {
        int sal_range = (emp[i].salary() / 10000) * 10000;
        sal[sal_range].push_back(emp[i]);

    }

}


void printSalRange(map<int,vector<Employee>> & salRange)
{
    map<int, vector<Employee>::iterator it;
    for (it = salRange.begin(); it != salRange.end(); ++it)
    {
        cout << *it << "\n";
    }

}


unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{

}


unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{

}


void uprintSalRange(unordered_map<int,vector<Employee>> & salRange)
{

}


vector<string> get_input_data()
{
    ifstream input_file;
    string file_name;

    cout << "Please enter a file name to process\n";
    cin >> file_name;

    input_file.open(file_name.c_str());

    if (input_file.fail())
    {
        cout << "Error opening file, try again" << "\n";
    }

    string line;

    vector<string> lines;

    while(getline(input_file, line))
    {
        lines.push_back(line);

        //istringstream iss(line);

        //string id;
        //iss >> id;

        //string name;
        //iss >> name;

        //string salary;
        //iss >> salary;

        //cout << "id: " << id << "name: " << name << "salary: " << salary << "\n";
    }

    return lines;
}
