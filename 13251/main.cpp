#include <bits/stdc++.h>

using namespace std;

int M, K;
int arr[60];
double Possible[60];

int sum = 0;
double ans = 0;

int main(){
    scanf("%d", &M);
    for(int i = 0 ; i< M ; i++){
        scanf("%d", &arr[i]);
        sum +=arr[i];
    }
    scanf("%d", &K);
    for(int i = 0 ; i< M; i++){
        if(arr[i] >= K){
            Possible[i] = 1.0;
        }
        for(int j = 0 ;j < K ; j++){
            Possible[i] = Possible[i] * ((double)(arr[i]-j) / (sum-j));
        }
        ans += Possible[i];
    }

    printf("%.9f", ans);

    return 0;
}