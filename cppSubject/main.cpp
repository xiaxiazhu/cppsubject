//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <stack>

using namespace std;

string check(long int n,long int d){
    string nStr = to_string(n);
    if (nStr.find(to_string(d))!=string::npos) {
        return "true";
    }else{
        return "false";
    }
}

int main(){
    
    long int n,d;
    cin>>n>>d;
    
    cout<<check(n,d);
}
