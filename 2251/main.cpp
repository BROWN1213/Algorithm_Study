#include <bits/stdc++.h>

using namespace std;

int input[3];
int fromBottle[6] = {0, 0, 1, 1, 2, 2};
int toBottle[6] = {1, 2, 0, 2, 0, 1};  //A->B, A->C, B->A, B->C, C->A, C->B
bool check[210][210];
queue<pair<int, int>> Q;
vector<int> V;

int sum = 0;

int main(){
    scanf("%d %d %d", input, input+1, input+2);
    
    sum = input[2];
    Q.push(make_pair(0, 0));
    check[0][0] = true;
    V.push_back(input[2]);
    while(!Q.empty()){
        int a = Q.front().first;
        int b = Q.front().second;
        int c = sum - a - b;
        Q.pop();
        for(int i = 0;i<6;i++){
            int next[3] = {a, b, c};
            next[toBottle[i]] += next[fromBottle[i]];
            next[fromBottle[i]] = 0;
            if(next[toBottle[i]] > input[toBottle[i]]){
                int temp = next[toBottle[i]] - input[toBottle[i]];
                next[fromBottle[i]] += temp;
                next[toBottle[i]] -= temp;
            }
            if (!check[next[0]][next[1]]){
                check[next[0]][next[1]] = true;
                Q.push(make_pair(next[0], next[1]));
                if(next[0] == 0){
                    V.push_back(next[2]);
                }
            }
        }
    }
    sort(V.begin(), V.end());
    for(int i : V){
        printf("%d ", i);
    }

    return 0;
}