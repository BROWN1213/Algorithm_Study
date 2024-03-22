#include <bits/stdc++.h>

using namespace std;


int Friend[110][110];
int Bacon[110];

int main(){
    for(int i = 0; i <110 ; i++){
        for(int j = 0; j< 110 ;j++){
            if(i == j) continue;
            Friend[i][j] = 10000001;
        }
    }
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < M ; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        Friend[A][B] = 1;
        Friend[B][A] = 1;
    }
    for(int k = 1; k <= N ;k++){
        for(int i = 1; i<= N ; i++){
            for(int j = 1; j<= N ;j++){
                Friend[i][j] = min(Friend[i][j], Friend[i][k]+Friend[k][j]);
            }
        }
    }
    int minVal = 10000001;
    for(int i = 1; i<= N ; i++){
        int sum =0;
        for(int j = 1; j<= N ;j++){
            if(Friend[i][j] == 10000001) continue;
            sum += Friend[i][j];
        }
        Bacon[i] = sum;
        minVal = min(minVal, sum);
    }

    for(int i = 1; i<= N; i++){
        if(Bacon[i] == minVal){
            printf("%d", i);
            break;
        }
    }    
    
    return 0;
}