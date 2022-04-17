#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
	cout<<"sizeof: \n";
	cout<<"char\t" << sizeof(char) <<"\n";
	cout<<"short\t" << sizeof(short) <<"\n";
	cout<<"int\t" << sizeof(int) <<"\n";
	cout<<"long\t" << sizeof(long) <<"\n";
	cout<<"float\t" << sizeof(float) <<"\n";
	cout<<"double\t" << sizeof(double) <<"\n";
	cout<<"int*\t" << sizeof(int*) <<"\n";
	cout<<"double*\t" << sizeof(double*) <<"\n";
	cout<<"float*\t" << sizeof(float*) <<"\n";
	cout<<"long*\t" << sizeof(long*) <<"\n";
	
	cout<<"\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);
	cout<<"1D int, 10 elements \t\t"<<sizeof(a)<<'\n';
	cout<<"1D int, 100 elements \t\t"<<sizeof(b)<<'\n';
	cout<<"1D double, 10 elements \t\t"<<sizeof(c)<<'\n';
	cout<<"2D int, 10x10 elements \t\t"<<sizeof(d)<<'\n';
	cout<<"3D int, 10x10x10 elements \t"<<sizeof(e)<<'\n'; //A szerző dinamikus memóriakezelést használ
	
	cout<<"\nNumber of elements:\n";
	cout<<"a:\t"<<a.size() <<'\n';
	cout<<"b:\t"<<b.size() <<'\n';
	cout<<"c:\t"<<c.size() <<'\n';
	cout<<"d:\t"<<d.size() <<'\n';
	cout<<"e:\t"<<e.size() <<'\n';
	
	cout<<"\nTask #4 begins here\n";
	cout<<"Input numbers to calculate their square root!\n";
	double input;
	while(cin){
		cin>> input;
		if (input<0){
			cout<<"No square root\n";
			break;
		}
		cout<<'\t'<<sqrt(input)<<'\n';
	}
	/* Tanár megoldása. Az enyém is teljesen jó, sőt könnyebb védeni
	int i;
	cout<<"\n Enter ints: ";
	while(cin>>i){
		errno=0;
		double d=sqrt(i);
		if(errno==EDOM)
			cout<<"No square root\n";
		else
			cout<<"sqrt(" << i <<") = "<< d << '\n';
	}	*/
	
	
	cin.clear();
	cin.ignore();
	cout<<"\nEnter 10 floating point values: \n";
	Matrix<double> m2(10);
	double d2;
	for (int i=0; i<m2.size(); i++){
		cin>>d2;
		if (!cin) throw runtime_error("Problem reading from cin");
		m2[i]=d2;
		
	}
	cout<<"Matrix: \n"<<m2<<'\n';
	cout<<"\nMultiplication table\nEnter n: ";
	int n;
	cin>>n;
	int m;
	cout<<"\nEnter m: ";
	cin>>m;
	
	Matrix<int, 2> mtable(n, m);
	
	for(Index i=0; i< mtable.dim1(); ++i){
		for(Index j=0; j<mtable.dim2(); ++j){
			mtable(i,j) = (i+1)*(j+1);
			cout<<setw(5)<<mtable(i,j);
		}
		cout<<'\n';
	}
	
	Matrix<complex<double>> m3(10);
	cout<<"\nEnter 10 complex numbers (Re, Im): ";
	complex<double>comp;
	for(int i=0; i<10; i++){
		cin>> comp;
		if (!cin) throw runtime_error("Problem reading complex number!");
		m3[i]=comp;
	}
	complex<double> sum;
	for(Index i=0; i<m3.size(); i++){
		sum+=m3[i];
	}
	cout<<"Sum: "<<sum<<'\n';
	//Házifeladat: a drill utolsó feladata!
	//Használni kell a mátrix () operátorát, a sor/oszlop elem eléréséhez
	cout<<"\nInput 6 integers\n";
	Matrix<int,2> m4(2,3);
	int input2=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cin>>input2;
			if (!cin) throw runtime_error("Problem reading from cin");
			m4(i,j)=input2;
			cout<<setw(5)<<m4(i,j);
		}
		cout<<'\n';
	}
} 
catch(exception& e) {
	cerr<< "Exception: " << e.what() <<'\n';
	return 1;
} catch(...) {
	cerr<<"Unknown exception\n";
	return 2;
}
