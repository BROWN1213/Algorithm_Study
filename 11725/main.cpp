#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> V[100010];

bool Visited[100010];
int Parent[100010];

void dfs(int now);

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N - 1 ; i ++){
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i = 1; i<= N ; i++){
        sort(V[i].begin(), V[i].end());
    }

    dfs(1);

    for(int i = 2; i<= N;  i++){
        printf("%d\n", Parent[i]);
    }

    return 0;
}

void dfs(int now){
    Visited[now] = true;
    for(auto next:V[now]){
        if(Visited[next]) continue;
        Parent[next] = now;
        dfs(next);
    }

    return;
}