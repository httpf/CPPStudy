#include <iostream>
#include <string>

class Employee {
private:
    std::string name;

public:
    static int ID;

public:
    Employee()
    {
        ID++;
        std::cout << "ID = " << ID << std::endl;
    }
    Employee(std::string new_name):name(new_name)
    {
        ID++;
        std::cout << "name = "<< name << ", ID = " << ID << std::endl;
    }
    Employee(const Employee & orig) = delete;
    Employee & operator=(const Employee & left) = delete;
};

int Employee::ID = 0;

int main(void)
{
    Employee emp1;
    Employee emp2("Yao Xiang");

    return 0;
}