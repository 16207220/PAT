#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
string earliestId, latestId, id;
int m, inTime, outTime, inEarliest, outLatest;
int inHh, inMm, inSs, outHh, outMm, outSs;
int main() {
	inEarliest = INF; outLatest = 0;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		cin >> id;
		scanf("%d:%d:%d %d:%d:%d", &inHh, &inMm, &inSs, &outHh, &outMm, &outSs);
		inTime = inHh * 3600 + inMm * 60 + inSs, outTime = outHh * 3600 + outMm * 60 + outSs;
		if(inEarliest > inTime) {
			inEarliest = inTime;
			earliestId = id;
		}
		if(outTime > outLatest) {
			outLatest = outTime;
			latestId = id;
		}
	}
	cout << earliestId << ' ' << latestId << '\n';
	return 0;
}
