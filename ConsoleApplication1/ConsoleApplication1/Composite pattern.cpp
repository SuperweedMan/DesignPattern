#include "Composite pattern.h"

Component::Component()
{
}

Component::~Component()
{
}

Composite::Composite()
{
}

Composite::~Composite()
{
}

void Composite::add(Component *pComponent)
{
	m_leafs.push_back(pComponent);
}

void Composite::operateFun()
{
	cout << "节点的操作\r\n" << endl;
	vector<Component*>::iterator item = m_leafs.begin();
	for (; item != m_leafs.end(); item++)
	{
		cout << "------------" << endl;
		(*item)->operateFun();
	}
}

Leaf::Leaf()
{
}

Leaf::~Leaf()
{
}

void Leaf::operateFun()
{
	cout << "叶节点的操作\r\n" << endl;
}

int main()
{
	Component* pLeaf1 = new Leaf();
	Component* pLeaf2 = new Leaf();
	Composite* pComposite1 = new Composite();
	Composite* pComposite2 = new Composite();
	pComposite1->add(pLeaf1);
	pComposite1->add(pLeaf2);
	pComposite2->add(pComposite1);
	pComposite2->operateFun();
	return 0;
}