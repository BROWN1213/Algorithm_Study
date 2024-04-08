#include <bits/stdc++.h>

using namespace std;

int DP[40][40];

int T, N, M;

int main(){
    for(int i = 0 ; i<= 30 ;i++){
        DP[i][1] = i;
        DP[i][0] = 1;
        DP[i][i] = 1;
    }
    for(int i = 2; i<=30 ; i++){
        for(int j = 1; j<i; j++){
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
        }
    }

    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        printf("%d\n", DP[M][N]);
    }



    return 0;
}