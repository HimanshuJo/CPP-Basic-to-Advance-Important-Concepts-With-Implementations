#include<set>
#include<iostream>
using namespace std;


int main(){
	set<int>st{0};
	auto it1=st.begin();
	auto it=st.end();
	cout<<*it1<<endl;
	cout<<*it<<endl;
}