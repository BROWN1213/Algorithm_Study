#include <bits/stdc++.h>

using namespace std;


int N, M;
int Kmax;

vector<int> Tree[100010];
int Depth[100010];
int Parent[21][100010];
bool Visited[100010];

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
    int temp = 1;
    Kmax = 0;
    while(temp <= N){
        temp = temp << 1;
        Kmax++;
    }

    BFS(1);

    for(int k = 1 ; k<= Kmax; k++){  //N의 2^k 부모 노드 구하기 
        for(int n = 1; n <= N; n++){
            Parent[k][n] = Parent[k-1][Parent[k-1][n]];
        }
    }

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
                Parent[0][next] = now;
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
    if(Depth[a] > Depth[b]){
        swap(a, b);
    }
    for(int k = Kmax; k>= 0 ;k--){  //높이 맞추기(같은 높이로)
        if(pow(2, k) <= Depth[b] - Depth[a]){
            if(Depth[a] <= Depth[Parent[k][b]]){
                b = Parent[k][b];
            }
        }
    }

    for(int k = Kmax; k>= 0 && a!=b ;k--){  //위에서 아래로 내려오면서 부모 맞추기
        if(Parent[k][a] != Parent[k][b]){
            a = Parent[k][a];
            b = Parent[k][b];
        }
    }

    int res = a;

    if(a != b){
        res = Parent[0][res];
    }


    return res;
}