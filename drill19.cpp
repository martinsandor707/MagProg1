#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T> struct S {
	public:
	S(T vv = 0) : val{vv}{}
	const T& get() const;	//Az első const azt jelenti hogy a T nem változik, a második const pedig azt mondja hogy a függvényben lévő értékek nem változnak
	void set(T newValue){
		val=newValue;
	}
	void operator= (const T&);
	
	private:
	T val;
	
	
};

template<typename T> 
const T& S<T>::get() const{ //Referenciát adunk vissza, hogy később megváltoztathassuk a val értékét a függvénnyel, ha úgy akarjuk
	return val;
}

template <typename T>
void S<T>::operator=(const T& s){
	val=s;
}

template <typename T> void read_val(T& v) {
	cin >> v;
}

template<typename T> 
ostream& operator<<(ostream& os, vector<T> v){
	os << "{ ";
	for(int i=0; i<v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : " ");
	}
	
	os << "}\n";
	return os;
	
	/*string str="";
	for (auto& a: vec.get()){
		str=str+a+' ';
	}
	str=str+'\n';
	
	return os << str;*/
}

template<typename T> 
istream& operator>>(istream& is, vector<T> v)
{
	char ch = 0;
	is >> ch;
	if ( ch !='{'){
		is.unget();
		return is;
	}
	for (T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if ( ch != ',') break;
	}
	
	return is;
	
	/*vector<T> vec2;
	T input;
	while (cin >> input){
		if((char)input == '*') break;
		vec2.push_back(input);
	}
	vec=vec2;
	return is;*/
}

int main(){
	
	S<int> s;
	S<int> si{37};
	S<char> sc{'c'};
	S<double> sd{3.2};
	S<std::string> ss{"hello"};
	S<vector<int>> svi{std::vector<int>{1,1,2,3,5,8}}; //Egy S típusú objektum, aminek a típusparamétere vektor, aminek a típusparamétere int
	cout	<< "S<int> : " << s.get() <<endl
		<< "S<int> : " << si.get() <<endl
		<< "S<char> : " << sc.get() <<endl
		<< "S<double> : " << sd.get() <<endl
		<< "S<string> : " << ss.get() <<endl;
	//<< "S<vector<int>> : " << svi.val <<endl;	//Hiba: vektorra nem értelmezhető a kiíratás alapjáraton
	for (auto& a: svi.get()){
		cout << a << ' ';
	}
	cout << endl;
	
	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;
	
	si=30;
	cout << "S<int> : " << si.get() << endl;

	cout <<"Input an int: "; 
	int ii;
	read_val(ii);
	S<int>si2{ii};
	
	cout <<"\nInput a double: "; 
	int dd;
	read_val(dd);
	S<int>sd2{dd};
	
	cout <<"\nInput a string: "; 
	int str;
	read_val(str);
	
	S<int>ss2{str};
	
	cout	<< "S<int> : " << si2.get() <<endl
		<< "S<double> : " << sd2.get() <<endl
		<< "S<string> : " << ss2.get() <<endl;
	
	cout <<"\nInput a vector: "; 
	vector<int> vec;
	read_val(vec);		//Hiba: vektorra alapjáraton nem értelmezhető a cin >>
	S<vector<int>> svec{vec};
}
