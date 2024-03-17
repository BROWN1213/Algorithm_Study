#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edge;


vector<edge> V;
long Dist[510];

int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0 ; i< M; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        V.push_back(make_tuple(A, B, C));
    }
    for(int i = 0 ; i<=N; i++){
        Dist[i] = LONG_MAX;
    }

    Dist[1] = 0;

    for(int i = 1; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            edge now = V[j];
            int start = get<0>(now);
            int end = get<1>(now);
            int time = get<2>(now);

            if(Dist[start] != LONG_MAX && Dist[end] > Dist[start] + time) Dist[end] = Dist[start] + time;
        }
    }
    
    bool flag = false;

    for(int i = 0; i < M ; i++){
        
        edge now = V[i];
        int start = get<0>(now);
        int end = get<1>(now);
        int time = get<2>(now);

        if(Dist[start] != LONG_MAX && Dist[end] > Dist[start] + time) flag = true;
    
    }

    if(flag){
        printf("-1");
    }else{
        for(int i = 2; i <= N; i++){
            if(Dist[i] == LONG_MAX) printf("-1\n");
            else printf("%d\n", Dist[i]);
        }

    }

    return 0;
}