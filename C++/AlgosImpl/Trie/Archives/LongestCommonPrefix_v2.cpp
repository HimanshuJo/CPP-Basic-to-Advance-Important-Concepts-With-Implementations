#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

const int ALPH_SZ=26;
unordered_map<int, char>mp;

struct Trie{
    struct Trie *children[ALPH_SZ];
    bool isEndOfWord;
};

struct Trie *getNode(void){
    struct Trie *pNode=new Trie;
    pNode->isEndOfWord=false;
    for(int i=1; i<=ALPH_SZ; ++i){
        pNode->children[i]=NULL;
    }
    return pNode;
}

void insert(struct Trie *root, string key){
    struct Trie *pCrawl=root;
    int len=key.length();
    for(int i=0; i<len; ++i){
        int idx=key[i]-'a';
		idx++;
        if(!pCrawl->children[idx]){
            pCrawl->children[idx]=getNode();
        }
        pCrawl=pCrawl->children[idx];
    }
    pCrawl->isEndOfWord=true;
}

bool search(struct Trie *root, string key){
    struct Trie *pCrawl=root;
    int len=key.length();
    for(int i=0; i<len; ++i){
        int idx=key[i]-'a';
		idx++;
        if(!pCrawl->children[idx])
            return false;
        pCrawl=pCrawl->children[idx];
    }
    return (pCrawl->isEndOfWord);
}

char intToAlphabet(int i)
{
	return mp[i];
}

bool isValid(struct Trie *node){
	int count=0;
	for(int i=1; i<=ALPH_SZ; ++i){
		if(!!node->children[i]){
			count++;
		}
	}
	return count==1;
}

int getIdx(struct Trie *node){
	for(int i=1; i<=ALPH_SZ; ++i){
		if(!!node->children[i]){
			return i;
		}
	}
	return -1;
}

string findLCP(string dict[], int n){
    Trie* head=new Trie();
    for (int i=0; i<n; ++i){
        insert(head, dict[i]);
    }
    string lcp;
    Trie* curr=head;
	char bgn='a';
	for(int i=1; i<=26; ++i){
		mp[i]=bgn++;
	}
    // Looping until we find a leaf node or a node has more than 1 children
    while (curr && !curr->isEndOfWord && (isValid(curr))){
		int idx=getIdx(curr);
        lcp+=intToAlphabet(idx);
        curr=curr->children[idx];
    }
    return lcp;
}

int main(){
    string dict[]={"coder","coder","codering","coderble","codercs","coderless","coderpendence"};
    int n=sizeof(dict)/sizeof(dict[0]);
    cout<<findLCP(dict, n);
    return 0;
}