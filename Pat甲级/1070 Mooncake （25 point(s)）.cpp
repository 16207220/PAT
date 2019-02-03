#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	float mount, price, avg;
	bool operator < (const node& rhs) const {
		return avg > rhs.avg;
	}
};
int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	vector<node> res(n);
	for(int i = 0; i < n; ++i) scanf("%f", &res[i].mount);
	for(int i = 0; i < n; ++i) {
		scanf("%f", &res[i].price);
		res[i].avg = res[i].price / res[i].mount;
	}
	sort(res.begin(), res.end());
	float result = 0.0;
	for(int i = 0; i < n; ++i) {
		if(res[i].mount <= d) {
			d -= res[i].mount;
			result += res[i].price;
		} else {
			result += d * res[i].avg;
			break;
		}
	}
	printf("%.2f\n", result);
	return 0;
} 
