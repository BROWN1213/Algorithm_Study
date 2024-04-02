#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int MOD = 1000000007;
vector<long> Tree;

void setTree(int size);
void changeVal(int index, long val);
void printMul(int start, int end);


int main(){
    scanf("%d %d %d", &N, &M, &K);
    
    int Height = 0;
    int Length = N;

    while(Length){
        Length /= 2;
        Height++;
    }

    int Size = int(pow(2, Height+1));
    int StartIndex = Size/2 -1;

    Tree.resize(Size + 1);
    fill(Tree.begin(), Tree.end(), 1);

    for(int i = StartIndex + 1 ; i <= StartIndex + N; i++){
        scanf("%ld", &Tree[i]);
    }

    setTree(Size-1);

    for(int i = 0; i < M + K ; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1){
            changeVal(StartIndex + b, c);
        }else if (a == 2){
            printMul(b + StartIndex, c + StartIndex);
        }
    }

    return 0;
}

void setTree(int size){
    while(size != 1){
        Tree[size/2] = Tree[size/2]* Tree[size] % MOD;
        size--;
    }
}

void changeVal(int index, long val){
    Tree[index] = val;

    while(index > 1){
        index /= 2;
        Tree[index] = Tree[index * 2] % MOD * Tree[index *2 +1] % MOD;
    }
}


void printMul(int start, int end){
    long Mul = 1;

    while(start <= end){
        if(start % 2 == 1) Mul = Mul *Tree[start++] %MOD;
        if(end % 2 == 0) Mul = Mul * Tree[end--] % MOD;
        start /= 2;
        end /= 2;
    }
    printf("%ld\n", Mul);
}