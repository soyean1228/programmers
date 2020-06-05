#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v_str1;
    vector<string> v_str2;
    for(int i=0;i<str1.size()-1;i++){
        string s = "";
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            s = str1.substr(i,2);
            std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::toupper(c); } );
            // cout << s << endl;
            v_str1.push_back(s);
        }
    }
    cout << endl;
    for(int i=0;i<str2.size()-1;i++){
        string s = "";
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            s = str2.substr(i,2);
            std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::toupper(c); } );
            // cout << s<< endl;
            v_str2.push_back(s);
        }
    }
    cout << endl;
    
    if( v_str1.size()==0 && v_str2.size() == 0){return 65536;}
    
    std::sort(v_str1.begin(), v_str1.end());
    std::sort(v_str2.begin(), v_str2.end());
    
    vector<string> v_intersection;
    std::set_intersection(v_str1.begin(), v_str1.end(),
                          v_str2.begin(), v_str2.end(),
                          std::back_inserter(v_intersection));
    // for(int i=0;i<v_intersection.size();i++){
    //     cout << v_intersection[i] << endl;
    // }
    int intersection_num = v_intersection.size();
    
    vector<string> v_union;
    std::set_union(v_str1.begin(), v_str1.end(),
                          v_str2.begin(), v_str2.end(),
                          std::back_inserter(v_union));
    // for(int i=0;i<v_union.size();i++){
    //     cout << v_union[i] << endl;
    // }
    int union_num = v_union.size();
    // cout << intersection_num << endl;
    // cout << union_num << endl;
    double f_n = (double)intersection_num/union_num;
    // cout << f_n << endl;
    // cout << f_n * 65536 << endl;
    answer = f_n * 65536;
    return answer;
}