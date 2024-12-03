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

int digtalSum(int n){
    
    int sum=0;

    while (n>0) {
        int temp = n%10;
        sum+=temp;
        n=n/10;
    }
    return sum;
}

int findDigitalRoots(int num){
    
    int dr=0;
    dr=digtalSum(num);
    while (dr>=10) {
        dr = digtalSum(dr);
    }
    
    return dr;
}

int main(){
    //一个整数的“Digital Roots”就是这个整数的各位数字的和，如果这个和是一个一位数，则这个一位数就是这个整数的“Digital Roots”，否则的话则继续求这个和的“Digital Roots”，直到最后得出一个一位数。

    vector<int> numList;
    
    while (true) {
        int x;
        cin>>x;
        if (x!=0) {
            numList.push_back(x);
        }else{break;}
    }
    
    for (int i=0; i<numList.size(); i++) {
        
        int result = findDigitalRoots(numList[i]);
        cout<<result<<"\n";

        
    }
    
}
