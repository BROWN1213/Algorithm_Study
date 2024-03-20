#include <bits/stdc++.h>

using namespace std;

long Dist[110][110];

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N ; j++){
            Dist[i][j] = (i==j) ? 0 : 100000001;
        }
    }
    
    for(int i = 0 ; i < M ; i ++){
        int u, v, e;
        scanf("%d %d %d", &u, &v, &e);
        if(Dist[u][v] > e) Dist[u][v] = e;
    }
    for(int t =  1; t<=N; t++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if( Dist[i][j] > Dist[i][t] + Dist[t][j]) Dist[i][j] = Dist[i][t]+Dist[t][j]; //작은 경우 갱신
            }
        }
    }
     
    for(int i = 1; i<= N ;i++){
        for(int j = 1; j <= N ; j++){
            if(Dist[i][j] == 100000001) printf("0 ");
            else printf("%d ", Dist[i][j]);
        }
        puts("");
    }

    return 0;
}