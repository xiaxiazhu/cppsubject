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

//
//输入一个整数，求其各位数的数字和
int zhengshuSum(long int value){
    
    int n =0;

    while (value>0) {
        
        n +=value%10;
        
        value=value/10;
    }
    
    return n;
}

int main(){
    long int _value;
    cin>>_value;
    cout<< zhengshuSum(_value);
    
    return 1;
}
