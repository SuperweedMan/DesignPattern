#include <iostream>
#include <string>

using namespace std;

const int ESPRESSO_PRICE = 20;
const int DRAKROAST_PRICE = 20;
const int MOCHA_PRICE = 10;
const int WHIP_PRICE = 8;

class Beverage  //饮料基类 无法实例
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

class CondimentDecorator:public Beverage  //调味品装饰器 没有初始化 无法实例
{
protected:
	Beverage *beverage; //关键指针 回溯
};

class Espresso:public Beverage //不可装饰的基类 蒸馏咖啡
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

class DarkRoast:public Beverage //黑咖啡
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