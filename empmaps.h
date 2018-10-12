// Alycia Riese
// empmaps.h

#include <vector>
#include <map>
#include <unordered_map>
#include "Employee.h"
#include <string>

using std::vector;
using std::map;
using std::unordered_map;
using std::string;

// function prototypes
vector<Employee> employees();
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(map<int,vector<Employee>> & salRange);
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);
vector<string> get_input_data();
