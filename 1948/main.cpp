#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> temp[10010];
vector<pair<int, int>> V[10010]; //입력을 역방향으로 받음 1-> 2 : 3 을 2 <- 1 : 3으로 저장
int arr1[10010]; //자신을 가리키는 노드 수
int dist[10010];
queue<int> Q;
bool visited[10010];
int cnt = 0;


int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int input[3];
    for(int i = 0; i< M; i++){
        scanf("%d %d %d", input, input+1, input+2);
        //printf("%d %d %d\n", input[0], input[1], input[2]);
        temp[input[0]].push_back(make_pair(input[1],input[2]));
        V[input[1]].push_back(make_pair(input[0], input[2]));
        arr1[input[1]]++;
    }
    int start, end;
    scanf("%d %d", &start, &end);

    Q.push(start);
    while(!Q.empty()){
        int front = Q.front();
        Q.pop();
        for(auto i:temp[front]){
            arr1[i.first]--;
            dist[i.first] = max(dist[front]+i.second, dist[i.first]);
            if(arr1[i.first]==0) Q.push(i.first);
        }
    }

    Q.push(end);
    while(!Q.empty()){
        int front = Q.front();
        Q.pop();
        for(auto i:V[front]){
            if(dist[i.first]+i.second == dist[front]){
                cnt++;
                if(!visited[i.first]){
                    Q.push(i.first);
                    visited[i.first] = true;
                }
            }
        }

    }

    printf("%d\n%d", dist[end], cnt);

    return 0;
}