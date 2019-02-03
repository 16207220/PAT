#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
string name, gender, id, fname, fid, mname, mid; // female and male's id ,name
int grade, mingrade = 101, maxgrade = -1; // 莫非真的可能有零分的呢。。。 
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		cin >> name >> gender >> id >> grade;
		if(gender == "F") {
			if(grade > maxgrade) {
				fname = name;
				fid = id;
				maxgrade = grade;
			}
		} else {
			if(grade < mingrade) {
				mname = name;
				mid = id;
				mingrade = grade;
			}
		}
	}
	if(maxgrade != -1) cout << fname << " " << fid << '\n';
	else printf("Absent\n");
	if(mingrade != 101) cout << mname << " " << mid << '\n';
	else printf("Absent\n");
	if(maxgrade != -1 && mingrade != 101) printf("%d\n", maxgrade - mingrade);
	else printf("NA\n");
	return 0;
}
