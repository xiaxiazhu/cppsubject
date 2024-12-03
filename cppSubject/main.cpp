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

long int cnmFunction(int n ,int m){
    
//    cout <<factorial(n)<<"\n";
//    cout<< factorial(m)<<"\n";
//    cout<< factorial(n-m)<<"\n";
    return (
             factorial(n)     /
            (factorial(m)*factorial(n-m)));
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<cnmFunction(n,m);
}
