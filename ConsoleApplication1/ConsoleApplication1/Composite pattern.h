#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component
{
public:
	Component();
	~Component();
	virtual void operateFun() = 0;
private:

};

class Composite:public Component
{
public:
	Composite();
	~Composite();
	void add(Component* pComponent);
	void operateFun();
private:
	vector<Component*> m_leafs;
};

class Leaf:public Component
{
public:
	Leaf();
	~Leaf();
	void operateFun();
private:

};


