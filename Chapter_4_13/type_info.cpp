
#if 1
#include <iostream>

class Toy
{
public:
	virtual ~Toy() {};
};

class Car : public Toy
{
public:
	int value;
};

class Doll : public Toy
{
public:
	int value;
};

int main()
{
	Toy* car = new Car();
	Toy* doll = new Doll();

	const type_info& t1 = typeid(*car);
	const type_info& t2 = typeid(*doll);

	std::cout << t1.name() << std::endl;
	std::cout << t2.name() << std::endl;
}

#endif

#if 0
#include <iostream>

class Toy
{
public:
	virtual ~Toy() {};
	virtual void foo() {}
};

class Car : public Toy
{
public:
	int value;
	virtual void foo() {}
};

class Doll : public Toy
{
public:
	int value;
	virtual void foo() {}
};

int main()
{
	Toy* car = new Car();
	Toy* doll = new Doll();

	const type_info& t1 = typeid(*car);
	const type_info& t2 = typeid(*doll);

	std::cout << t1.name() << std::endl;
	std::cout << t2.name() << std::endl;
}
#endif