#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf() {cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";}
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf() override {cout << "D1::vf()\n";}
	void f() {cout << "D1::f()\n";}
};

class D2 : public D1
{
public:
	void pvf() override {cout << "D2::pvf()\n";}
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	string s = "valami";
	void pvf() override {cout << s << endl;}
};

class D22 : public B2
{
public:
	int i = 37;
	void pvf() override {cout << i << endl;}

};

void f (B2& b)
{
	b.pvf();
}

int main()
{
	/*
	//B1 object
	B1 b;
	b.vf();
	b.f();

	//D1 object
	D1 d;
	d.vf();
	d.f();

	//B1 reference
	B1& ref {d};
	ref.vf();
	ref.f();
	*/

	//D2 object
	D2 dd;
	dd.vf();
	dd.f();
	dd.pvf();

	//call f with D21 and D22 object
	D21 huszonegy;
	D22 huszonketto;

	f(huszonegy);
	f(huszonketto);


	return 0;
}