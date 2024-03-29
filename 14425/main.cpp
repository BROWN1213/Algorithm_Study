// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node{
public:
    Node* next[26];
    bool isEnd;

    Node() : isEnd(false){
        fill(next, next+26, nullptr);
    }

    ~Node(){
        for (auto& child : next){
            delete child;
        }
    }

    void insert(const char *key){
        if (*key == 0) isEnd = true;
        else{
            int next_index = *key - 'a';
            if(next[next_index] == nullptr) next[next_index] = new Node();
            next[next_index] -> insert(key+1);
        }
    }

    Node* find(const char *key){
        if (*key == 0) return this;
        int next_index = *key - 'a';
        if(next[next_index] == nullptr) return nullptr;
        return next[next_index] -> find(key+1);

    }
};


int N, M;
int cnt = 0;


int main(){
    Node* root = new Node();
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i< N ; i++){
        char input[510];
        scanf("%s", input);
        root -> insert(input);
    }
    for(int i = 0 ; i< M ; i++){
        char output[510];
        scanf("%s", output);
        Node *result = root -> find(output);
        if(result && result -> isEnd) cnt++;
    }


    printf("%d", cnt);

    return 0;
}