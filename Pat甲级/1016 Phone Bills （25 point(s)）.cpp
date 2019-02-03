#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 25;
const int MAXM = 1010;
int rate[MAXN];
struct node {
	string id;
	int month;
	int d, h, m;
	int t;
	int status; //0, 1 
	bool operator < (const node& rhs) const {
		return rhs.id == id ? t < rhs.t : id < rhs.id;
	}
}bill[MAXM];
map<string, vector<node>> res;
double zeroToNowBill(node u) {	//从月初到当前时间通话费用. 
	double total = 0.0;
	total += 60 * rate[24] * u.d + rate[u.h] * u.m;
	for(int i = 0; i < u.h; ++i) total += rate[i] * 60;
	return total / 100; // 美分->美元 
}
int main() {
	for(int i = 0; i < 24; ++i) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i]; 	// 通话一天价格. 
	}
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		cin >> bill[i].id;
		scanf("%d:%d:%d:%d", &bill[i].month, &bill[i].d, &bill[i].h, &bill[i].m);
		bill[i].t = bill[i].d * 24 * 60 + bill[i].h * 60 + bill[i].m; 
		string stat;
		cin >> stat;
		bill[i].status = stat == "on-line" ? 1 : 0; 
	}
	sort(bill, bill + n);
	for(int i = 1; i < n; ++i) {
		if(bill[i].id == bill[i - 1].id && bill[i].status == 0 && bill[i - 1].status == 1) {
			res[bill[i].id].push_back(bill[i - 1]);
			res[bill[i].id].push_back(bill[i]);
		}
	}
	for(map<string, vector<node>>::iterator it = res.begin(); it != res.end(); ++it) {
		string id = it->first;
		vector<node>& u = res[id];
		double total = 0.0;
		printf("%s %02d\n", id.c_str(), u[0].month);
		for(int i = 1; i < u.size(); i += 2) {
			double t = zeroToNowBill(u[i]) - zeroToNowBill(u[i - 1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", u[i - 1].d, u[i - 1].h, u[i - 1].m, u[i].d, u[i].h, u[i].m, u[i].t - u[i - 1].t, t);
			total += t;
		}
		 printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
