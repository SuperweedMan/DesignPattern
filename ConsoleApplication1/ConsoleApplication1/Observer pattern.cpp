#include <iostream>
#include <string>
#include <list>

using namespace std;


class Subject //Ŀ�� ����
{
public:
	virtual void attach(Observe*)=0;
	virtual void detach(Observe*)=0;
	virtual void notify() = 0;
};

class Subject_1 :public Subject
{
private:
	list<Observe*> m_ObserverList;
public:
	void attach(Observe* pObserver) { m_ObserverList.push_back(pObserver); }
	void detach(Observe* pObserver) { m_ObserverList.remove(pObserver); }
	void notify();

	string fun()
	{
		return "subject_1";
	}
};

void Subject_1::notify()
{
	std::list<Observe*>::iterator it = m_ObserverList.begin();
	while (it != m_ObserverList.end())
	{
		(*it)->update(this);
		++it;
	}
}

class Observe
{
public:
	virtual void update(Subject*) = 0; //ˢ�º��� ���������ʵ������ָ�룬�������ֻ���ø���
};

class Observe_1 :public Observe //����۲�����Ҫ֪��Ҫ�۲�Ķ���
{
public:
	Observe_1() {}
	void update(Subject* psubject)//ͳһ�Ǹ���
	{
		Subject_1 *p = static_cast<Subject_1*>(psubject);  //ǿ������ת��
		cout << "Observer_1 get the update. "  << p->fun()<<endl;
	}
};

class Observe_2 :public Observe
{
public:
	Observe_2() {} //��ָ�룬��ȡ��������
	void update(Subject* psubject)//ͳһ�Ǹ���
	{
		Subject_1* p = static_cast<Subject_1*>(psubject);  //ǿ������ת��
		cout << "Observer_2 get the update. " << p->fun() << endl;
	}
};



int main()
{
	Subject_1* psubject = new Subject_1();
	
	Observe* pobserve1 = new Observe_1();
	Observe* pobserve2 = new Observe_2();

	psubject->attach(pobserve1);
	psubject->attach(pobserve2);
	psubject->notify();
	return 0;


}

