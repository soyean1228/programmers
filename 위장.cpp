#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,string> m;
    map<string,int> num;
    for(int i=0;i<clothes.size();i++){
        vector<string> tmp = clothes[i];
        m[tmp[0]] = tmp[1];
        if(num.find(tmp[1]) != num.end()){
            //없다면 
            num[tmp[1]] = num[tmp[1]]+1;
        }else{ num[tmp[1]]++;}
    }
    // map<string,string>::iterator iter = m.begin();
    int sum;
    // for(iter = m.begin(); iter!=m.end();iter++){
    //     if(iter == m.begin()){
    //         sum = (iter -> second)+1;
    //     }else{
    //         sum = sum * ((iter -> second)+1);
    //     }
    //     // cout << iter->first <<" "<< iter->second << endl;
    // }
    map<string,int>::iterator a = num.begin();
    for(a = num.begin(); a!=num.end();a++){
        // cout << a->first <<" "<< a->second << endl;
        if(a == num.begin()){
            sum = (a -> second)+1;
        }else{
            sum = sum * ((a -> second)+1);
        }
    }
    cout << sum -1 <<endl;
    return sum-1;
}