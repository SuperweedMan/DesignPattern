#include "Command pattern.h"

Command::Command()
{
}

Command::~Command()
{
}


Receiver::Receiver()
{
}

Receiver::~Receiver()
{
}

ConcreteReceiver::ConcreteReceiver()
{
}

ConcreteReceiver::~ConcreteReceiver()
{
}

void ConcreteReceiver::action()
{
	cout << "Action number 1." << endl;
}

ConcreteCommand::ConcreteCommand(Receiver *pReceiver)
{
	this->m_pReceiver = pReceiver;
}

ConcreteCommand::~ConcreteCommand()
{
}

void ConcreteCommand::excute()
{
	m_pReceiver->action();
}

Invoker::Invoker()
{
}

Invoker::~Invoker()
{
}

void Invoker::setCommand(Command *pcommand)
{
	cmds.push_back(pcommand);
}

void Invoker::cancleCommand(Command *pcommand)
{
	cmds.remove(pcommand);
}

void Invoker::excuteCommand()
{
	list<Command*>::iterator item = cmds.begin();
	while (item != cmds.end())
	{
		(*item)->excute();
		item++;
	}
}

int main()
{
	Receiver* preceiver = new ConcreteReceiver();
	Command* pcommand1 = new ConcreteCommand(preceiver); //��һ������
	Command* pcommand2 = new ConcreteCommand(preceiver);//�ڶ������ʵ���������ǲ�ͬ��ʵ�������벻ͬ�Ľ��ܶ���
	Invoker* pinvoker = new Invoker();

	pinvoker->setCommand(pcommand1); //�ͻ�����Ҫ�����ģ����������Լ�ִ�У������˭��ִ��
	pinvoker->setCommand(pcommand2);
	pinvoker->excuteCommand();
	return 0;
}