// C++ program to illustrate the
// unordered_multimap::erase() function
#include <bits/stdc++.h>
using namespace std;

int main()
{

	// declaration of unordered_multimap
	unordered_multimap<char, int> sample;

	// inserts element
	sample.insert({ 'a', 2 });
	sample.insert({ 'a', 4 });
	sample.insert({ 'c', 8 });
	sample.insert({ 'd', 10 });
	sample.insert({ 'c', 4 });
	sample.insert({ 'e', 4 });
	sample.insert({ 'f', 4 });
	cout << " Elements of multimap are : \n";
	for (auto& x : sample)
		cout << x.first << " : " << x.second << endl;

	// delete element by position
	sample.erase('a');

	// print after delete by position
	cout << " Elements of multimap after deleting by position are : \n";
	for (auto& x : sample)
		cout << x.first << " : " << x.second << endl;

	// erase by Element
	sample.erase('c');

	// print after delete by element
	cout << " Elements of multimap after deleting by element name : \n";
	for (auto& x : sample)
		cout << x.first << " : " << x.second << endl;

	// erase by range
	sample.erase(sample.find('e'), sample.end());

	// print after delete by range
	cout << " Elements of multimap after deleting by range are : \n";
	for (auto& x : sample)
		cout << x.first << " : " << x.second << endl;
	return 0;
}
