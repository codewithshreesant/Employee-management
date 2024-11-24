#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<iterator>

using namespace std;
struct Employee {
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee& emp)
{
    cout<<"ID: "<<" , Name: "<<emp.name<<" , Salary:$"<< emp.salary << endl;
}

int main()
{
    //structure of employee
    vector<Employee> employees={};
    
    int num;
    cout<<"Enter how many employee information do you want to store "<<endl;
    cin>>num;

    int id=101;
    for (int i = 0; i < num; i++)
    {
        string name;
        double salary;
        cout<<"Enter the name of employee "<<endl;
        cout<<"Enter the  salary "<<endl;
        cin>>name;
        cin>>salary;
        employees.push_back({id, name, salary});
        id++;
        /* code */
    }
    

    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee e2){
        return e1.salary > e2.salary;
    });

    cout<<"Employees sorted by salary -> Highest to lowest \n";

    for_each(employees.begin(), employees.end(), displayEmployee);

    vector<Employee> highEarners;

    copy_if(
        employees.begin(), 
        employees.end(), 
        back_inserter(highEarners), 
        [](const Employee& e){
        return e.salary > 20000;
    });

    cout<<"Employees who are high earners \n";

    for_each(highEarners.begin(), highEarners.end(), displayEmployee);

    double totalSalary=accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e){
        return sum+e.salary;
    });

    double averageSalary = totalSalary/employees.size();

    auto highestPaid=max_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee  &e2){
        return e1.salary < e2.salary;
    });

    return 0;

}


