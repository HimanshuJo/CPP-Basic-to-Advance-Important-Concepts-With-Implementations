// 2416. Sum of Prefix Scores of Strings
/*
You are given an array words of size n consisting of non-empty strings.

We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

Example 1:

Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.
Example 2:

Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists of lowercase English letters.
*/

/*
TLE: 32 / 38

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, int>mp;
        for(auto &vals: words){
            string temp="";
            int sz=vals.size();
            for(int i=0; i<sz; ++i){
                temp+=vals[i];
                mp[temp]++;
            }
        }
        int fnsz=words.size();
        vector<int>ans(fnsz);
        int idx=0;
        for(auto &vals: words){
            int sz=vals.size();
            string temp="";
            int sm=0;
            for(int i=0; i<sz; ++i){
                temp+=vals[i];
                sm+=mp[temp];
            }
            ans[idx++]=sm;
        }
        return ans;
    }
};
*/

class TrieNode{
    public:
    unordered_map<int, TrieNode*>children;
    bool isEndOfWord;
    int visited;
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode();
        root->isEndOfWord=false;
        root->visited=0;
    }
    
    void insert(string word){
        int sz=word.size();
        TrieNode *temp=root;
        for(int i=0; i<sz; ++i){
            if(temp->children.find(word[i])==temp->children.end()){
                TrieNode *nwNode=new TrieNode();
                nwNode->isEndOfWord=false;
                nwNode->visited++;
                temp->children[word[i]]=nwNode;
            } else{
                temp->children[word[i]]->visited++;
            }
            temp=temp->children[word[i]];
        }
        temp->isEndOfWord=true;
    }
    
    int curval(string word){
        int sz=word.size();
        TrieNode *temp=root;
        int curr=0;
        for(int i=0; i<sz; ++i){
            if(temp->children.find(word[i])!=temp->children.end()){
                curr+=temp->children[word[i]]->visited;
                temp=temp->children[word[i]];
            }
        }
        return curr;
    }
    
    bool search(string word){
        int sz=word.size();
        TrieNode *temp=root;
        for(int i=0; i<sz; ++i){
            if(temp->children.find(word[i])==temp->children.end()) return false;
            temp=temp->children[word[i]];
        }
        return temp->isEndOfWord;
    }
    
    bool startsWith(string word){
        int sz=word.size();
        TrieNode *temp=root;
        for(int i=0; i<sz; ++i){
            if(temp->children.find(word[i])==temp->children.end()) return false;
            temp=temp->children[word[i]];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *obj=new Trie();
        for(auto &word: words){
            obj->insert(word);
        }
        int sz=words.size();
        vector<int>ans(sz, 0);
        int idx=0;
        for(auto &word: words){
            int curans=obj->curval(word);
            ans[idx++]=curans;
        }
        return ans;
    }
};

// -------*******-------

class Trie2{
    public:
    Trie2 *children[26]={};
    int visited=0;
};

class Solution2 {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int sz=words.size();
        Trie2 trie;
        for(auto &word: words){
            auto t=&trie;
            for(char &ch: word){
                if(!t->children[ch-'a']){
                    t->children[ch-'a']=new Trie();
                }
                t->children[ch-'a']->visited++;
                t=t->children[ch-'a'];
            }
        }
        vector<int>ans(sz, 0);
        int idx=0;
        for(auto &word: words){
            auto t=&trie;
            int curr=0;
            for(char &ch: word){
                curr+=t->children[ch-'a']->visited;
                t=t->children[ch-'a'];
            }
            ans[idx++]=curr;
        }
        return ans;
    }
};