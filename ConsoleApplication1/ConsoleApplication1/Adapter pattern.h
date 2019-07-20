#pragma once
#include <string>
#include <iostream>

using namespace std;

class ThreePinPlus //���е���
{
public:
	ThreePinPlus();
	~ThreePinPlus();
	void doThreePinPlus();
};

class TwoPinPlus //��Ҫʵ�ֵĽӿ�
{
public:
	TwoPinPlus();
	~TwoPinPlus();
	virtual void doTwoPinPlus() = 0;  //����
};

class PlusCovertor:public TwoPinPlus  //��������
{
public:
	PlusCovertor(ThreePinPlus *pThreePinPlus); //���ĳ���������䣬����һ������
	~PlusCovertor();
	void doTwoPinPlus()
	{
		doCover(); //��һЩת�����乤��
		m_pThreePinPlus->doThreePinPlus();
	}
	void doCover();
private:
	ThreePinPlus* m_pThreePinPlus;
};
