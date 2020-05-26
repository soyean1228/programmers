#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isCheck(string target, vector<string> already){
    for(int i=0;i<already.size();i++){
        string tmp = already[i];
        if(tmp == target){continue;}
        if(target.find(tmp)==0){
            cout << "1 " << endl;
            return true;
        }
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> already;
    for( int i = 0;i < phone_book.size(); i++ ){
        already.push_back(phone_book[i]);   
    }
    for( int i = 0;i < phone_book.size(); i++ ){
        if(isCheck(phone_book[i],already)){
            cout << phone_book[i] << endl;
            return false;
        }
    }
    return true;
}