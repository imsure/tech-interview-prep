#include "common.hpp"

// Employee info
class Employee {
public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};


// Map employ ID to index of employee record, recursively add up
// the importance value of all indirect subordinates.

class Solution {
private:
  int _getImportance(vector<Employee*>& employees, int id, unordered_map<int, int>& id2index) {
    int i = id2index[id];
    Employee* e = employees[i];
    if (e->subordinates.empty()) return e->importance;

    int sum = e->importance;
    for (int sub_id : e->subordinates) sum += _getImportance(employees, sub_id, id2index);
    return sum;
  }

public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, int> id2index;
    for (int i = 0; i < employees.size(); ++i) id2index[employees[i]->id] = i;
    return _getImportance(employees, id, id2index);
  }
};


int main()
{
  Solution sol;
}
