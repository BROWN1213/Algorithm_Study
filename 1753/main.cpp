#include <bits/stdc++.h>

#define INF INT_MAX;

using namespace std;

typedef pair<int, int> edge;
vector<edge> V[20010];
int dist[20010];
bool visited[20010];
priority_queue<edge, vector<edge>, greater<edge>> PQ;

int main(){
    int N, M;
    int start;

    scanf("%d %d", &N, &M);
    scanf("%d", &start);

    int u, v, w;
    for(int i = 0 ;i < M ;i++){
        scanf("%d %d %d", &u, &v, &w);
        V[u].push_back(make_pair(v, w));
    }

    for(int i = 0 ; i<=N; i++){
        dist[i] = INF;
    }

    PQ.push(make_pair(0, start));
    dist[start] = 0;

    while(!PQ.empty()){
        auto now = PQ.top();
        PQ.pop();
        if(visited[now.second]) continue;
        visited[now.second] = true;
        for(auto next:V[now.second]){
            if (dist[next.first] > now.first + next.second){
                dist[next.first] = now.first + next.second;
                PQ.push(make_pair(dist[next.first], next.first));
            }
        }
    }
    for(int i = 1; i<= N; i++){
        if(visited[i]) printf("%d\n", dist[i]);
        else printf("INF\n");
    }
    return 0;
}