#include <bits/stdc++.h>

using namespace std;

int N, K;
long Factorial[30], Answer[30];

bool Visited[30];

int main(){
    

    scanf("%d", &N);
    Factorial[0] = 1;
    for(int i = 1 ; i <= N ; i++){
        Factorial[i] = Factorial[i-1] * i;
    }
    scanf("%d", &K);
    if(K == 1){
        long x;
        scanf("%ld", &x);
        for(int i = 1; i <= N ; i++){
            for(int j = 1, cnt = 1; j<=N; j++){
                if(Visited[j]) continue;
                
                if( x <= cnt * Factorial[N-i]){
                    x -= ((cnt-1) * Factorial[N-i]);
                    Answer[i] = j;
                    Visited[j] = true;
                    break;
                }
                cnt++;
            }
        }
        for(int i = 1; i<= N ;i++){
            printf("%d ", Answer[i]);
        }


    }else if(K == 2){
        long x = 1;
        for(int i = 1; i<= N; i++){
            scanf("%ld", &Answer[i]);

            long cnt = 0;

            for(int j = 1; j< Answer[i]; j++){
                if(!Visited[j]) cnt++;

            }
            x += cnt * Factorial[N-i];
            Visited[Answer[i]] = true;
        }
        printf("%ld", x);

        
    }

    return 0;
}