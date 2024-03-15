#include <bits/stdc++.h>
#define INF INT_sMAX

using namespace std;

typedef pair<int, int> edge;
vector<edge> V[1010];
priority_queue<edge, vector<edge>, greater<edge>> PQ; //오름차순 정렬
bool visited[1010];
int dist[1010];



int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int u, v, w;
    for(int i = 0 ; i<M ; i++){
        scanf("%d %d %d", &u, &v, &w);
        V[u].push_back(make_pair(v, w));
    }
    int start, end;
    scanf("%d %d", &start, &end);

    for(int i = 0; i<=N ; i++){
        dist[i] = INF;
    }
    PQ.push(make_pair(0, start));
    dist[start] = 0;
    while(!PQ.empty()){
        edge now = PQ.top();
        PQ.pop();
        if(visited[now.second]) continue;
        visited[now.second] = true;
        for(auto next:V[now.second]){
            if(dist[next.first] > next.second + dist[now.second]){
                dist[next.first] = next.second + dist[now.second];
                PQ.push(make_pair(dist[next.first], next.first));
            }
        }
    }

    printf("%d", dist[end]);

    return 0;
}