#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5;
struct node {
	int id, fat, mot, num, people;
	int child[8];
	double area, avgs, avga;
	bool flag;
	bool operator < (const node& rhs) const {
		return avga != rhs.avga ? avga > rhs.avga : id < rhs.id;
	}
}res[MAXN]; 
int book[MAXN], father[MAXN];
int n, x, k;
int find(int x) {
	return x == father[x] ? x : father[x] = find(father[x]); 
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x > y) father[x] = y;
	else if(y > x) father[y] = x;
}
int main() {
	for(int i = 0; i < MAXN; ++i) father[i] = i, book[i] = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x); res[x].id = x; book[x] = 1;
		scanf("%d%d%d", &res[x].fat, &res[x].mot, &k);
		if(res[x].fat != -1) {
			unite(x, res[x].fat);
			book[res[x].fat] = 1;
		}
		if(res[x].mot != -1) {
			unite(x, res[x].mot);
			book[res[x].mot] = 1;
		}
		for(int j = 0; j < k; ++j) {
			scanf("%d", &res[x].child[j]);
			unite(x, res[x].child[j]);
			book[res[x].child[j]] = 1;
		}
		scanf("%d%lf", &res[x].num, &res[x].area);
	}
	for(int i = 0; i < MAXN; ++i) if(book[i]) {
		x = find(i);
		res[x].id = x; // 可能是孩子 
		res[x].flag = true;
		res[x].people++; // 总人数 
		res[x].avga += res[i].area; // 总面积 
		res[x].avgs += res[i].num; // 总套数 
	}
	int cnt = 0;
	for(int i = 0; i < MAXN; ++i) if(book[i] && res[i].flag) {
		++cnt;
		res[i].avga /= res[i].people; //平均面积 
		res[i].avgs /= res[i].people; //平均套数 
	} 
	sort(res, res + MAXN);
	printf("%d\n", cnt); 
	for(int i = 0; i < cnt; ++i) {
		printf("%04d %d %.3f %.3f\n", res[i].id, res[i].people, res[i].avgs, res[i].avga);
	}
	return 0;
}
