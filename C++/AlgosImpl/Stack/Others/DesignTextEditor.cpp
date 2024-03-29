// 2296. Design a Text Editor
/*
Design a text editor with a cursor that can do the following:

Add text to where the cursor is.
Delete text from where the cursor is (simulating the backspace key).
Move the cursor either left or right.
When deleting text, only characters to the left of the cursor will be deleted. 
The cursor will also remain within the actual text and cannot be moved beyond it. 

More formally, we have that 0 <= cursor.position <= currentText.length always holds.

Implement the TextEditor class:

TextEditor() Initializes the object with empty text.
void addText(string text) Appends text to where the cursor is. 
The cursor ends to the right of text.

int deleteText(int k) Deletes k characters to the left of the cursor. 
Returns the number of characters actually deleted.

string cursorLeft(int k) Moves the cursor to the left k times. 
Returns the last min(10, len) characters to the left of the cursor, 
where len is the number of characters to the left of the cursor.

string cursorRight(int k) Moves the cursor to the right k times. 
Returns the last min(10, len) characters to the left of the cursor, 
where len is the number of characters to the left of the cursor.
 

Example 1:

Input
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", 
"deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
Output
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

Explanation
TextEditor textEditor = new TextEditor(); // The current text is "|". 
(The '|' character represents the cursor)
textEditor.addText("leetcode"); // The current text is "leetcode|".
textEditor.deleteText(4); // return 4
                          // The current text is "leet|". 
                          // 4 characters were deleted.
textEditor.addText("practice"); // The current text is "leetpractice|". 
textEditor.cursorRight(3); // return "etpractice"
                           // The current text is "leetpractice|". 
                           // The cursor cannot be moved beyond the actual text and thus did not move.
                           // "etpractice" is the last 10 characters to the left of the cursor.
textEditor.cursorLeft(8); // return "leet"
                          // The current text is "leet|practice".
                          // "leet" is the last min(10, 4) = 4 characters to the left of the cursor.
textEditor.deleteText(10); // return 4
                           // The current text is "|practice".
                           // Only 4 characters were deleted.
textEditor.cursorLeft(2); // return ""
                          // The current text is "|practice".
                          // The cursor cannot be moved beyond the actual text and thus did not move. 
                          // "" is the last min(10, 0) = 0 characters to the left of the cursor.
textEditor.cursorRight(6); // return "practi"
                           // The current text is "practi|ce".
                           // "practi" is the last min(10, 6) = 6 characters to the left of the cursor.
 

Constraints:

1 <= text.length, k <= 40
text consists of lowercase English letters.
At most 2 * 10^4 calls in total will be made to addText, deleteText, 
cursorLeft and cursorRight.
*/

/*
TLE: 41/45

class TextEditor {
public:
    
    string fntxt="|";
    
    TextEditor() {
        
    }
    
    void addText(string text) {
        int idx=fntxt.find('|');
        fntxt.insert(idx, text);
    }
    
    int deleteText(int k) {
        int ans=0;
        int idx=fntxt.find('|');
        int avlchars=idx;
        if(avlchars>=k){
            auto it=fntxt.begin()+idx;
            fntxt.erase(it);
            int count=k;
            while(count--){
                if(idx==0) break;
                idx--;
                if(idx==0) break;
            }
            fntxt.insert(idx, "|");
            int idx_=fntxt.find('|');
            if(idx_+1<=fntxt.size()-1){
                fntxt.erase(idx_+1, k);
            }
            ans=k;   
        } else{
            auto it=fntxt.begin()+idx;
            fntxt.erase(it);
            idx-=avlchars;
            fntxt.insert(idx, "|");
            int idx_=fntxt.find('|');
            if(idx_+1<=fntxt.size()-1){
                fntxt.erase(idx_+1, avlchars);
            }
            ans=avlchars; 
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        int idx=fntxt.find('|');
        string ans="";
        if(idx==0){
            return ans;
        } else{
            auto it=fntxt.begin()+idx;
            fntxt.erase(it);
            while(k--){
                if(idx==0) break;
                idx--;
                if(idx==0) break;
            }
            fntxt.insert(idx, "|");
            if(idx>=1){
                int sz=idx;
                int minn=min(10, sz);
                int count=minn;
                while(count--){
                    if(idx==0) break;
                    idx--;
                    if(idx==0) break;
                }
                ans=fntxt.substr(idx, minn);
                if(ans.size()==1&&ans[0]=='|') ans="";
            }
        }
        return ans;
    }
    
    string cursorRight(int k) {
        int idx=fntxt.find('|');
        string ans="";
        if(idx==fntxt.size()-1){
            int sz=idx;
            int minn=min(10, sz);
            int count=minn;
            while(count--){
                if(idx==0) break;
                idx--;
                if(idx==0) break;
            }
            ans=fntxt.substr(idx, minn);
            if(ans.size()==1&&ans[0]=='|') ans="";
        } else{
            auto it=fntxt.begin()+idx;
            fntxt.erase(it);
            while(k--){
                if(idx==fntxt.size()) break;
                idx++;
                if(idx==fntxt.size()) break;
            }
            fntxt.insert(idx, "|");
            int sz=idx;
            int minn=min(10, sz);
            int count=minn;
            while(count--){
                if(idx==0) break;
                idx--;
                if(idx==0) break;
            }
            ans=fntxt.substr(idx, minn);
            if(ans.size()==1&&ans[0]=='|') ans="";
        }
        return ans;
    }
};
*/


/*
Time Complexity of each operation:
addText(string text) : O(n) {where n == length of text}
deleteText(int k) : O(k)
cursorLeft(int k) : O(k)
cursorRight(int k) : O(k)
*/

class TextEditor {
    
    stack<char>left, right;
    
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char &ch: text){
            left.push(ch);
        }
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(!left.empty()&&k>0){
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }
    
    string cursorShiftString(){
        string res="";
        int cnt=10;
        while(!left.empty()&&cnt>0){
            char ch=left.top();
            left.pop();
            res+=ch;
            cnt--;
        }
        reverse(res.begin(), res.end());
        for(int i=0; i<res.size(); ++i){
            left.push(res[i]);
        }
        return res;
    }
    
    string cursorLeft(int k) {
        while(!left.empty()&&k>0){
            char ch=left.top();
            left.pop();
            right.push(ch);
            k--;
        }
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
        while(!right.empty()&&k>0){
            char ch=right.top();
            right.pop();
            left.push(ch);
            k--;
        }
        return cursorShiftString();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */