#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
		delete[] p;
	}
protected:
	string _name; // 姓名

	int* p = new int[10];
};

class Student : public Person
{
public:
	Student(const char* name)
		:Person(name)
		, _num(1)
		//, _address("西安")
	{
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator= (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	// 1、子类析构函数和父类析构函数构成隐藏关系。（由于多态关系需求，所有析构函数都会特殊处理成destructor函数名）
	// 子类先析构，父类再析构。子类析构函数不需要显示调用父类析构，子类析构后会自动调用父类析构
	~Student()
	{
		//Person::~Person();

		cout << "~Student()" << endl;
	}

protected:
	int _num; //学号
	//string _address;
};
class Animal {
public:
	// 基类的公有成员
	void eat() {
		cout << "Animal eats food." << endl;
	}

	void sleep() {
		cout << "Animal sleeps." << endl;
	}

protected:
	// 基类的受保护成员
	string color;
};

// 派生类
class Dog : public Animal {
public:
	// 派生类的公有成员
	void bark() {
		cout << "Dog barks." << endl;
	}

	void setColor(string clr) {
		color = clr; // 访问基类的受保护成员
	}

	void displayColor() {
		cout << "Dog's color is: " << color << endl;
	}
};
void test_1()
{
	Dog myDog;

	// 调用基类的成员函数
	myDog.eat();
	myDog.sleep();

	// 调用派生类的成员函数
	myDog.bark();

	myDog.setColor("brown");
	myDog.displayColor();
}
class X
{
	int _x;
};

class Y : public X
{
	int _y;
};

// 组合
class M
{
	int _m;
};

class N
{
	M _mm;
	int _n;
};
//继承表示 "是一个（is-a）" 关系,组合表示 "有一个（has-a）" 关系。

int main()
{
	Student s("张三");
	test_1();
	return 0;
}