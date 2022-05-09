#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
using ll=long long;

void print(const unordered_map<int, ll>&mp){
	for(const auto &v: mp){
		cout<<v.first<<" : "<<v.second<<"\n";
	}
	cout<<"\n";
}

int main(int argc, char * argv[]){
	string inp="./Test/6_inp.txt";
	if(argc>1){
		inp=argv[1];
	}
	string line;
	fstream file(inp);
	getline(file, line);
	unordered_map<int, ll>fish;
	for(int i=0; i<9; ++i){
		fish[i]=0;
	}
	size_t start=0;
	size_t end=line.find(',', start);
	while(end!=string::npos){
		const auto val=stoll(line.substr(start, end-start));
		fish[val]++;
		start=end+1;
		end=line.find(',', start);
	}
	const auto val=stoll(line.substr(start, line.size()-start));
	fish[val]++;
	for(int d=0; d<256; ++d){
		const ll to_add=fish[0];
		for(int i=1; i<7; ++i){
			fish[i-1]=fish[i];
		}
		fish[6]=to_add+fish[7];
		fish[7]=fish[8];
		fish[8]=to_add;
	}
	ll sum=0;
	for(const auto &v: fish){
		sum+=v.second;
	}
	print(fish);
	cout<<"-------\n";
	cout<<sum<<"\n";
	return 0;
}
