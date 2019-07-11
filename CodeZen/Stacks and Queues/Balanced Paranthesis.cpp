#include<bits/stdc++.h>
using namespace std;
bool isOpenningBracket(char bracket){
    return bracket == '{' || bracket == '(' || bracket == '[';
}
bool isClosingBracket(char bracket){
    return bracket == '}' || bracket == ')' || bracket == ']';
}
bool isMatchingBracket(stack<char> s, char closingBracket){
    if(s.empty())
        return false;
    char openningBracket = s.top();
    if(openningBracket == '{' && closingBracket == '}')
        return true;
    if(openningBracket == '[' && closingBracket == ']')
        return true;
    if(openningBracket == '(' && closingBracket == ')')
        return true;
    return false;
}
bool checkBalanced(char *exp) {
    // Write your code here
    stack<char>s;
    for(int i = 0; i < strlen(exp); i++){
        if(isOpenningBracket(exp[i]))
            s.push(exp[i]);
        if(isClosingBracket(exp[i])){
            if(isMatchingBracket(s,exp[i]))
            {
                s.pop();
                continue;
            }
            else
                return false;
        }
    }
    if(!s.empty())
        return false;
    else
        return true;
}