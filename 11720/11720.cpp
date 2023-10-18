#include <bits/stdc++.h>

int N;
int sum = 0;
char temp[110];

int main(){
    scanf("%d", &N);
    scanf("%s", &temp);
    for(int i = 0;i<N;i++){
        sum += int(temp[i])-'0';
    }
    printf("%d", sum);

    return 0;
}