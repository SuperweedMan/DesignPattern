#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Receiver //具体对象的抽象层，为了能统一注册某个concrete command
{
public:
	Receiver();
	~Receiver();
	virtual void action() = 0;
private:

};

class Command
{
public:
	Command();
	~Command();
	virtual void excute() = 0;
private:
	Receiver* m_pReceiver;
};



class ConcreteReceiver:public Receiver
{
public:
	ConcreteReceiver();
	~ConcreteReceiver();
	void action();
private:

};

class ConcreteCommand:public Command
{
public:
	ConcreteCommand(Receiver *pReceiver);
	~ConcreteCommand();
	void excute();
private:
	Receiver* m_pReceiver;
};

class Invoker
{
public:
	Invoker();
	~Invoker();
	void setCommand(Command *pcommand);
	void cancleCommand(Command *pcommand);
	void excuteCommand();
private:
	list<Command*> cmds;
};

