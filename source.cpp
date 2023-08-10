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
    int examScores[6] = { 0 }, total = 0, id = 0;
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
    std::vector<Person*> persons;

    for (int i = 0; i < n; i++) {

        std::cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            persons.emplace_back(new Professor);
        }
        else persons.emplace_back(new Student); // Else the current object is of type Student

        persons.back()->GetData(); // Get the data from the user.
    }

    for (const auto& person : persons)
    {
        person->PutData(); // Print the required output for each object.
        delete person;
    }
    return 0;
}
