#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int Height = 0;
int Length;

vector<long> Tree;

void setTree(int size);
void changeSum(int index, long val);
void printSum(int start, int end);

int main(){
    scanf("%d %d %d", &N, &M, &K);

    Length = N;
    while(Length){
        Length /= 2;
        Height++;
    }
    int Size = int(pow(2, Height+1));
    int StartIndex = Size/2 -1;

    Tree.resize(Size + 1);

    for(int i = StartIndex + 1 ; i <= StartIndex+N ; i++){
        scanf("%ld", &Tree[i]);
    }

    setTree(Size - 1);

    for(int i = 0 ; i< M+K; i++){
        long a, b, c;
        scanf("%ld %ld %ld", &a, &b, &c);
        if(a == 1){
            changeSum(StartIndex + b, c);
        }else if(a = 2){
            printSum(b + StartIndex, c + StartIndex);
        }
    }
    
    return 0;
}



void setTree(int size){
    while(size != 1){
        Tree[size / 2] += Tree[size];
        size--;
    }
}

void changeSum(int index, long val){
    long diff = val - Tree[index];

    while(index > 0){
        Tree[index] = Tree[index] + diff;
        index /= 2;
    }
}

void printSum(int start, int end){
    long Sum = 0;

    while(start <= end){
        if(start % 2 == 1) Sum += Tree[start++];
        if(end % 2 == 0) Sum += Tree[end--];
        start /= 2;
        end /= 2;
    }
    printf("%ld\n", Sum);
}