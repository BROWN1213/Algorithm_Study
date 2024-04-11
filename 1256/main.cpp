#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long DP[210][210];

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0 ; i<= 200 ;i++){
        for(int j = 0; j<= i; j++){
            if(j == 0 || i == j){
                DP[i][j] = 1;
            }else{
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
                if(DP[i][j] > 1000000000) DP[i][j] = 1000000001;
            }
        }
    }

    if(DP[N+M][M] < K){
        printf("-1");
        return 0;
    }
    while(!(N == 0 && M == 0)){
        if(DP[N+M-1][M] >= K){
            printf("a");
            N--;
        }else{
            printf("z");
            K -= DP[N+M -1][M];
            M--;
        }
    }

    return 0;
}