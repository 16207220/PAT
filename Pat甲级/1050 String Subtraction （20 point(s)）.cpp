#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a, b;
bool book[256];
int main() {
	getline(cin, a);
	getline(cin, b);
	for(int i = 0; i < b.length(); ++i) book[b[i]] = true;
	for(int i = 0; i < a.length(); ++i) if(book[a[i]] == false) printf("%c", a[i]);
	return 0;
} 
