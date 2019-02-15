#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> dispath, Timepath, temppath, Timepre[510];
int dispre[510], Time[510], dis[510], e[510][510], w[510][510], weight[510];
bool visit[510];
int st, fin, minnode = INF;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return ;
    dfsdispath(dispre[v]);
}

void dfsTimepath(int v) {
    temppath.push_back(v);
    if(v == st) {
        if(temppath.size() < minnode) {
            minnode = temppath.size();
            Timepath = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < Timepre[v].size(); i++)
        dfsTimepath(Timepre[v][i]);
    temppath.pop_back();
}
int main(){
	fill(dis, dis + 510, INF);
    fill(Time, Time + 510, INF);
    fill(weight, weight + 510, INF);
    fill(e[0], e[0] + 510 * 510, INF);
    fill(w[0], w[0] + 510 * 510, INF);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d%d", &st, &fin);
    dis[st] = 0;
    weight[st] = 0;
    for(int i = 0; i < n; ++i){
    	int u = -1, minn = INF;
    	for(int j = 0; j < n; ++j){
    		if(visit[j] == false && dis[j] < minn){
    			u = j;
    			minn = dis[j];
			}
		}
		if(u == -1)	break;
		visit[u] = true;
		for(int v = 0; v < n; ++v){
			if(visit[v] == false && e[u][v] != INF){
				if(e[u][v] + dis[u] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					dispre[v] = u;
					weight[v] = weight[u] + w[u][v];
				}else if(e[u][v] + dis[u] == dis[v] && weight[u] + w[u][v] < weight[v]){
					weight[v] = weight[u] + w[u][v];
					dispre[v] = u;
				}
			}
		}
	}
	dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != INF) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v].clear();
                    Timepre[v].push_back(u);
                } else if(w[u][v] + Time[u] == Time[v]) {
                    Timepre[v].push_back(u);
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}
