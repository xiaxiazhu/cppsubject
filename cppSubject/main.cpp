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

bool isWanquanNum(int n){
    
    int yueshuSum = 0;
    for (int i = 1; i<n; i++) {
        if (n%i==0) {
            yueshuSum+=i;
        }
    }
    return yueshuSum == n;
}

int main(){
    // 完全数：28 的约数是 1，2，4，7，14，并且 1+2+4+7+14=28，所以 28 是完全数。
    
    int min,max;
    
    cin>>min>>max;
    
    bool isNo = true;
    
    for (int i = min; i<=max; i++) {
        if(isWanquanNum(i)){
            isNo=false;
            cout<<std::uppercase<<std::hex<<i<<" ";
        }
    }
    if (isNo) {
        cout<<"no";
    }
    
}
