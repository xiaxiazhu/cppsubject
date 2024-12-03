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

long int factorial( int n){
    
    if (n==1||n==0) {
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int main(){
    //求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!）
    int n;
    cin>>n;
    int sum = 0 ;
    
    for (int i = 1 ; i<=n; i++) {
        sum+=factorial(i);
    }
    cout <<sum;
}
