#include <bits/stdc++.h>

using namespace std;

int N;
long long DP[1000010];

int main(){
    scanf("%d", &N);
    DP[1] = 0;
    DP[2] = 1;
    for(long i = 3; i <= N; i++){
        DP[i] = (i-1) * (DP[i-1] + DP[i-2]) % 1000000000;
    }
    printf("%lld", DP[N]);
    return 0;
}