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
	Command* pcommand1 = new ConcreteCommand(preceiver); //第一个命令
	Command* pcommand2 = new ConcreteCommand(preceiver);//第二个命令，实际运用中是不同的实际命令与不同的接受对象
	Invoker* pinvoker = new Invoker();

	pinvoker->setCommand(pcommand1); //客户端需要操作的，输入命令以及执行，不清楚谁来执行
	pinvoker->setCommand(pcommand2);
	pinvoker->excuteCommand();
	return 0;
}