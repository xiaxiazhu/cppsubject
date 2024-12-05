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
    
bool ishuiwen(string nStr){
    
    string fanStr=nStr ;

    reverse(nStr.begin(),nStr.end());

    if (nStr ==fanStr) {
        return true;
    }else{
        return false;
    }
}

int main(){
    
    string testString;
    
    getline(cin, testString);
    
    if(ishuiwen(testString)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    
    return 0;
}
