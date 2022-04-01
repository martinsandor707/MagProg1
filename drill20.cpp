#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <array>
#include <string>

template <typename C> 
const void print_contents(const C& c){
	for(auto& a : c) std::cout<<a<<' ';
	std::cout<<std::endl;
}

template<typename C>
void inc(C& c, int n){
	for(int& a : c) a=a+n;
	
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p=f1; p!=e1; ++p){
		*f2=*p;
		f2++;
	}
	return f2;
} 

int main(){
try{
	constexpr int size=10;
	/*int arr[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> vec{0,1,2,3,4,5,6,7,8,9};
	list<int> lis= {0,1,2,3,4,5,6,7,8,9}; // Regular list implemented as a doubly-linked list	cppreference.com for documentation
	*/
	
	int arr[size];
	for(int i=0; i< size; ++i) arr[i]=i;
	
	std::array<int,size> ai;
	std::copy(arr,arr+size, ai.begin());
	
	std::vector<int> vi(size);
	std::list<int> li(size);
	std::copy(arr, arr+size, li.begin());
	
	std::array<int,size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	std::cout<<"\n";
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	std::cout<<"New Array's contents: \n";
	print_contents(ai2);
	std::cout<<"\nNew Vector's contents: \n";
	print_contents(vi2);
	std::cout<<"\nNew list's contents: \n";
	print_contents(li2);

	std::vector<int>::iterator vit;
	vit=std::find(vi2.begin(), vi2.end(), 3);
	std::cout<<"\nIs the number 3 in the new vector? \n";	
	if(vit !=vi2.end()){
		std::cout<<"Found at: " << std::distance(vi2.begin(), vit) << std::endl;
	}
	else{
	std::cout<<"Not found"<< std::endl;
	}	
		//HF: Megnézni, hogy a a lista tartalmazza-e a 27-es értéket, és ha igen, hol.
	
	std::cout<<"\nIs the number 27 in the new list? \n";
	std::list<int>::iterator lit;
	lit=std::find(li2.begin(), li2.end(), 27);
		
	if(lit !=li2.end()){
		std::cout<<"Found at: " << std::distance(li2.begin(), lit) << std::endl;
	}
	else{
	std::cout<<"Not found"<< std::endl;
	}
	
	return 0;
}	
	
catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << '\n';
	return 2;
}	

catch(...){
	std::cerr << "Unknown error\n";
	return 2;
}		
	
} 	
