//g++ drill15_class.cpp -o a2.out
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Person{
	private:	
		//string n;
		string f;
		string l;
		int a;
		
	public:
		Person(){};
		//Person(string n, int a): n{n}, a{a}{
		Person(string fn, string ln, int ag) : f{fn}, l{ln}, a{ag}{
			if ( a < 0 || a >= 150){
				throw runtime_error("Invalid age");
			}
			string n=f+l;
			for (char c : n ){
				switch(c){
					case';':
					case':':
					case'"':
					case'\'':
					case'[':
					case']':
					case'*':
					case'&':
					case'^':
					case'%':
					case'$':
					case'#':
					case'@':
					case'!': runtime_error("Invalid character");
					
					default: break;
			}
			
		}
		};
		//string getName() const { return n;}
		string getFirst() const { return f;}
		string getLast() const { return l;}
		int getAge() const {return a;}
		
	
};

istream& operator>>(istream& is, Person& p){
			//string n;
			string f;
			string l;
			int a;
			is >> f >> l >> a;
			
			p = Person(f, l, a);
			return is;
		}
ostream& operator<<(ostream& os, Person& p){
			return os << p.getFirst() << ' ' << p.getLast() << " Age:" << p.getAge();
		}

int main(){
	
	Person p;
	p = Person("Goofy", "Goof", 63);
	//p.n="Goofy";
	//p.a=63;
	cout << p.getFirst() << ' ' << p.getLast() << " is " << p.getAge() << " years old" <<endl;
	
	Person p2;
	cout << "Enter a second person and their age" <<endl;
	cin >> p2;
	cout << p2 << endl;
	cout << "Enter a first and a last name, and an age to add to the list. Otherwise, enter \"stop\"" << endl;
	vector<Person> vec;
	for (Person p; cin>>p;){
		if(p.getFirst() == "stop") break;
		vec.push_back(p);
	}	
	for (Person p: vec){
		cout << p << endl;
	}

	

}

