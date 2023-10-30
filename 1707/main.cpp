#include <bits/stdc++.h>

using namespace std;

vector<int> V[20010];
bool visited[20010];
int check[20010];
bool flag = false;


void dfs(int x){
    visited[x] = true;

    for(int next:V[x]){
        if(!visited[next]){
            check[next] = (check[x]+1) %2;
            dfs(next);
        }
        else if(check[x] == check[next]){ //이분 그래프가 아닌 경우
            flag = true;
        }
        
    }
}

int main(){

    int N;
    scanf("%d", &N);
    while(N--){
        int S, E;
        scanf("%d %d", &S, &E);
        while(E--){
            int st, en;
            scanf("%d %d", &st, &en);
            V[st].push_back(en);
            V[en].push_back(st);
        }
        for(int i = 1;i <= S; i++){
            if(flag) break;
            dfs(i);
        }
        if(flag){
            printf("NO\n");
            
        }else{
            printf("YES\n");
        }
        for(int i = 0; i<= S; i++){
            visited[i] = false;
            check[i] = 0;
            V[i].clear();
        }
        flag = false;
    }
    return 0;
}