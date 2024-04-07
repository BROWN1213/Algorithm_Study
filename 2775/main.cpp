#include <bits/stdc++.h>

using namespace std;

int DP[20][20];

int T;
int K, N;

int main(){
    scanf("%d", &T);
    while(T){
        T--;
        scanf("%d" ,&K);
        scanf("%d" ,&N);
        for(int i = 1; i<=N; i++){
            DP[0][i] = i;
        }
        for(int i = 1; i<= K; i++){
            for(int j = 1; j<= N ;j ++){
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }
        printf("%d\n", DP[K][N]);
    }




    return 0;
}