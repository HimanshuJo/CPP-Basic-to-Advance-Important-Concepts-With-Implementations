#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int, int> mp;
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 60 });
	mp.insert({ 4, 20 });
	mp.insert({ 5, 50 });

	auto ite = mp.cbegin();

	cout << "The first element is: ";
	cout << "{" << ite->first << ", "
		 << ite->second << "}\n";
		 
	cout << "\nThe map is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr) {
		cout << itr->first
			 << '\t' << itr->second << '\n';
	}
	cout<<"\n-------\n";
	for(auto itr=mp.cbegin(); itr!=mp.cend(); ++itr){
		if(itr->first&1){
			mp.erase(itr++);
		} else itr++;
	}
	cout << "\nThe new map is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr) {
		cout << itr->first
			 << '\t' << itr->second << '\n';
	}
	return 0;
}

/*
Output:

The first element is: {1, 40}
The map is : KEY     ELEMENT
1       40
2       30
3       60
4       20
5       50

-------

The new map is : 
KEY     ELEMENT
2       30
4       20
*/