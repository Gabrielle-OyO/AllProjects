/*假设在一个学校管理系统中有学生类Student、教师类Teacher和职员类Staff，
现在要把这三个类的对象连接在一个链表中，既要构成一个异质链表。
要求各类人员的信息都放在链表中，并能实现删除信息和输出每个人的信息。
*/

/*
基本信息包括：
学生：姓名、年龄、入学成绩
教师：姓名、年龄、职称
职员：姓名、年龄、业绩评级
*/

#include<iostream>
using namespace std;

class DLinList;
class Person						//基类Person
{
	friend class DLinLins;
protected:
	const char name[10];					//name
	int age;						//age
	Person* next;					//next node pointer
	static Person* point;			//static基类指针
public:
	Person(const char* nm, int ag);
	~Person(void) {}
	virtual void CreatNode(void) {};	//空的虚函数
	virtual void Print(void);			//虚函数
};

Person::Person(const char* nm, int ag)
{
	strcpy(name, nm);
	age = ag;
	next = NULL;
}

void Person::Print(void)
{
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
}

class student :public Person		//派生类student
{
private:
	float score;					//学习成绩
public:
	student(char* nm, int ag, float sc) :Person(nm, ag) { score = sc; }
	~student(void) {}
	void CreatNode(void);			//虚函数
	void Print(void);				//虚函数
};

void student::CreatNode(void)
{
	point = new student(name, age, score);
}

void student::Print(void)
{
	Person::Print();
	cout << "入学成绩：" << score << endl << endl;
}

class teacher :public Person
{
private:
	char position[15];
public:
	teacher(const char* nm, int ag, char* pos) :Person(nm, ag) { strcpy(position, pos); }
	~teacher(void) {}
	void CreatNode(void);
	void Print(void);
};

void teacher::CreatNode(void)
{
	point = new teacher(name, age, position);
}
void teacher::Print(void)
{
	Person::Print();
	cout << "职称：" << position << endl << endl;
}

class Staff :public Person
{
private:
	char Comment;
public:
	Staff(const char* nm, int ag, char cm) :Person(nm, ag) { Comment = cm;}
	~Staff(void) {}
	void CreatNode(void);
	void Print(void);
};

void Staff::CreatNode(void)
{
	point = new Staff(name, age, Comment);
}

void Staff::Print(void)
{
	Person::Print();
	cout << "业绩评级：" << Comment << endl << endl;
}
class DLinList
{
private:
	Person* head;
	int size;
public:
	DLinList(void) :head(NULL), size(0) {}
	~DLinList(void);
	Person* Indext(int pos)const;
	void Insert(Person* p, int pos);
	void Delete(int pos);
	void Print(void);
};

DLinList::~DLinList(void)
{
	Person* curr, * prev;
	curr = head;
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}
	size = 0;
}

Person* DLinList::Index(int pos)const
{
	if (pos<-1 || pos>size)
	{
		cout << "参数pos越界出错！" << endl;
		exit(1);
	}
	if (pos == -1)return head;
	Person* curr = head;
	int i = 0;
	while (curr != NULL && i < pos)
	{
		curr = curr->next;
		i++;
	}
	return curr;
}
void DLinList::Insert(Person* p, int pos)
{
	if (pos<0 || pos>size)
	{
		cout << "参数pos越界出错!" << endl;
		exit(1);
	}
	Person* prev = Index(pos - 1);
	p->CreatNode();
	if (pos == 0)
	{
		Person::point->next = head;
		head = Person::point;
	}
	size++;
}

void DLinList::Delete(int pos)
{
	if (pos<0 || pos>size)
	{
		cout << "参数pos越界出错!" << endl;
		exit(1);
	}
	Person* kill;
	Person* prev = Index(pos - 1);
	if (pos == 0)
	{
		kill = prev;
		head = head->next;
	}
	else
	{
		kill = prev->next;
		prev->next = prev->next->next;
	}
	delete kill;
	size--;
}
void DLinList::Person(void)
{
	Person* curr = head;
	while (curr != NULL)
	{
		curr->Print();
		curr = curr->next;
	}
}

Person* Person::point = NULL;
void main(void)
{
	DLinList personList;
	student stud1("aaa", 20, 99);
	teacher teac1("ddd", 89, "jiaoh dhaoh");
	teacher teac2("jjj", 89, "jainghi dhofhu");
	Staff staf1("ooo", 45, 'A');
	personList.Insert(&stud1, 0);
	personList.Insert(&teac1, 1);
	personList.Insert(&teac2, 2);
	personList.Insert(&staf1, 3);
	personList.Delete(2);
	personList.Print();

}