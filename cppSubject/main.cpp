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

bool isPrime(long int num){
    //若一个正整数N为合数，则存在一个能整除N的数K，其中2<=K<=sqrt(N)
    if (num==2) {
        cout<<"YES";
        return true;
    }
    
    if (num%2==0) {
        cout<<"NO";
        return false;
    }
    
    if (num%3==0) {
        return false;
    }
    
    long int a = 1;
    while (a*6-1<=sqrt(num)&&a>=1) {
        
        if(num%(a*6+1)==0||num%(a*6-1)==0){
            cout<<"NO";
            return false;
        }
        a++;
    }
    cout<<"YES";
    return true;
}

int main(){
    
    long int num;
    cin >>num;
    isPrime(num);
    
}
