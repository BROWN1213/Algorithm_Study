#include <bits/stdc++.h>

using namespace std;

int N, K;

int dp[1010][1010];

int main(){
    scanf("%d %d", &N, &K);

    
    for(int i = 1; i<= N; i++){
        for(int j = 0 ;j<= N; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else if(j == 1){
                dp[i][j] = i;
            }else if(i == j){
                dp[i][j] = 1;
            }else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
            }
        }
    }

    printf("%d", dp[N][K]);
    return 0;
}