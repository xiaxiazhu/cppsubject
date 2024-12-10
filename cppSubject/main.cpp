//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

int main(){
    
    //    a#abcd#xyz#efgh#opq
    
    string inputStr;
    
    getline(cin, inputStr);
        
    vector<int> xulie;
    
    for (int i = 0 ; i<inputStr.size(); i++) {
        if (inputStr[i]=='#') {
            xulie.push_back(i);
        }
    }
    
    string result;
    for (int k = 0 ; k<xulie.size(); k+=2) {
        result += inputStr.substr(xulie[k]+1,xulie[k+1]-xulie[k]-1);
    }
    
    cout<<result;
    return 0;
}
