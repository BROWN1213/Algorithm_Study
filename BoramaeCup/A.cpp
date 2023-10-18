#include <bits/stdc++.h>

char arr[110][1010];

int main(){
    int x, y;
    scanf("%d %d",&y, &x);
    for(int i =0;i<y;i++){
        scanf("%s",arr[i]);
    }
    // for(int i = 0;i<y;i++){
    //     for(int j = 0;j<x;j++){
    //         printf("%c ",arr[i][j]);
    //     }
    //     puts("");
    // }
//가로가 홀수 인 경우  wyw 를 가로로 넣어서 되면 됨
    if(x%2){
        for (int i = 0; i < y; i++)
        {
            int j = x / 2 - 1;
            if(j>0 && j+2<x){
                if (arr[i][j] == 'X' && arr[i][j+1] == 'X' && arr[i][j+2] == 'X'){
                    arr[i][j] = 'W';
                    arr[i][j+1] = 'Y';
                    arr[i][j+2] = 'W';
                    printf("YES\n");
                    for(int l = 0;l<y;l++){
                        for(int k = 0;k<x;k++){
                            if(arr[l][k] =='W' || arr[l][k] =='Y'){
                                printf("%c", arr[l][k]);
                            }else{
                                printf("B");
                            }
                        }
                        puts("");
                    }
                    return 0;
                }
            }
            
        }
    }else{
        for (int i = 0; i < y; i++)
        {
            int j = x/2 - 2;
                if (j > 0 && j + 3 < x)
                {
                    if (arr[i][j] == 'X' && arr[i][j + 1] == 'X' && arr[i][j + 2] == 'X' && arr[i][j+3] == 'X')
                    {
                        arr[i][j] = 'W';
                        arr[i][j + 1] = 'Y';
                        arr[i][j + 2] = 'Y';
                        arr[i][j + 3] = 'W';
                        printf("YES\n");
                        for (int l = 0; l < y; l++)
                        {
                            for (int k = 0; k < x; k++)
                            {
                                if (arr[l][k] == 'W' || arr[l][k] == 'Y')
                                {
                                    printf("%c", arr[l][k]);
                                }
                                else
                                {
                                    printf("B");
                                }
                            }
                            puts("");
                        }
                        return 0;
                    }
                }
            
        }
    }
    printf("NO\n");

    return 0;
}
/*
8 15
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
BXXXXXXXXXXXXXX
BXXXXXXXXXXXXXX
BXXXXXXXXXXXXXX
BXXXXXXXXXXXXXX
BBBBBBBBBBBBBBB
*/