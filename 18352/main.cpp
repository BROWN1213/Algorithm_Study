#include <bits/stdc++.h>

using namespace std;

vector<int> V[300010];
queue<int> Q;
int visited[300010];
int answer[300010];
int anstemp = 0;
int main(){
    int N, M, K, X;
    int A, B;
    scanf("%d %d %d %d", &N, &M, &K, &X);
    for(int i = 0;i < M ;i++){
        scanf("%d %d", &A, &B);
        V[A].push_back(B);
    }
    for(int i = 0; i<=N ;i++){
        visited[i] = -1;
    }
    visited[X] = 0;
    Q.push(X);
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(int dest:V[temp]){
            if(visited[dest]==-1){
                visited[dest] = visited[temp] + 1;
                Q.push(dest);    
            }
        }
    }
    for(int i = 1;i <=N; i++){
        if(visited[i] == K){
            answer[anstemp++] = i;
        }
    }
    for(int i = 0; i<anstemp; i++){
        printf("%d\n",answer[i]);
    }
    if(anstemp == 0){
        printf("-1");
    }
    return 0;
}