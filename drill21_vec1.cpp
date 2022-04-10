#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct Item{
	public:
		string name;
		int iid;
		double value;
		Item(string n, int i, double v): name{n}, iid{i}, value{v} {}
};

ostream& operator<<(ostream& os, const Item& t){
		os << t.name <<"\t" << t.iid << '\t'<< t.value;
		return os;
}

struct Item_cmp{
	bool operator() ( const Item a, const Item b){
	return a.name < b.name; 	//sort by name
	//return a.iid < b.iid; 	//sort by iid
	//return a.value < b.value;	//sort by value
	}
	
};

template<typename C>
void print(const C& c, char sep='\n'){
	cout<<"Container elements: \n";
	for (const auto elem : c){
		cout<<elem<<sep;
	}
	cout<<endl;
}

int main()
try{
	cout<<"---------- THE VECTOR BEGINS HERE ----------\n";
	vector<Item> vi {
	Item{"Shoe", 1, 30.0},
	Item{"Flower", 2, 5.25},
	Item{"Hat", 200, 20.1},
	Item{"Candy", 9, 3.9},
	Item{"Balloon", 7, 2.65},
	Item{"Ball", 11, 10.2},
	Item{"Cookies", -30, 15.0},
	Item{"Flower", 2, 5},
	Item{"Ferrari", 1000, 300000.99},
	Item{"Tape", 0, -4000.78},
	};
	print(vi);
	
	sort(vi.begin(), vi.end(),Item_cmp());
	cout<<"After sorting by name: \n";
	print(vi);

	vi.push_back(Item("horse",99, 12.34));
	vi.push_back(Item("Canon",9988, 499.95));
	cout<<"After adding horse shoe and Canon S400: \n";
	print(vi);
	
	vector<Item>::iterator ptr;
	string nameKey="Ball";
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->name==nameKey) break;
	}
	vi.erase(ptr);
	nameKey="Hat";
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->name==nameKey) break;
	}
	vi.erase(ptr);
	cout<<"After removing Ball and Hat : \n";
	print(vi);
	
	int iidKey=9;
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->iid==iidKey) break;
	}
	vi.erase(ptr);
	iidKey=7;
	for(ptr=vi.begin(); ptr < vi.end(); ptr++){
	if(ptr->iid==iidKey) break;
	}
	vi.erase(ptr);
	cout<<"After removing iid 9 and 7 : \n";
	print(vi);
	cout<<"---------- THE LIST BEGINS HERE ----------\n";
	list<Item> li {
	Item{"Shoe", 1, 30.0},
	Item{"Flower", 2, 5.25},
	Item{"Hat", 200, 20.1},
	Item{"Candy", 9, 3.9},
	Item{"Balloon", 7, 2.65},
	Item{"Ball", 11, 10.2},
	Item{"Cookies", -30, 15.0},
	Item{"Flower", 2, 5},
	Item{"Ferrari", 1000, 300000.99},
	Item{"Tape", 0, -4000.78},
	};
	print(li);
	
	li.sort(Item_cmp());
	cout<<"After sorting by name: \n";
	print(li);

	li.push_back(Item("horse",99, 12.34));
	li.push_back(Item("Canon",9988, 499.95));
	cout<<"After adding horse shoe and Canon S400: \n";
	print(li);
	
	 
	nameKey="Ball";
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->name==nameKey) {
		li.erase(ptr2);
		break; 
		}
	}
	
	nameKey="Hat";
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->name==nameKey) {
		li.erase(ptr2);
		break;
		}
	}
	
	cout<<"After removing Ball and Hat : \n";
	print(li);
	
	iidKey=9;
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->iid==iidKey) {
		li.erase(ptr2);
		break;
		}
	}
	iidKey=7;
	for(list<Item>::iterator ptr2=li.begin(); ptr2 != li.end(); ptr2++){
	if(ptr2->iid==iidKey) {
		li.erase(ptr2);
		break;
		}
	}
	cout<<"After removing iid 9 and 7 : \n";
	print(li);
}
catch(exception& e) {
	cerr<<e.what()<<'\n';
	return 1;
}catch(...) {
	cerr<<"Unknown exception";
	return 2;
}
