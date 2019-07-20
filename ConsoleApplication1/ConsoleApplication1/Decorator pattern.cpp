#include <iostream>
#include <string>

using namespace std;

const int ESPRESSO_PRICE = 20;
const int DRAKROAST_PRICE = 20;
const int MOCHA_PRICE = 10;
const int WHIP_PRICE = 8;

class Beverage  //���ϻ��� �޷�ʵ��
{
public:
	Beverage() {};
	~Beverage() {};
	virtual string getDescription()
	{
		return description;
	}
	virtual int cost() = 0;
protected:
	string description;
};

class CondimentDecorator:public Beverage  //��ζƷװ���� û�г�ʼ�� �޷�ʵ��
{
protected:
	Beverage *beverage; //�ؼ�ָ�� ����
};

class Espresso:public Beverage //����װ�εĻ��� ���󿧷�
{
public:
	Espresso() 
	{
		description = "espresso";	
	}
	~Espresso() {};
	int cost()
	{
		return ESPRESSO_PRICE;
	}
private:

};

class DarkRoast:public Beverage //�ڿ���
{
public:
	DarkRoast() 
	{
		description = "darkroast";
	}
	~DarkRoast() {};
	int cost()
	{
		return DRAKROAST_PRICE;
	}
private:

};

class Mocha:public CondimentDecorator
{
public:
	Mocha(Beverage *beverage)
	{
		this->beverage = beverage;
	}
	~Mocha() {};
	string getDescription()
	{
		return beverage->getDescription() + ",mocha";
	}
	int cost()
	{
		return beverage->cost() + MOCHA_PRICE;
	}
};

class Whip:public CondimentDecorator
{
public:
	Whip(Beverage * beverage)
	{
		this->beverage = beverage;
	}
	~Whip() {};
	string getDescription()
	{
		return beverage->getDescription() + ",wipe";
	}
	int cost()
	{
		return beverage->cost() + WHIP_PRICE;
	}

};

int main()
{
	Beverage* beverage = new DarkRoast();
	beverage = new Whip(beverage);
	beverage = new Mocha(beverage);
	beverage = new Whip(beverage);
	cout<< beverage->getDescription()<<endl;
	return 0;

}