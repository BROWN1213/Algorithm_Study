#include <bits/stdc++.h>

using namespace std;


int N, M;
vector<int> Tree[50010];
int Depth[50010];
int Parent[50010];
bool Visited[50010];

void BFS(int node);
int LCA(int a, int b);


int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N-1 ; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        Tree[s].push_back(e);
        Tree[e].push_back(s);
    }

    BFS(1);

    scanf("%d", &M);
    for(int i = 0 ; i< M ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    Visited[node] = true;

    int level = 1;
    int size = 1;
    int cnt = 0;

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(auto next: Tree[now]){
            if(!Visited[next]){
                Visited[next] = true;
                Q.push(next);
                Parent[next] = now;
                Depth[next] = level;
            }
        }
        cnt++;
        if(cnt == size){
            cnt = 0;
            size = Q.size();
            level++;
        }
    }
}

int LCA(int a, int b){
    if(Depth[a] < Depth[b]){
        swap(a, b);
    }
    while(Depth[a] != Depth[b]){
        a = Parent[a];
    }
    while(a != b){
        a = Parent[a];
        b = Parent[b];
    }
    return a;
}