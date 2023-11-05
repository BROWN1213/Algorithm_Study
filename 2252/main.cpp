#include <bits/stdc++.h>

using namespace std;

vector<int> V[32010];
int indegree[32010];
queue<int> Q;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i< M ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        indegree[b]++;
    }
    for(int i = 1 ; i <= N ; i++){
        if(indegree[i] == 0 ){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        printf("%d ", temp);
        for(int nextTemp : V[temp]){
            if(--indegree[nextTemp] == 0){
                Q.push(nextTemp);
            }
        }
    }
    return 0;
}