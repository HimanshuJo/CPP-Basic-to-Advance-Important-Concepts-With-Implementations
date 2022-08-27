// 2227. Encrypt and Decrypt Strings
/*
You are given a character array keys containing unique characters and a string array values 
containing strings of length 2. You are also given another string array dictionary that 
contains all permitted original strings after decryption. You should implement a data 
structure that can encrypt or decrypt a 0-indexed string.

A string is encrypted with the following process:

For each character c in the string, we find the index i satisfying keys[i] == c in keys.
Replace c with values[i] in the string.
A string is decrypted with the following process:

For each substring s of length 2 occurring at an even index in the string, we find an 
i such that values[i] == s. If there are multiple valid i, we choose any one of them. 
This means a string could have multiple possible strings it can decrypt to.
Replace s with keys[i] in the string.
Implement the Encrypter class:

Encrypter(char[] keys, String[] values, String[] dictionary) Initializes the Encrypter class with keys,
 values, and dictionary.

String encrypt(String word1) Encrypts word1 with the encryption process described above and 
returns the encrypted string.

int decrypt(String word2) Returns the number of possible strings word2 could decrypt to that also appear in dictionary.

Example 1:

Input
["Encrypter", "encrypt", "decrypt"]
[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
Output
[null, "eizfeiam", 2]

Explanation
Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
encrypter.encrypt("abcd"); // return "eizfeiam". 
                           // 'a' maps to "ei", 'b' maps to "zf", 'c' maps to "ei", and 'd' maps to "am".
encrypter.decrypt("eizfeiam"); // return 2. 
                              // "ei" can map to 'a' or 'c', "zf" maps to 'b', and "am" maps to 'd'. 
                              // Thus, the possible strings after decryption are "abad", "cbad", "abcd", and "cbcd". 
                              // 2 of those strings, "abad" and "abcd", appear in dictionary, so the answer is 2.

Constraints:

1 <= keys.length == values.length <= 26
values[i].length == 2
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
All keys[i] and dictionary[i] are unique.
1 <= word1.length <= 2000
1 <= word2.length <= 200
All word1[i] appear in keys.
word2.length is even.
keys, values[i], dictionary[i], word1, and word2 only contain lowercase English letters.
At most 200 calls will be made to encrypt and decrypt in total.
*/

/*
Solution2:

unordered_map<char, string> enc;
    unordered_map<string, int> count;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i)
            enc[keys[i]] = values[i];
        for (string& w: dictionary)
            count[encrypt(w)]++;
    }
    
    string encrypt(string word1) {
        string res = "";
        for (char c: word1) {
            if (!enc.count(c)) return "";
            res += enc[c];
        }
        return res;
    }
    
    int decrypt(string word2) {
        return count[word2];
    }
*/

class Encrypter {
public:
    unordered_map<char, string>mp1;
    unordered_map<string, vector<char>>mp2;
    unordered_map<string, string>dict;
    unordered_map<string, int>memo;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int sz=keys.size();
        for(int i=0; i<sz; ++i){
            mp1[keys[i]]=values[i];
            mp2[values[i]].push_back(keys[i]);
        }
        for(auto &vals: dictionary){
            dict[vals]=vals;
        }
    }
    
    string encrypt(string word1) {
        string res="";
        for(char ch: word1){
            res+=mp1[ch];
        }
        return res;
    }
    
    void dfs(string word, string curr, int idx, int len, int &res){
        if(idx>=len){
            if(dict.find(curr)!=dict.end()) res++;
            return;
        }
        string temp="";
        temp+=word.substr(idx, 2);
        int sz=mp2[temp].size();
        for(int i=0; i<sz; ++i){
            string antemp=curr;
            antemp+=mp2[temp][i];
            dfs(word, antemp, idx+2, len, res);
        }
    }
    
    int decrypt(string word2) {
        int i=0, len=word2.length();
        if(memo.find(word2)!=memo.end()) return memo[word2];
        if(mp2.size()==1){
            auto it=mp2.begin();
            if(it->second.size()==26){
                int idx=0;
                string tochk=it->first;
                bool flag=false;
                while(true){
                    string temp_=word2.substr(idx, 2);
                    if(temp_!=tochk){
                        flag=true;
                        break;
                    }
                    idx+=2;
                    if(idx>=len) break;
                }
                if(!flag){
                    int sztochk=len/2;
                    int cnt=0;
                    for(auto &entries: dict){
                        if(entries.first.size()==sztochk) cnt++;
                    }
                    return cnt;
                }
            }
        }
        string curr="";
        int res=0;
        dfs(word2, curr, i, len, res);
        return memo[word2]=res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */