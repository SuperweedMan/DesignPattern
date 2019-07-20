#pragma once
#include <string>
#include <iostream>

using namespace std;

class ThreePinPlus //已有的类
{
public:
	ThreePinPlus();
	~ThreePinPlus();
	void doThreePinPlus();
};

class TwoPinPlus //想要实现的接口
{
public:
	TwoPinPlus();
	~TwoPinPlus();
	virtual void doTwoPinPlus() = 0;  //两脚
};

class PlusCovertor:public TwoPinPlus  //适配器类
{
public:
	PlusCovertor(ThreePinPlus *pThreePinPlus); //针对某个对象适配，不是一整个类
	~PlusCovertor();
	void doTwoPinPlus()
	{
		doCover(); //做一些转换适配工作
		m_pThreePinPlus->doThreePinPlus();
	}
	void doCover();
private:
	ThreePinPlus* m_pThreePinPlus;
};
