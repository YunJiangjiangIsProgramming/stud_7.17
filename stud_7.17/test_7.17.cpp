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
	string _name; // ����

	int* p = new int[10];
};

class Student : public Person
{
public:
	Student(const char* name)
		:Person(name)
		, _num(1)
		//, _address("����")
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

	// 1���������������͸������������������ع�ϵ�������ڶ�̬��ϵ�����������������������⴦���destructor��������
	// ����������������������������������������Ҫ��ʾ���ø���������������������Զ����ø�������
	~Student()
	{
		//Person::~Person();

		cout << "~Student()" << endl;
	}

protected:
	int _num; //ѧ��
	//string _address;
};
class Animal {
public:
	// ����Ĺ��г�Ա
	void eat() {
		cout << "Animal eats food." << endl;
	}

	void sleep() {
		cout << "Animal sleeps." << endl;
	}

protected:
	// ������ܱ�����Ա
	string color;
};

// ������
class Dog : public Animal {
public:
	// ������Ĺ��г�Ա
	void bark() {
		cout << "Dog barks." << endl;
	}

	void setColor(string clr) {
		color = clr; // ���ʻ�����ܱ�����Ա
	}

	void displayColor() {
		cout << "Dog's color is: " << color << endl;
	}
};
void test_1()
{
	Dog myDog;

	// ���û���ĳ�Ա����
	myDog.eat();
	myDog.sleep();

	// ����������ĳ�Ա����
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

// ���
class M
{
	int _m;
};

class N
{
	M _mm;
	int _n;
};
//�̳б�ʾ "��һ����is-a��" ��ϵ,��ϱ�ʾ "��һ����has-a��" ��ϵ��

int main()
{
	Student s("����");
	test_1();
	return 0;
}