#include <bits/stdc++.h>

using namespace std;


int Dist[110][110];

int main(){ 
    int N;
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N; j++){
            scanf("%d", &Dist[i][j]);
        }
    }
    for(int k = 1 ; k <= N ; k++){
        for(int i = 1; i<= N; i++){
            for(int j = 1; j <= N; j++){
                if(Dist[i][k] && Dist[k][j]) Dist[i][j] = 1;
            }
        }
    }
    for(int i = 1; i<= N; i++){
        for(int j = 1; j<= N; j++){
            printf("%d ", Dist[i][j]);
        }
        puts("");
    }



    return 0;
}