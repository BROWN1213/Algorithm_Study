#include <bits/stdc++.h>

using namespace std;

int Group[60];
vector<int> turthParty;
vector<int> Party[60];

void matchParent(int a, int b);
int findParent(int temp);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int truthCount;
    scanf("%d", &truthCount);
    for(int i = 0; i < truthCount; i++){
        int temp;
        scanf("%d", &temp);
        turthParty.push_back(temp);
    }
    for(int i = 0; i < M; i++){
        int temp, temp1;
        scanf("%d", &temp);
        for(int j = 0; j< temp ; j++){
            scanf("%d", &temp1);
            Party[i].push_back(temp1);
        }
    }
    for(int i = 0; i< N; i++){
        Group[i] = i;
    }
    for(int i = 0 ; i<M; i++){
        bool flag = true;
        int firsttemp;
        for(int temp: Party[i]){
            if(flag){
                firsttemp = temp;
                flag = false;
                continue;
            }
            matchParent(firsttemp, temp);
        }
    }
    int res= 0;
    for(int i = 0; i < M; i++){
        bool flag = true;
        if(truthCount != 0){
            int firsttemp = findParent(Party[i].front());
            for (int temp : turthParty)
            {
                if (firsttemp == findParent(temp))
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            res++;
        }
    }
    printf("%d", res);

    return 0;
}

void matchParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if(a != b){
        Group[b] = a;
    }
}

int findParent(int temp)
{
    if (Group[temp] == temp)
        return temp;
    return Group[temp] = findParent(Group[temp]);
}