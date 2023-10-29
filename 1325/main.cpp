#include <bits/stdc++.h>

using namespace std;


vector<int> V[10010];
int trustArray[10010];
bool visited[10010];
queue<int> Q;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M ; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        V[A].push_back(B);
    }
    for(int i = 1;i <= N; i++){
        for(int j = 0; j<= N; j++){
            visited[j] = false;
        }
        Q.push(i);
        visited[i] = true;
        while(!Q.empty()){
            int current = Q.front();
            Q.pop();
            for(int next:V[current]){
                if(!visited[next]){
                    Q.push(next);
                    trustArray[next]++;
                    visited[next] = true;
                }
                
            }
        }
    }
    int maxValue = 0;
    for(int i = 1;i <= N; i++){
        maxValue = max(maxValue, trustArray[i]);
    }
    for (int i = 1; i <= N; i++){
        if(trustArray[i] == maxValue){
            printf("%d ", i);
        }
    }
    return 0;
}