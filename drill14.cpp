
#include <string>
#include <iostream>

using namespace std;

class B1{
	public:
		virtual void vf() {cout <<"B1::vf()"<<endl;} //a virtual kulcsszó annyit jelent, hogy a függvény később felül lesz írva, hasznos a hivatkozásoknál, lást 27. sor
		void f() {cout <<"B1::f()"<<endl;}
		virtual void pvf()=0; //Így jelezzük c++ specifikusan, hogy tisztán virtuális függvény, azaz absztrakt, így ha B1 típusú osztályt példányosítunk, hibát kapunk
};

class D1 : public B1{	//Ha ide protectedet írunk, akkor legfeljebb protected lehetne, public --> protected, private --> private
	public:
		virtual void vf() {cout <<"D1::vf()"<<endl;}
		void f() {cout <<"D1::f()"<<endl;}	//Ha nem implementáljuk valahogyan B1 pvf() függvényét, akkor ez az osztály is absztrakt lesz
};

class D2 : public D1{
	public:
		void pvf(){cout<<"D2::pvf()"<<endl;} //mivel adtunk végre értelmet a pvf()-nek, így lehet példányosítani D2-t
};

class B2{	//absztrakt
	public:
		virtual void pvf()=0; //tisztán virtuális
};


class D21 : public B2{
	public:
		string s;
		void pvf(){cout << s << endl;}
};

class D22 : public B2{
	public:
		int n;
		void pvf(){cout << n << endl;}
};

void f(B2& b2){ b2.pvf();}

int main(){
	/*B1 b1; //osztály és példány/objektum
	b1.vf();
	b1.f();*/
	
	/*D1 d1;
	d1.vf();
	d1.f();
	d1.f();
	d1.f();
	d1.f();
	B1& b1ref=d1; //Az ősosztályba be tudjuk csomagolni a leszármazott osztályokat is --> Kollekcióknál fontos, hogy megmaradjanak az osztályspecifikus tulajdonságok
	b1ref.vf();	//d1::vf()
	b1ref.f();	//b1::f()
	
	D2 d2;
	d2.pvf();*/
	D21 d21;
	d21.s="d21.s";
	d21.pvf();
	D22 d22;
	d22.n=22;
	d22.pvf();
	f(d21);		//a leszármazott osztályok felhasználhatók az ősök helyében
	f(d22);
}
