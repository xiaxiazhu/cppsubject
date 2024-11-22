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
    
    // n个人 ； m出圈；m<=n<=100;
    int n,m;
    
    cin>>n>>m;
    vector<int> basicArray;

    // 初始化数组 10 3
    for (int i=1; i<=n; i++) {
        basicArray.push_back(i);
    }
    
    int currentIndex = 0;

    while (basicArray.size()>0) {
        
        currentIndex = (currentIndex + m - 1) % basicArray.size();
        
        cout<<basicArray[currentIndex]<<" ";
        
        basicArray.erase(basicArray.begin()+currentIndex);
        
    }
    
    return 0;
}
