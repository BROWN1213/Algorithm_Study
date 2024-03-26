#include <bits/stdc++.h>

using namespace std;

typedef struct Edge{
    int s, e, v;
    bool operator > (const Edge &temp) const{
        return v > temp.v;
    }
} Edge;

int N;
int sum;
int result;

char input[100][100];
int Lan[100][100];

int Parent[100];

priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

void matchParent(int a, int b);
int findParent(int temp);


int main(){
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%s", input[i]+1);
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N; j++){
            if(input[i][j] >= 'a' && input[i][j] <= 'z'){ //a~z : 1~ 26
                Lan[i][j] = input[i][j] - 'a' + 1;
                PQ.push(Edge{i, j, Lan[i][j]});
            }else if(input[i][j] >= 'A' && input[i][j] <= 'Z'){ //A~Z : 27~ 52
                Lan[i][j] = input[i][j] - 'A' + 27;
                PQ.push(Edge{i, j, Lan[i][j]});
            }else if(input[i][j] == '0'){ //미연결
                Lan[i][j] = 0;
            }
            sum += Lan[i][j];
        }
    }
    for(int i = 1 ; i<= N; i++){
        Parent[i] = i;
    }

    while(!PQ.empty()){
        Edge temp = PQ.top();
        PQ.pop();

        int start = temp.s;
        int end = temp.e;
        int value = temp.v;


        if(findParent(start) != findParent(end)){
            matchParent(start, end);
            result += value;
        }       

    }
    bool flag = false;
    for(int i = 2; i<= N; i++){
        if(findParent(1) != findParent(i)){
            flag = true;
            break;
        }
    }
    if(!flag) printf("%d", sum - result);
    else printf("-1");

    return 0;
}


void matchParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a != b){
        Parent[b] = a;
    }
}

int findParent(int temp){
    if(temp == Parent[temp]) return temp;
    else return Parent[temp] = findParent(Parent[temp]);
}