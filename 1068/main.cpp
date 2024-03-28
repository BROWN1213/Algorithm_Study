#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> V[100];
int rootNode, DeleteNode;

int cnt = 0;

void dfs(int now);

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        int temp;
        scanf("%d", &temp);
        if(temp == -1) rootNode = i;
        else V[temp].push_back(i);      
    }
    scanf("%d", &DeleteNode);

    if(DeleteNode != rootNode) dfs(rootNode);

    printf("%d", cnt);
    return 0;
}

void dfs(int now){
    bool flag = false;
    for(int next:V[now]){
        if(next == DeleteNode) continue;
        dfs(next);
        flag = true;
    }
    if(!flag){
        cnt++;
    }
    return;
}