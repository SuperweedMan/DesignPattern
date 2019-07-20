#include <iostream>
#include <string>

using namespace std;

class Singleton
{
private:
	int t = 0;
	Singleton() {};
public:
	int getT()
	{
		this->t++;
		return this->t;
	}
	static Singleton* getInstance()
	{
		static Singleton* m_pInstance;
		if (m_pInstance == NULL)
		{
			m_pInstance = new Singleton();
		}
		return m_pInstance;
	}
};

int main()
{
	Singleton* psingleton = Singleton::getInstance();
	Singleton* psingleton1 = Singleton::getInstance();
	cout << psingleton << endl;
	cout << psingleton1 << endl;
	return 0;
}