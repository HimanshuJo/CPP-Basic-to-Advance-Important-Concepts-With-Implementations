#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

struct Trie{
    bool isLeaf;
    unordered_map<char, Trie*>charMp;

    Trie(){
        isLeaf=false;
    }
};

void insert(Trie* const &head, string const &str){
    Trie* curr=head;
    for (char ch: str){
        // Creating a new node if the path doesn't exist yet
        if (curr->charMp.find(ch)==curr->charMp.end()){
            curr->charMp[ch]=new Trie();
        }
        // Go to the next node
        curr=curr->charMp[ch];
    }
    curr->isLeaf=true;
}

string findLCP(string dict[], int n){
    // Inserting all keys into the Trie
    Trie* head=new Trie();
    for (int i=0; i<n; ++i){
        insert(head, dict[i]);
    }
    string lcp;
    Trie* curr=head;
    // Looping until we find a leaf node or a node has more than 1 children
    while (curr && !curr->isLeaf && (curr->charMp.size()==1)){
        // Getting an iterator to the only child
        auto it=curr->charMp.begin();
        lcp+=it->first;
        // Updating child pointer to the child node
        curr=it->second;
    }
    return lcp;
}

int main(){
    string dict[]={"coder","coder","codering","coderble","codercs","coderless","coderpendence"};
    int n=sizeof(dict)/sizeof(dict[0]);
    cout<<findLCP(dict, n);
    return 0;
}