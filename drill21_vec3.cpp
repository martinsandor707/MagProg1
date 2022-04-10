//Házi: Drill első 8 feladata
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
//funktor
class Less_than{
	double v;
	public:
		Less_than(double vv) : v{vv}{}
		bool operator()(const double val) { return val < v;}
};

template<typename C>
void print(const C& c, char sep='\n'){
	std::cout<<"Container elements: \n";
	for (const auto elem : c){
		std::cout<<elem<<sep;
	}
	std::cout<<std::endl;
}

int main()
try{
	const std::string iname{"input_floats.txt"};
	std::ifstream ifs{iname};
	if (!ifs) throw std::runtime_error("Could not read from file: "+iname);
	
	std::vector<double> vd;
	for(double d; ifs>>d;){
		vd.push_back(d);
	}
	print(vd);
	
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(),vd.end(),vi.begin());
	
	for(int i=0 ; i<vd.size() ; i++){
		std::cout<<vd[i]<<'\t' <<vi[i]<<std::endl;
	}
	double vd_sum=std::accumulate(vd.begin(),vd.end(),0.0);
	double vi_sum=std::accumulate(vi.begin(),vi.end(),0.0);
	double difference=vd_sum-vi_sum;

	std::cout<<"The difference between the double and integer vectors: "<<difference<<std::endl;
	/* Ugyanez inner_product függvénnyel
		double diff_sum = std::inner_product(vd.begin, vd.end(), 
		vi.begin(), 0, std::plus<double>(), std::minus<double>());	
	*/	
	std::reverse(vd.begin(), vd.end());
	
	print(vd);
	
	double vd_mean=vd_sum/vd.size();
	
	std::cout<<vd_mean<<std::endl;
	
	std::vector<double> vd2;
	/*Ugyanez std::copy_if-el
		auto it = std::copy_if(vd.begin(),vd.end(), vd2.begin(), 
		Less_than(vd_mean));
		vd2.resize(std::distance(vd2.begin(),it));
	*/
	for (int i=0 ; i<vd.size() ; i++){
		if (vd[i]<vd_mean) vd2.push_back(vd[i]);
	}
	std::cout<<"The elements which are lower than the mean: \n";
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);
	
} catch (std::exception& e) {
	std::cerr<<e.what()<<'\n';
	return 1;
} catch(...){
	std::cerr<<"Unknown exception";
	return 2;
}

