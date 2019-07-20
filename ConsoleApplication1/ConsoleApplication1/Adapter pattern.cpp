#include "Adapter pattern.h"


using namespace std;

ThreePinPlus::ThreePinPlus() {};
ThreePinPlus::~ThreePinPlus() {};
void ThreePinPlus::doThreePinPlus()
{
	cout << "三脚插头插入" << endl;
}

TwoPinPlus::TwoPinPlus() {};
TwoPinPlus::~TwoPinPlus() {};
void TwoPinPlus::doTwoPinPlus()
{
	cout << "两脚插头插入" << endl;
}


int main()
{
	return 0;
}

