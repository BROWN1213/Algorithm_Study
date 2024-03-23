#include <bits/stdc++.h>

using namespace std;

typedef struct Edge{
    int s, e, v;
    bool operator > (const Edge &temp) const{
        return v > temp.v;
    }
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;
int unionArr[10010];


void matchParent(int a, int b);
int findParent(int temp);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < M; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        PQ.push(Edge{A, B, C});
    }
    for(int i = 1; i<= N; i++){
        unionArr[i] = i;
    }

    int sum = 0;
    int result = 0;

    while(sum < N -1){
        Edge temp = PQ.top();
        PQ.pop();

        int start = temp.s;
        int end = temp.e;
        int value = temp.v;

        if(findParent(start) != findParent(end)){
            matchParent(start, end);
            sum++;
            result += value;
        }
    }

    printf("%d", result);
    return 0;
}

void matchParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a != b){
        unionArr[b] = a;
    }
}

int findParent(int temp){
    if(temp == unionArr[temp]) return temp;
    else return unionArr[temp] = findParent(unionArr[temp]);
}