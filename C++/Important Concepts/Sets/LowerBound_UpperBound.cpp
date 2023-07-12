/*
lower_bound(const g):

	Returns an iterator to the first element that is equivalent to ‘g’ or

	Definitely will not go before the element ‘g’ in the set.

-------

upper_bound(const g):

	Returns an iterator to the first element that will go after the element ‘g’ in the set.

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int>s = {11, 21, 30, 4, 25};
	cout << "set contents: " << endl;
	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
	auto itLb = lower_bound(s.begin(), s.end(), 15);
	auto itUb = upper_bound(s.begin(), s.end(), 15);
	cout << "lower Bounded element in the set: " << (*itLb) << endl;
	cout << "upper Bounded element in the set: " << (*itUb) << endl;
	int index = 0;
	int index2 = 0;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it == itLb) {
			cout << "Num ele less than the provided number: " << index << endl;
			break;
		}
		index++;
	}
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (it == itUb) {
			cout << "Num ele greater than the provided number: " << s.size() - index2 << endl;
			break;
		}
		index2++;
	}
	return 0;
}

/*
Output:

set contents:
4 11 21 25 30
lower Bounded element in the set: 21
upper Bounded element in the set: 21
Num ele less than the provided number: 2
Num ele greater than the provided number: 3
*/

/*
If the provided element is greater than the max element in the set, the iterator will point
	to the 'last index + 1'

Best way to avoid this is by checking, if the provided number is > element present in the last index
	in the set

	as if in some case iterator is pointing to the 'last index + 1' (like here), it might be
		problematic for some other cases when the lower or upper bound is actually that number
		i.e set size - 1

	int num=*next(s.begin(), s.size()-1);
	if (provNum>num){
		cout<<"Out of bounds";
	}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	set<int>s={11,21,30,5,25};
	cout<<"set contents: "<<endl;
	for (auto it=s.begin(); it!=s.end(); ++it){
		cout<<(*it)<<" ";
	}
	cout<<endl;
	int provNum=35;
	auto itLb=lower_bound(s.begin(), s.end(), provNum);
	auto itUb=upper_bound(s.begin(), s.end(), provNum);
	int maxEle=*next(s.begin(), s.size()-1);
	bool flag=false;
	if (provNum>maxEle){
		flag=true;
		cout<<"Element provided is greater than the max element"<<endl;
	}
	if (!flag){
		cout<<"lower Bounded element in the set: "<<(*itLb)<<endl;
		cout<<"upper Bounded element in the set: "<<(*itUb)<<endl;
		int index=0;
		int index2=0;
		for (auto it=s.begin(); it!=s.end(); ++it){
			if (it==itLb){
				cout<<"Num ele less than the provided number: "<<index<<endl;
				break;
			}
			index++;
		}
		for (auto it=s.begin(); it!=s.end(); ++it){
			if (it==itUb){
				cout<<"Num ele greater than the provided number: "<<s.size()-index2<<endl;
				break;
			}
			index2++;
		}
	}
	return 0;
}

Output:

set contents:
5 11 21 25 30
Element provided is greater than the max element
*/