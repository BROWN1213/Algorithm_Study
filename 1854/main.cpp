#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> edge;

vector<edge> V[1010];
priority_queue<int> Dist[1010]; //거리 PQ (최댓값이 가장 위- > K번째 출력 위함)
priority_queue<edge, vector<edge>, greater<edge>> PQ; // 엣지 구할떄

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0 ; i < M ; i++){
        int u, v, e;
        scanf("%d %d %d", &u, &v, &e);
        V[u].push_back(make_pair(v, e));
    }

    PQ.push(make_pair(0, 1));
    Dist[1].push(0);

    while(!PQ.empty()){
        auto now = PQ.top();
        int now_edge = now.first;
        int now_node = now.second;
        PQ.pop();
        for(auto next:V[now_node]){
            int next_node = next.first;
            int next_edge = next.second;
            if(Dist[next_node].size() < K){ //K개 미만 -> 무조건 추가
                Dist[next_node].push(now_edge + next_edge);
                PQ.push(make_pair(now_edge + next_edge, next_node));
            }else if(Dist[next_node].top() > now_edge+next_edge){
                // K개 일때 -> 최솟값일 경우에만 추가, 그 전 최댓값 pop
                Dist[next_node].pop();
                Dist[next_node].push(now_edge + next_edge);
                PQ.push(make_pair(now_edge + next_edge, next_node));
            }
        }
    }
    for(int i = 1 ; i<= N; i++){
        if(Dist[i].size() == K) printf("%d\n", Dist[i].top());
        else printf("-1\n");
    }
    return 0;
}