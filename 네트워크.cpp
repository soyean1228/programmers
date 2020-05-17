#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check[200];

void dfs(int start, vector<vector<int>> &computers, int n){
    check[start] = 1;
    for(int i=0;i<n;i++){
        if(!check[i] && computers[start][i]){
            dfs(i, computers, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(check[i] == false){
            answer++;
            dfs(i,computers,n);
        }
    }
    return answer;
}