/* Given a dictionary of words, determine if a given string can be segmented into 
    a space-separated sequence of one or more dictionary words

    Example:
        Input
            dict[]={this,th,is,famous,Word,break,b,r,e,a,k,br,bre,brea,ak,problem}
            string=Wordbreakproblem
        Output:
            The string can be segmented
            The segmented strings are:
            Word break problem
            Word brea k problem
            Word bre ak problem
            Word bre a k problem
            Word br e ak problem
            Word br e a k problem
            Word b r e ak problem
            Word b r e a k problem
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define CHAR_SIZE 26

struct Node{
    bool isLeaf;
    Node* next[CHAR_SIZE];

    // Function to return a new Trie node
    Node(){
        isLeaf=false;
        for (int i=0; i<CHAR_SIZE; ++i){
            next[i]=nullptr;
        }
    }
};

// Recursive function to delete a Trie in a postorder manner
void freeTrie(Node* node){
    if (!node){
        return;
    }
    for (int i=0; i<CHAR_SIZE; ++i){
        freeTrie(node->next[i]);
    }
    delete node;
}

void insertTrie(Node* const head, string const &str){
    Node* node=head;
    // Do for each character in the string
    for (char ch: str){
        if (node->next[ch-'a']==nullptr){
            node->next[ch-'a']=new Node();
        }
        node=node->next[ch-'a'];
    }
    node->isLeaf=true;
}

// Function to determine if the string can be segmented into a space separated sequence
// of one or more dictionary words
bool wordBreak(Node* const head, string const &str){
    int n=str.length();
    // good[i] is true if the first i'th characters of str can be segmented
    vector<bool>good(n+1);
    good[0]=true;
    for (int i=0; i<n; ++i){
        if (good[i]){
            Node* node=head;
            for (int j=i; j<n; ++j){
                if (!node){
                    break;
                }
                node=node->next[str[j]-'a'];
                // We can make [0,i] using our known decompositio// and [i+1,j] using the string in a Trie
                if (node&&node->isLeaf){
                    good[j+1]=true;
                }
            }
        }
    }
    // good[n] would be true if all the characters of str can be segemented
    return good[n];
}

int main(){
    //vector<string>dict={"this","th","is","famous","word","break","b","r","e","a","k","br","bre","brea","ak","prob","lem"};
    vector<string>dict={"this","th","is","famous","word","break","b","r","e","a","k","br","bre","brea","ak","prob","lem"};
    Node* trie=new Node();
    for (string const &s: dict){
        insertTrie(trie,s);
    }
    string str="wordbreakproblem";
    if (wordBreak(trie,str)){
        cout<<"The string can be segmented"<<endl;
    } else{
        cout<<"The string can't be segmented"<<endl;
    }
    
    freeTrie(trie);
    return 0;
}
