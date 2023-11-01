#include <bits/stdc++.h>

using namespace std;

int group[1000010];


int findGroup(int temp);
void makeGroup(int a, int b);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int i = 1;i<= N; i++){
        group[i] = i;
    }

    int x, a, b;
    for(int i =0;i<M;i++){
        scanf("%d %d %d", &x, &a, &b);
        if(x){ //check Yes or No
            if(findGroup(a) == findGroup(b)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else{
            makeGroup(a, b);
        }
    }

    return 0;
}

int findGroup(int temp){
    if(group[temp] == temp) return temp;
    return group[temp] = findGroup(group[temp]);
}

void makeGroup(int a, int b){
    a = findGroup(a);
    b = findGroup(b);
    if(a != b) group[b] = a;
    return;
}