/*Given a string check if it is a permutation of a palindrome.

E.g. string="tact coa"
     output: true ("taco cat" or "atco cta")

     string="mmdaa"
     output: true ("madam")
*/

/*
	Algo:

		When we see a letter, we map it to an int value(between 0 and 25)
		We toggle the bit at that value
		At the end, we check if at most one bit in the integer is set to 1

		Checking if at most one bit in the integer is set to 1

			Suppose we've an int value: 00010000
				if we subtract 1 from the number, we'll get 00001111

				next we AND the resultant number with the original number
				If there is at-most one bit set, we should get 0

				00010000 - 1 = 00001111
				00010000 & 00001111 = 0

Time: O(N)
*/

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

string toBinary(int num){
	string res="";
	if(num==0) return "0";
	while(num!=1){
		if(num%2==0) res+="0";
		else res+="1";
		num/=2;
	}
	res+="1";
	reverse(res.begin(), res.end());
	return res;
}

int toggle(int bitVector, int index){
	if(index<0) return bitVector;
	int mask=1<<index;
	bitVector^=mask;
	return bitVector;
}

int createBitVector(string in){
	int bitVector=0;
	for(char ch: in){
		int x=((int)ch)-87;
		cout<<"num equiv "<<x<<endl;
		cout<<"bit vector earlier "<<toBinary(bitVector)<<endl;
		bitVector=toggle(bitVector, x);
		cout<<"bit vector next "<<toBinary(bitVector)<<endl;
		cout<<"-------\n";
	}
	return bitVector;
}

bool checkAtMostOneBitSet(int bitVector){
	return (bitVector&(bitVector-1))==0;
}

bool isPermutationOfPalindrome(string in){
	int bitVector=createBitVector(in);
	return checkAtMostOneBitSet(bitVector);
}


int main(){
	string in="madam";
	bool res=isPermutationOfPalindrome(in);
	cout<<(res==0?"false":"true")<<endl;
}