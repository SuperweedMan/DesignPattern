#include <iostream>
#include <string>

using namespace std;



class Product_A
{
public:
	Product_A() {};
	~Product_A() {};
	void set_a(int _a) { a = _a; }
	void set_b(int _b) { b = _b; }
	int get_a(void) { return a; }
	int get_b(void) { return b; }
private:
	int a=0;
	int b=0;
};


class AbstractBuilder 
{
public:
	virtual void buildProductA() = 0;
	virtual Product_A* getProduct() = 0;
};

class ProductABuilder :public AbstractBuilder
{
private:
	Product_A* pProduct_A;
public:
	ProductABuilder()
	{
		pProduct_A = new Product_A;
	}
	void buildProductA()
	{
		pProduct_A->set_a(12);
		pProduct_A->set_b(23);
	}
	Product_A* getProduct()
	{
		return pProduct_A;
	}
};

class Designer
{
private:
	AbstractBuilder* pAbstractBuilder;
public:
	Designer(AbstractBuilder *p)
	{
		pAbstractBuilder = p;
	}
	Product_A* establish()
	{
		pAbstractBuilder->buildProductA();
		return pAbstractBuilder->getProduct();
	}

};
int main()
{
	ProductABuilder* pProductAaBuilder = new ProductABuilder;
	Designer* pDesigner = new Designer(pProductAaBuilder);
	Product_A* pProduct_A= pDesigner->establish();
	cout << pProduct_A->get_a() << endl;
}