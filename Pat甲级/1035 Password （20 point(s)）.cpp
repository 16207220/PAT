#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	string user, password;
	vector<string> res;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		cin >> user >> password;
		bool modified = false;
		for(int j = 0; j < password.length(); ++j)	switch(password[j]) {
			case '1' : password[j] = '@'; modified = true; break;
			case 'l' : password[j] = 'L'; modified = true; break;
			case '0' : password[j] = '%'; modified = true; break;
			case 'O' : password[j] = 'o'; modified = true; break;
		}
		if(modified) res.push_back(user + " " + password);
	}
	if(res.size()) {
		printf("%d\n", res.size());
		for(int i = 0; i < res.size(); ++i)	printf("%s\n", res[i].c_str());
	} else if(n == 1) printf("There is 1 account and no account is modified\n");
	else printf("There are %d accounts and no account is modified", n);
	return 0;
} 
