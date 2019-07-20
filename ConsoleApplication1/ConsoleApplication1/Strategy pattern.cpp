#include <iostream>
#include <string>

using namespace std;

class Strategy
{
public:
	virtual void concreteStrategy() = 0;
};

class Strategy_1:public Strategy
{
public:
	void concreteStrategy()
	{
		cout << "this is strategy 1!" << endl;
	}
};

class Strategy_2 :public Strategy
{
public:
	void concreteStrategy()
	{
		cout << "this is strategy 2!" << endl;
	}
};

class Contex
{
public:
	Contex(Strategy* strategy) { this->_strategy = strategy; }
	~Contex() { delete this->_strategy; }
	void doAction() { this->_strategy->concreteStrategy(); }
private:
	Strategy* _strategy;
};
int main()
{
	Contex* p = new Contex(new Strategy_1);
	p->doAction();
	p = new Contex(new Strategy_2);
	p->doAction();
	return 0;
}
