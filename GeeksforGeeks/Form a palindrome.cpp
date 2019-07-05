//https://practice.geeksforgeeks.org/problems/form-a-palindrome/0/?track=md-string&batchId=144
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	int n = s.size();
	int table[n][n],l,h;
	memset(table,0,sizeof(table));
	for(int gap = 1; gap < n; gap++)
	for(l = 0, h = gap; h < n; h++, l++)
	table[l][h] = (s[l] == s[h] ? table[l+1][h-1] : min(table[l][h-1],
	                                               table[l+1][h])+1);
	cout << table[0][n-1] << endl;
	}
	return 0;
}
