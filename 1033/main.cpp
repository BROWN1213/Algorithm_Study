#include <bits/stdc++.h>

using namespace std;

int N;
int a, b, p, q;
vector<tuple<int, int, int>> V[20];
long LCM = 1;
bool visited[20];
long answer[20];

long getGcd(long x, long y);
void getLcm(long x, long y);
void DFS(int node);

int main(){
    scanf("%d", &N);
    
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d %d",&a, &b, &p, &q);
        V[a].push_back(make_tuple(b, p, q));
        V[b].push_back(make_tuple(a, q, p));
        getLcm(p, q);
    }
    // printf("%d", LCM);

    answer[0] = LCM;
    DFS(0);
    
    long gcd = answer[0];
    for(int i =1;i<N;i++){
        gcd = getGcd(gcd, answer[i]);
    }
    //printf("%d\n", gcd);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", answer[i]/ gcd);
    }
    return 0;
}

long getGcd(long x, long y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return getGcd(y, x % y);
    }
}

void getLcm(long x, long y)
{
    LCM *= (x * y / getGcd(x, y));
}

void DFS(int node){
    visited[node] = true;

    for(tuple<int, int, int> i : V[node]){
        int next = get<0>(i);
        if(!visited[next]){ //다음 방문할 노드를 아직 방문아지 않은 경우
            answer[next] = answer[node] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }

}