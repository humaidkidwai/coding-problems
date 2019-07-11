#include<bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &s){
    // Write your code here
    stack<int> tmp;
    while(!s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    s.push(tmp.top());
    tmp.pop();
    while(!tmp.empty()){
        int cur = tmp.top();
        tmp.pop();
        int cnt = 0;
        while(!s.empty() && s.top() < cur){
            tmp.push(s.top());
            s.pop();
            cnt++;
        }
        s.push(cur);
        while(cnt--){
            s.push(tmp.top());
            tmp.pop();
        }
    }
}