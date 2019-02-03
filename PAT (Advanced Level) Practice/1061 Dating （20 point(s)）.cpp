#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string t[8] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int book[256];
int day, h, m;
int main() {
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < a.length() && i < b.length(); ++i) {
		if(!day && a[i] >= 'A' && a[i] <= 'Z' && a[i] == b[i]) day = a[i] - 'A' + 1;
		else if(day && a[i] == b[i]) {
			if(a[i] >= '0' && a[i] <= '9') {
				h = a[i] - '0';
				break;
			}
			else if(a[i] >= 'A' && a[i] <= 'N') {
				h = a[i] - 'A' + 10;
				break;
			}
		}	
	}
	cin >> a >> b;
	for(int i = 0; i < a.length() && i < b.length(); ++i) if(isalpha(a[i]) && a[i] == b[i]) {
		m = i;
		break;
	}
	printf("%s %02d:%02d", t[day].c_str(), h, m);
	return 0;
} 
