// 2232. Minimize Result by Adding Parentheses to Expression
/*
You are given a 0-indexed string expression of the form "<num1>+<num2>" 
where <num1> and <num2> represent positive integers.

Add a pair of parentheses to expression such that after the addition of parentheses, 
expression is a valid mathematical expression and evaluates to the smallest possible value. 
The left parenthesis must be added to the left of '+' and the right parenthesis must 
be added to the right of '+'.

Return expression after adding a pair of parentheses such that expression evaluates 
to the smallest possible value. If there are multiple answers that yield the same result, 
return any of them.

The input has been generated such that the original value of expression, 
and the value of expression after adding any pair of parentheses that meets 
the requirements fits within a signed 32-bit integer.

Example 1:

Input: expression = "247+38"
Output: "2(47+38)"
Explanation: The expression evaluates to 2 * (47 + 38) = 2 * 85 = 170.
Note that "2(4)7+38" is invalid because the right parenthesis must be to the right of the '+'.
It can be shown that 170 is the smallest possible value.
Example 2:

Input: expression = "12+34"
Output: "1(2+3)4"
Explanation: The expression evaluates to 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20.
Example 3:

Input: expression = "999+999"
Output: "(999+999)"
Explanation: The expression evaluates to 999 + 999 = 1998.

Constraints:

3 <= expression.length <= 10
expression consists of digits from '1' to '9' and '+'.
expression starts and ends with digits.
expression contains exactly one '+'.
The original value of expression, and the value of expression after adding any pair of 
parentheses that meets the requirements fits within a signed 32-bit integer.
*/

class Solution {
public:
    
    int eval(string expr)
    {
        string xxx;
        for (int i = 0; i < expr.length(); i++)
        {
            if (expr[i] != ' ')
            {
                xxx += expr[i];
            }
        }

        string tok = "";
        for (int i = 0; i < xxx.length(); i++)
        {
            if (xxx[i] == '(')
            {
                int iter = 1;
                string token;
                i++;
                while (true)
                {
                    if (xxx[i] == '(')
                    {
                        iter++;
                    } else if (xxx[i] == ')')
                    {
                        iter--;
                        if (iter == 0)
                        {
                            i++;
                            break;
                        }
                    }
                    token += xxx[i];
                    i++;
                }
                tok += to_string(eval(token));
            }
            tok += xxx[i];
        }

        for (int i = 0; i < tok.length(); i++)
        {
            if (tok[i] == '+')
            {
                return eval(tok.substr(0, i)) + eval(tok.substr(i+1, tok.length()-i-1));
            }
        }

        for (int i = 0; i < tok.length(); i++)
        {
            if (tok[i] == '*')
            {
                return eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.length()-i-1));
            }
        }
        return stoi(tok.c_str());
    }
    
    string minimizeResult(string expression) {
        int sz=expression.size();
        unordered_map<string, string>mp;
        int plusidx=0;
        for(int i=0; i<sz; ++i){
            if(expression[i]=='+'){
                plusidx=i;
                break;
            }
        }
        int currexpr=INT_MAX;
        string ans="";
        string left=expression.substr(0, plusidx);
        string right=expression.substr(plusidx+1, (sz-plusidx)-1);
        string openb="(";
        string closeb=")";
        string star="*";
        int rsz=right.size(), lsz=left.size();
        for(int i=0; i<=lsz-1; ++i){
            string templ=left;
            templ.insert(i, openb);
            for(int j=rsz; j>0; --j){
                string tempr=right;
                tempr.insert(j, closeb);
                string combstr="";
                combstr+=templ;
                combstr+='+';
                combstr+=tempr;
                int sz_=combstr.length();
                string temp__=combstr;
                for(int x=0; x<sz_-1; ++x){
                    if(isdigit(combstr[x])&&combstr[x+1]=='('){
                        combstr.insert(x+1, star);
                        break;
                    }
                }
                sz_=combstr.length();
                for(int x=sz_-1; x>0; --x){
                    if(isdigit(combstr[x])&&combstr[x-1]==')'){
                        combstr.insert(x, star);
                        break;
                    }
                }
                mp[combstr]=temp__;
                int curvals=eval(combstr);
                if(curvals<currexpr){
                    ans=combstr;
                    currexpr=curvals;
                }
            }
        }
        return mp[ans];
    }
};