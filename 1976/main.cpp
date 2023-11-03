#include <bits/stdc++.h>

using namespace std;

int question[1010];
int cityGroup[210];


int find(int temp);

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 1; i <= N; i++)
    {
        cityGroup[i] = i;
    }
    int x;
    for(int i = 1; i<=N;i++){
        for(int j = 1;j<=N;j++){
            scanf("%d", &x);
            if(x){
                cityGroup[find(j)] = find(i);
            }
        }
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &question[i]);
    }

    bool flag = false;
    int temp = find(question[0]);

    for (int i = 1; i <M; i++){
        if(temp != find(question[i])){
            flag = true;
            break;
        }
    }

    if(flag) printf("NO");
    else printf("YES");

    return 0;
}

int find(int temp){
    if(cityGroup[temp] == temp) return temp;
    return cityGroup[temp] = find(cityGroup[temp]);
}