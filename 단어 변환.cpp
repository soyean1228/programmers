#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 100;
bool check[50];

bool isChange(string a, string b){
    int d = 0; //다른 것의 개수 
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) { d++; }
    }
    if(d == 1){return true;}
    return false;
}

void dfs(string begin, string target, vector<string> words, int count){
    for(int i=0;i<words.size();i++){
        if(!check[i] && isChange(words[i],begin)){
            if(target == words[i]){
                answer = count + 1;
                return;
            }
            check[i] = true;
            if(count+1 < answer){
                count++;
                cout << begin <<"  "<<words[i] << count << endl;
                dfs(words[i],target,words,count);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target)==words.end()){return 0;}
    for(int i=0;i<50;i++){check[i] = false;}
    dfs(begin,target,words,0);
    cout << answer << endl;
    if(answer == -1){return 0;}
    return answer;
}