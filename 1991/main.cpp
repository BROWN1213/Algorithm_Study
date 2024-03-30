#include <bits/stdc++.h>

using namespace std;


int N;
int arr[30][2];


void preorder(int now);
void inorder(int now);
void postorder(int now);


int main(){
    scanf("%d", &N);
    
    for(int i = 0 ; i< N ; i++){
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        int cursur = a - 'A';
        if(b == '.'){
            arr[cursur][0] = 0;
        }else if(b != '.'){
            arr[cursur][0] = b - 'A';
        }
        if(c == '.'){
            arr[cursur][1] = 0;
        }else if(c != '.'){
            arr[cursur][1] = c - 'A';
        }
    }
    // for(int i = 0 ; i < N ; i++){
    //     printf("%d %d\n", arr[i][0], arr[i][1]);
    // }
    
    //left : 0 right : 1
    preorder(0);
    puts("");
    inorder(0);
    puts("");
    postorder(0);
    puts("");

    return 0;
}

void preorder(int now){
    printf("%c", now+'A');
    if(arr[now][0]) preorder(arr[now][0]);
    if(arr[now][1]) preorder(arr[now][1]);
    return;
}

void inorder(int now){
    if(arr[now][0]) inorder(arr[now][0]);
    printf("%c", now + 'A');
    if(arr[now][1]) inorder(arr[now][1]);
    return;
}

void postorder(int now){
    if(arr[now][0]) postorder(arr[now][0]);
    if(arr[now][1]) postorder(arr[now][1]);
    printf("%c", now + 'A');
    return;
}