#include <bits/stdc++.h>

using namespace std; 

typedef tuple<int, int, int> edge;

vector<edge> V;
priority_queue<edge, vector<edge>, greater<edge>> PQ;

long Dist[100];
long Gain[100];


int main(){

    int N, M, start, end;
    scanf("%d %d %d %d", &N, &start, &end, &M);
    for(int i = 0 ; i < M ; i++){
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        V.push_back(make_tuple(u, v, cost));
    }
    for(int i = 0; i< N; i++){
        scanf("%ld", &Gain[i]);
        Dist[i] = LONG_MIN;
    }

    Dist[start] = Gain[start];

    for(int i = 0; i <= N +50; i++){
        for(int j = 0; j < M; j++){
            edge now = V[j];
            int left = get<0>(now);
            int right = get<1>(now);
            int value = get<2>(now);
            if(Dist[left] == LONG_MIN) continue; //미연결 노드
            
            else if(Dist[left] == LONG_MAX) Dist[right] = LONG_MAX;
            
            else if(Dist[right] < Dist[left] - value + Gain[right]){
                Dist[right] = Dist[left] - value + Gain[right];


                if(i >= N -1){ //이미 한번씩 돌은 상태에서 최댓값이 갱신되는 경우 -> 양수 사이클
                    Dist[right] = LONG_MAX; 
                }
            }

        }
    }
    if(Dist[end] == LONG_MAX){
        printf("Gee");
    }
    else if(Dist[end] == LONG_MIN){
        printf("gg");
    }else{
        printf("%ld", Dist[end]);
    }   
    return 0;
}