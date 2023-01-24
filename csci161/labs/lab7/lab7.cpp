// Vasily Kontorer
// lab 7
#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person();
		Person(string theName);
		Person(const Person & obj);
		string getName() const;
		void setName(string theName);
		void display() const;
	private:
		string name;
};

Person :: Person()
{
	name = "";
}

Person :: Person(string theName)
{
	name = theName;
}

Person :: Person(const Person & obj)
{
	name = obj.name;
}

string Person :: getName() const
{
	return name;
}

void Person :: setName(string theName)
{
	name = theName;
}

void Person :: display() const
{
	cout << "Person's name is " << name << '\n';
}

class Student : public Person
{
	public:
		Student(int number, int gpa, string theName);
		Student(const Student & obj);
		int getNumber() const;
		double getGPA() const;
		void setNumber(int number);
		void setGPA(double gpa);
		void sDisplay() const;
	private:
		int sNumber;
		double sGPA;
};

Student :: Student(int number, int gpa, string theName) : Person(theName)
{
	sNumber = number;
	sGPA = gpa;
}

Student :: Student(const Student & obj) : Person(obj)
{
	sNumber = obj.sNumber;
	sGPA = obj.sGPA;
}

int Student :: getNumber() const
{
	return sNumber;
}

double Student :: getGPA() const
{
	return sGPA;
}

void Student :: setNumber(int number)
{
	sNumber = number;
}

void Student :: setGPA(double gpa)
{
	sGPA = gpa;
}

void Student :: sDisplay() const
{
	cout << "Student's name is " << getName() << '\n';
	cout << "Student's number is " << sNumber << '\n';
	cout << "Student's GPA is " << sGPA << '\n';
}

int main()
{
	Person p1("Alice");
	Person p2 = p1;
	Person p3;
	cout << "p1's name is " << p1.getName() << '\n';
	p3.setName("Bob");
	p3.display();
	Student s1(123456789, 4.0, "Charles");
	Student s2 = s1;
	cout << "s2's name is " << s2.getName() << '\n';
	s1.setName("Diane");
	s1.sDisplay();
	return 0;
}
