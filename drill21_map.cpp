// A vektorokat egyelőre kihagjyuk, majd otthon meg kell csinálni
#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>

void read_map(std::map<std::string, int>& m){
	std::string s;
	int i=0;
	
	while(m.size()<10){
		std::cin>> s >> i;
		//m[s] = i;
		m.insert(std::make_pair(s,i));
	}
}

template <typename K, typename V>
void print(const std::map<K,V>& m){
	for(auto& a : m){
		std::cout << a.first <<'\t' << a.second << std::endl ;
	}

}

template <typename K, typename V>
void sum(const std::map<K, V>& m){
	int sum=0;
	for(auto& a : m){
		sum=sum+(int)(a.second);
	}
	std::cout<<"The sum of the map elements is: " << sum << std::endl;
	
	/*int total=std::accumulate(msi.begin(), msi.end(), 0, [](int sum, const std::pair<std::string, int>& p)
	{ 
	return sum+=p.second;
	});
	
	//total=std::accumulkate(msi.begin(), msi.end(), 0);
	int total=0;
	for(std::pair<std::string, int> a : msi){
		total2 += a.second;
	}
	std::cout<<"Sum of ints: " <<total << " " << total2 << std::endl;*/
}


int main(){
try{
	std::map<std::string, int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 45;
	msi["x"] = 23;
	msi["g"] = 41;
	msi["wert"] = 292;
	msi["j"] = 31;
	msi["po"] = 11;
	msi["px"] = 67;
	msi["ac"] = 4;		//A map mindig rendezett, attól függetlenül, hogy milyen sorrendben adtunk hozzá elemeket
	msi["a"] = 1; 		//A legelső érték felülírva
	print(msi);
	msi.erase("a");
	std::cout<<std::endl<<"Az elem törlése után: " << std::endl;
	print(msi);
	msi.erase(msi.begin(),msi.end());
	std::cout<<std::endl<<"Teljes törlés után: " << std::endl;
	print(msi);
	
	std::cout<<"10 név érték pár megadása: " << std::endl;
	read_map(msi);
	std::cout<<std::endl<<"msi: " << std::endl;
	print(msi);
	sum(msi);
	
	std::map<int, std::string> mis;
	for (std::pair<std::string, int> a : msi){
		//mis[a.second] = a.first;
		mis.insert(std::make_pair(a.second, a.first));
	}
	std::cout<<std::endl<<"mis map: "<<std::endl;
	print(mis);
	
}
catch (std::exception& e){
	std::cerr<<"Exception: " <<e.what() << '\n';
	return 1;
}	
catch (...){
	std::cerr<<"Exception" << '\n';
	return 2;
}


}

