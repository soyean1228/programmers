#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    int num = 0;
    vector<int> result;
    vector<int> minusNum;
    
    for(int i=0;i<moves.size();i++){
        //moves의 횟수만큼
        int m = moves[i];
        for(int j=0;j<n;j++){
            vector<int> v = board[j];
            int a = v[m-1];
            if(v[m-1] != 0){
                result.push_back(v[m-1]);
                v[m-1] = 0;
                board[j] = v;
                break;
            }
        }
        
//         cout<<"result 출력"<<endl;
//         for(int a=0;a<result.size();a++){
//             cout<<result[a];
//         }
//         cout<<endl;
        
//         for(int a=0;a<n;a++){
//             vector<int> c = board[a];
//             for(int b=0;b<n;b++){
//                 cout<<c[b];
//             }
//             cout<<endl;
//         }
//         cout<<endl;
    }
    bool isRight = false;
    while(isRight == false){
        int i=0;
        for(i=0;i<result.size();i++){
            //cout << result[i] << "~~"<<result[i+1] << endl;
            if(result[i] == result[i+1]){
                result.erase(result.begin()+i,result.begin()+i+2);
                num = num + 2;
                // cout<<"result 출력"<<endl;
                // for(int a=0;a<result.size();a++){
                //     cout<<result[a];
                // }
                // cout<<endl;
                break;
            }   
        }
        if(i==result.size()){
            isRight = true;
        }
    }
    // cout<<endl; cout<<"result 출력"<<endl;
    // for(int a=0;a<result.size();a++){
    //     cout<<result[a];
    // }
    // cout<<endl;
    return num;
}