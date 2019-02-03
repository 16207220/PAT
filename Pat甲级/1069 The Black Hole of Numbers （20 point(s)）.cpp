#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string a, b, t;
	cin >> t;
	a.insert(0, 4 - a.length(), '0');
	do {
		b = a = t;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<char>());
		int result = stoi(b) - stoi(a);
		t = to_string(result);
		t.insert(0, 4 - t.length(), '0');
		cout << b << " - " << a << " = " << t << endl;
	} while(t != "0000" && t != "6174");
	return 0;
}
