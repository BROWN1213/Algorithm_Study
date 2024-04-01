#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<long> Tree;

void setTree(int size);
void printMin(int start, int end);


int main(){
    scanf("%d %d", &N, &M);
    
    int Height = 0;
    int Length = N;

    while(Length){
        Length /= 2;
        Height++;
    }

    int Size = int(pow(2, Height+1));
    int StartIndex = Size/2 -1;

    Tree.resize(Size + 1);
    fill(Tree.begin(), Tree.end(), LONG_MAX);

    for(int i = StartIndex + 1 ; i <= StartIndex + N; i++){
        scanf("%ld", &Tree[i]);
    }

    setTree(Size-1);

    for(int i = 0; i < M ; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printMin(s + StartIndex, e + StartIndex);
    }

    return 0;
}

void setTree(int size){
    while(size != 1){
        if(Tree[size/2] > Tree[size]) Tree[size/2] = Tree[size];
        size--;
    }
}

void printMin(int start, int end){
    long Min = LONG_MAX;

    while(start <= end){
        if(start % 2 == 1) Min = min(Min, Tree[start++]);
        if(end % 2 == 0) Min = min(Min, Tree[end--]);
        start /= 2;
        end /= 2;
    }
    printf("%ld\n", Min);
}