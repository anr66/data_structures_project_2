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

        if (id.length() > 0 && name.length() > 0 && salary.length() > 0)
        {
            Employee emp(stoi(id), name, stoi(salary));
            employee_vec.push_back(emp);
        }
    }

    cout << "Number of employees: " << employee_vec.size() << "\n";

    return employee_vec;

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

    cout << "ORDERED Map number of departments: " << dept.size() << "\n";

    return dept;
}


// Creates a map of employees based on salary ranges
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
    map<int, vector<Employee>> sal;

    for(int i = 0; i <= emp.size(); i++)
    {
        int sal_range = (emp[i].sal() / 10000) * 10000;
        sal[sal_range].push_back(emp[i]);
    }

    cout << "ORDERED Map number of salary ranges: " << sal.size() << "\n";

    return sal;
}


void printSalRange(map<int,vector<Employee>> & salRange)
{
    int largest_size = 0;
    int largest_group = 0;

    //map<int, vector<Employee>>::iterator it;
    for (auto it = salRange.begin(); it != salRange.end(); ++it)
    {
        int emps = it->second.size();
        int groups = it->first;

        cout << "ORDERED Map Salary Range " << groups << " contains " << emps << "\n";

        // Check to see if we found a range with more employees
        if (emps > largest_size)
        {
            largest_group = groups;
            largest_size = emps;
        }
    }

    cout << "ORDERED Map Salary Range with most employees: " << largest_group << 
    " containing " << largest_size << " employees\n";

}


unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> dept;

    for(int i = 0; i <= emp.size(); i++)
    {
        int dept_num = emp[i].id() / 100;
        dept[dept_num].push_back(emp[i]);
    }

    cout << "UNORDERED Map number of departments: " << dept.size() << "\n";

    return dept;
}


unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> sal;

    for(int i = 0; i <= emp.size(); i++)
    {
        int sal_range = (emp[i].sal() / 10000) * 10000;
        sal[sal_range].push_back(emp[i]);
    }

    cout << "UNORDERED Map number of salary ranges: " << sal.size() << "\n";

    return sal;
}


void uprintSalRange(unordered_map<int,vector<Employee>> & salRange)
{
    int largest_size = 0;
    int largest_group = 0;

    unordered_map<int, vector<Employee>>::iterator it;
    for (it = salRange.begin(); it != salRange.end(); ++it)
    {
        int emps = it->second.size();
        int groups = it->first;

        cout << "UNORDERED Map Salary Range " << groups << " contains " << emps << "\n";

        // Check to see if we found a range with more employees
        if (emps > largest_size)
        {
            largest_group = groups;
            largest_size = emps;
        }
    }

    cout << "UNORDERED Map Salary Range with most employees: " << largest_group << 
    " containing " << largest_size << " employees\n";
}


vector<string> get_input_data()
{
    ifstream input_file;
    string file_name;

    cout << "Please enter a file name to process\n";
    cin >> file_name;

    input_file.open(file_name.c_str());

    while (input_file.fail())
    {
        cout << "Error opening file, try again" << "\n";
        cin >> file_name;
        input_file.open(file_name.c_str());        
    }

    string line;

    vector<string> lines;

    while(getline(input_file, line))
    {
        if (line.length() > 0)
        {
            lines.push_back(line);
        }
    }
    
    return lines;
}
