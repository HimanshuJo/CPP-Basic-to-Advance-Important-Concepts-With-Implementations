// 2129. Capitalize the Title
/*
You are given a string title consisting of one or more words separated by a single space, 
where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
Example 2:

Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
*/

class Solution {
public:
    string capitalizeTitle(string title) {
        for_each(title.begin(), title.end(), [](char & c){
            c=::toupper(c);
        });
        map<char, char>mp;
        for(char ch='A'; ch<='Z'; ++ch){
            mp[ch]=tolower(ch);
        }
        string res="";
        int n=title.length();
        vector<string>splitted;
        char *cstr=new char[n+1];
        strcpy(cstr, title.c_str());
        char *ptr;
        ptr=strtok(cstr, " ");
        while(ptr!=NULL){
            splitted.push_back(ptr);
            ptr=strtok(NULL, " ,-.");
        }
        int sz=splitted.size();
        for(int x=0; x<sz; ++x){
            string vals=splitted[x];
            int n_=vals.size();
            if(n_>2){
                string temp="";
                for(int i=0; i<n_; ++i){
                    if(i==0){
                        temp+=toupper(mp[vals[i]]);
                    } else temp+=mp[vals[i]];
                }
                res+=temp;
            } else{
                string temp="";
                for(int i=0; i<n_; ++i){
                    temp+=mp[vals[i]];
                }
                res+=temp;
            }
            if(x!=sz-1) res+=" ";
        }
        return res;
    }
};