#include <bits/stdc++.h>

using namespace std;

vector<int> V[510];
int buildTime[510];
int indegree[510];
int res[510];
queue<int> Q;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N ; i++){
        int temp;
        scanf("%d", &temp);
        buildTime[i] = temp;
        while(1){
            scanf("%d", &temp);
            if(temp == -1){
                break;
            }
            V[temp].push_back(i);
            indegree[i]++;
        }
    }
    for(int i = 1; i<= N; i++){
        if(indegree[i] == 0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(int nextTemp: V[temp]){
            if (--indegree[nextTemp] == 0){
                Q.push(nextTemp);
            }
            res[nextTemp] = max(res[nextTemp], res[temp]+buildTime[temp]);
        }
    }
    for(int i = 1; i<= N; i++){
        printf("%d\n", res[i] + buildTime[i]);
    }
    return 0;
}