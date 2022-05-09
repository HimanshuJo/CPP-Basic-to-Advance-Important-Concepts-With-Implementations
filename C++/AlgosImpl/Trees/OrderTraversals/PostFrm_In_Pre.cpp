#include<iostream>
using namespace std;

int search(int arr[], int x, int n){
	for(int i=0; i<n; ++i){
		if(arr[i]==x){
			return i;
		}
	}
	return -1;
}

/*
main idea: take each pre element and search for it's index in in[]
           accordingly update the right boundary for the search

pre[0] is always the root of the BT
S1: Search for pre[0] in in[] -> that will setup the first boundary in in[]
							     to create the left sub-tree as all the elements
								 left to the root in in[] are part of the left
								 sub-tree in post-fix tree
S2: Then start searching further in pre[] array for the next elements
*/

void prntPostOrder(int in[], int pre[], int n){
	int root=search(in, pre[0], n);
	cout<<endl;
	cout<<"pre element: "<<*pre<<endl;
	cout<<"curr root index: "<<root<<endl;
	if(root!=0){
		// search next pre element in in[] taking into account
		// the current root index as the right boundary
		prntPostOrder(in, pre+1, root);
	}
	if(root!=n-1){
		prntPostOrder(in+root+1, pre+root+1, n-root-1);
	} else{
		cout<<"root: "<<root<<" "<<"n-1: "<<n-1<<endl;
	}
	// pre is now currently at the current postfix element's index
	cout<<pre[0]<<" ";
	cout<<"\n-------\n";
}

int main(){
	int in[]={4, 2, 5, 1, 3, 6};
	int pre[]={1, 2, 4, 5, 3, 6};
	int n=6;
	prntPostOrder(in, pre, n);
}

// 4 5 2 6 3 1