#include <bits/stdc++.h>

using namespace std;


int N, M;

int input[20][20];
int Parent[1000];
bool visited[20][20];

typedef struct Edge{
    int s, e, v;
    bool operator > (const Edge &temp) const{
        return v > temp.v;
    }
}Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;


void makeGroup(int x, int y, int value);
void getBridge(int x, int y);

void matchParent(int a, int b);
int findParent(int temp);


int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i< N; i++){
        for(int j = 0; j < M; j++){
            int temp;
            scanf("%d", &temp);
            input[i][j] = -temp; //1을 -1로 저장
        }
    }
    int cnt = 1;
    for(int i = 0 ; i<N; i++){
        for(int j = 0 ; j<M; j++){
            if(input[i][j] == -1 && !visited[i][j]){
                makeGroup(i, j, cnt++);
            }
        }
    }

    // for(int i = 0 ; i<N; i++){
    //     for(int j = 0 ; j<M; j++){
    //         printf("%d ", input[i][j]);
    //     }
    //     puts("");
    // }

    for(int i = 0 ; i<N; i++){
        for(int j = 0 ; j<M; j++){
            if(input[i][j]){
                getBridge(i, j);
            }
        }
    }

    // while(!PQ.empty()){
    //     Edge temp = PQ.top();
    //     PQ.pop();
    //     printf("%d %d %d\n", temp.s, temp.e, temp.v);
    // }
    for(int i = 1; i<cnt ; i++){
        Parent[i] = i;
    }

    int sum = 0;
    int result = 0;

    while(!PQ.empty()){
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

    if(sum == cnt -2) printf("%d", result);
    else printf("-1");
    
    return 0;
}


void makeGroup(int x, int y, int value){
    if(input[x][y] == -1 && !visited[x][y]){
        input[x][y] = value;
        visited[x][y] = true;
        if(x != N-1) makeGroup(x+1, y, value);
        if(y != M-1) makeGroup(x, y+1, value);
        if(x != 0) makeGroup(x-1, y, value);
        if(y != 0) makeGroup(x, y-1, value);
    }
    return;
}

void getBridge(int x, int y){
    //오른쪽
    if(y != M-1){
        if(input[x][y+1] == 0 && input[x][y+1] != input[x][y]){
            int length = 0;
            int i = x;
            int j = y;
            bool flag = false;
            while(j<M-1){
                if(j!= y && input[i][j] == input[x][y]){
                    flag = true;
                    break;
                }
                if(input[i][j] !=0 && input[i][j] != input[x][y]){
                    break;
                }else{
                    j++;
                    length++;
                }
            }
            if(!flag && length > 2 && input[i][j]){
                PQ.push(Edge{input[x][y], input[i][j], length-1});
            }
        }
    }
    
    //아래
    if(x != N-1){
        if(input[x+1][y] == 0 && input[x+1][y] != input[x][y]){
            int length = 0;
            int i = x;
            int j = y;
            bool flag = false;
            while(i<N-1){
                if(i!= x && input[i][j] == input[x][y]){
                    flag = true;
                    break;
                }
                if(input[i][j] !=0 && input[i][j] != input[x][y]){
                    break;
                }else{
                    i++;
                    length++;
                }
            }
            if(!flag && length > 2 && input[i][j]){
                PQ.push(Edge{input[x][y], input[i][j], length-1});
            }
        }
    }
    //왼쪽
    if(y != 0){
        if(input[x][y-1] == 0 && input[x][y-1] != input[x][y]){
            int length = 0;
            int i = x;
            int j = y;
            bool flag = false;
            while(j>0){
                if(j!= y && input[i][j] == input[x][y]){
                    flag = true;
                    break;
                }
                if(input[i][j] !=0 && input[i][j] != input[x][y]){
                    break;
                }else{
                    j--;
                    length++;
                }
            }
            if(!flag && length > 2 && input[i][j]){
                PQ.push(Edge{input[x][y], input[i][j], length-1});
            }
        }
    }
    
    //위
    if(x != 0){
        if(input[x-1][y] == 0 && input[x-1][y] != input[x][y]){
            int length = 0;
            int i = x;
            int j = y;
            bool flag = false;
            while(i>0){
                if(i!= y && input[i][j] == input[x][y]){
                    flag = true;
                    break;
                }
                if(input[i][j] !=0 && input[i][j] != input[x][y]){
                    break;
                }else{
                    i--;
                    length++;
                }
            }
            if(!flag && length > 2 && input[i][j]){
                PQ.push(Edge{input[x][y], input[i][j], length-1});
            }
        }
    }

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

// 7 8
// 0 0 0 0 0 0 1 1
// 1 1 0 0 0 0 1 1
// 1 1 0 0 0 0 0 0
// 1 1 0 0 0 1 1 0
// 0 0 0 0 0 1 1 0
// 0 0 0 0 0 0 0 0
// 1 1 1 1 1 1 1 1


