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

int main(){
    //两个相差为2的素数称为素数对，如5和7，17和19等，要求找出给定范围内所有的素数对。
    int min,max;
    cin>>min>>max;
    
    // 找在primevector中的出素数
    //埃拉托斯特尼筛法
    if (min>=max) {
        cout<<"empty";
        return -1;
    }
    vector<bool> isPrime(max+1,true);
    
    isPrime[0]=false;isPrime[1]=false;
    
    for (int i=2; i*i<=max; i++) {
        // 2 以及2的倍数不是prime
        //isPrime[2]=true;
        if (isPrime[i]) {
            for (int j = i*i; j<=max; j+=i) {
                isPrime[j]=false;
            }
        }
    }
    
    // 输出相差为2的素数对
    
    for (int p=min; p<isPrime.size(); p++) {
        if (isPrime[p]) {
            if (isPrime[p+2]) {
                cout<< p <<" " <<p+2<<"\n";
            }
        }
    }
}
