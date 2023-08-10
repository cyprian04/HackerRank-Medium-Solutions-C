#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class Person
{
public:
    virtual void GetData() = 0;
    virtual void PutData() const = 0;
    virtual ~Person() = default;
protected:
    std::string name;
    int age;
};

int curIdStudent = 0;
int curIdProfessor = 0;

class Student : public Person
{
public:
    Student() { id = ++curIdStudent; }
    void GetData() override
    {
        std::cin >> name >> age;
        for (auto i : examScores)
        {
            std::cin >> examScores[i];
            total += examScores[i];
        }
    }
    void PutData()const override
    {
        std::cout << name << " " << age << " " << total << " " << id << std::endl;
    }
private:
    int examScores[6], total, id;
};

class Professor : public Person
{
public:
    Professor() { id = ++curIdProfessor; }
    void GetData() override
    {
        std::cin >> name >> age >> publication;
    }
    void PutData()const override
    {
        std::cout << name << " " << age << " " << publication << " " << id << std::endl;
    }
private:
    int publication, id;
};

int main() {

    int n, val;
    std::cin >> n; //The number of objects that is going to be created.
    Person* per[n]; // it won't compile in Visual Studio2019, bec HackerRank provides for us the whole main func, where we have declarations
                    // Person* per[n]; As we know it can't compile because we can't declare size of arrray at runtime if it's placed on stack
                    // for the problem purpose I'm not going to change any of this
    for (int i = 0; i < n; i++) {

        std::cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->GetData(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->PutData(); // Print the required output for each object.

    return 0;
}