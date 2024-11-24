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
using namespace std;


int main() {
    
    int decimalNum;
    int r;
    
    cin >> decimalNum >>r;
    
    bool isNegetive = false;
    
    if (decimalNum<0) {
        isNegetive=true;
        decimalNum = -decimalNum;
    }
    
    const char dic[]= "0123456789ABCDEFG";

    int temp=0;
    string result = "";
    
    
    while (decimalNum >0) {
        temp = decimalNum%r;
        result += dic[temp];
        decimalNum = decimalNum/r;
    }
    
    reverse(result.begin(),result.end());
    
    string t = isNegetive ? "-" :"" ;
    cout<<t<< result;
    
    return 0;
}
