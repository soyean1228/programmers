#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i=123;i<987;i++){
        int num = i;
        int f_num = num / 100; num = num % 100;
        int s_num = num / 10 ; num = num % 10;
        int t_num = num;
        if(f_num == 0 || s_num == 0 || t_num == 0 || f_num == s_num || f_num == t_num || t_num == s_num){ continue; }
        bool right = true;
        for(int j=0;j<baseball.size();j++){
            vector<int> v = baseball[j];
            int target_num = v[0];
            int target_strike = v[1]; int target_ball = v[2];
            int num_strike = 0; int num_ball = 0;
            int target_f_num = target_num / 100; target_num = target_num % 100;
            int target_s_num = target_num / 10 ; target_num = target_num % 10;
            int target_t_num = target_num;
            if( target_f_num == f_num ){ num_strike++; }
            if( target_s_num == s_num ){ num_strike++; }
            if( target_t_num == t_num ){ num_strike++; }
            if( num_strike != target_strike ){ right = false; break; }
            if( target_f_num == s_num ) {num_ball++;} 
            if( target_f_num == t_num ) {num_ball++;} 
            if( target_s_num == f_num ) {num_ball++;} 
            if( target_s_num == t_num ) {num_ball++;} 
            if( target_t_num == s_num ) {num_ball++;} 
            if( target_t_num == f_num ) {num_ball++;} 
            if( num_ball != target_ball ) { right = false; break; }
        }
        if(right == true){ cout << i << endl; answer++;}
    }
    return answer;
}