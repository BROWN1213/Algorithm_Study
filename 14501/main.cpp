#include <bits/stdc++.h>

using namespace std;

int N;
int T[20];
int P[20];

int DP[20];


int main(){
    scanf("%d", &N);
    for(int i = 1; i<= N; i++){
        scanf("%d %d", &T[i], &P[i]);
    }
    for(int i = N; i>0 ;i--){
        DP[i] = DP[i + 1];
        if(i+T[i] > N +1) continue;
        DP[i] = max(DP[i], DP[i+T[i]] + P[i]);
    }

    printf("%d", DP[1]);

    return 0;
}