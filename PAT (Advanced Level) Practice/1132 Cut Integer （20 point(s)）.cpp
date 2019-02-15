#include<cstdio>
#include<iostream> 
#include<string>
#include<algorithm>
using namespace std; 
typedef long long ll;
ll n, a, b, c;
string s;
int main() {
	scanf("%lld", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &c);
		s = to_string(c);
		a = stoll(s.substr(0, s.length() / 2));
		b = stoll(s.substr(s.length() / 2));
		if(a * b != 0 && c % (a * b) == 0) printf("Yes\n");
		else printf("No\n");
	}	
	return 0;
}
