#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> ans;
bool cmp(const string& a, const string& b) {
	return a + b < b + a;
}
int main() {
	int n;
	scanf("%d", &n);
	ans.resize(n);
	for(int i = 0; i < n; ++i) cin >> ans[i];
	sort(ans.begin(), ans.end(), cmp);
	string res = "";
	for(int i = 0; i < ans.size(); ++i) res += ans[i];
	while(res.size() != 0 && res[0] == '0') res.erase(res.begin());
	if(res.size()) cout << res;
	else printf("0");
	return 0; 
}
