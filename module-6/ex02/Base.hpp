#pragma once
class Base
{
	public:
		virtual ~Base();
};

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};


Base* generate(void);

void identify(Base* basePtr);

void identify(Base& baseRef);
