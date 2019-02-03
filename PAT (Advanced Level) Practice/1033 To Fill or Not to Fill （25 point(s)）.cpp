#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node {
	double price, dis;
	bool operator < (const node& rhs) const {
		return dis < rhs.dis;
	}
};
vector<node> station;
double cmax, d, davg; //���������� ���ݸ��յ�ľ��룬 һ����λ���ܵ�·
int n; // ��վ 
int main() {
	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	station.resize(n + 1);
	for(int i = 0; i < n; ++i) scanf("%lf%lf", &station[i].price, &station[i].dis);
	station[n].price = 0.0, station[n].dis = d; // �߽����� 
	sort(station.begin(), station.end());
	double nowdis = 0.0, leftdis = 0.0, maxdis = 0.0, totalprice = 0.0, nowprice = 0.0;
	if(station[0].dis) {
		printf("The maximum travel distance = 0.00");
		return 0;
	} else nowprice = station[0].price;
	while(nowdis < d) {
		maxdis = nowdis + cmax * davg;
		double minpricedis, minprice = INF;
		bool cheap = false; //�ҵ�һ���ͼ��͵���� 
		for(int i = 1; i <= n && station[i].dis <= maxdis; ++i) {
			if(station[i].dis <= nowdis) continue; //���վ�Ѿ�����
			if(station[i].price < nowprice) {
				totalprice += (station[i].dis - nowdis - leftdis) / davg * nowprice;
				nowprice = station[i].price;
				nowdis = station[i].dis;
				leftdis = 0.0;
				cheap = true; //�ҵ�һ�������˵���վ. 
				break;
			} else if(station[i].price < minprice){
				minprice = station[i].price;
				minpricedis = station[i].dis;
			}
		} 
		if(!cheap && minprice != INF) {
			totalprice += nowprice * (cmax - leftdis / davg);
			leftdis = cmax * davg - (minpricedis - nowdis); // �����վ�ȽϹ�������ԭ����վ�����͡�
			nowdis = minpricedis;
			nowprice = minprice; 
		} else if(!cheap && minprice == INF) {
			nowdis += cmax * davg;
			printf("The maximum travel distance = %.2f", nowdis);
			return 0; 
		}
	} 
	printf("%.2f", totalprice);
	return 0;
} 
