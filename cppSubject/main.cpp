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
using namespace std;



int main() {
        
//    cout << "int 类型的最大值: " << INT_MAX << endl;
//    cout << "long int 类型的最大值: " << LONG_MAX << endl;
//    cout << "long long int 类型的最大值: " << LLONG_MAX << endl;
    int n = 0;
    cin>>n;
    
    vector<int> faibonacciList;
    
    // init
    faibonacciList.push_back(0);
    faibonacciList.push_back(1);
    
    for (int i = 2; i<=n; i++) {

        int fnext = faibonacciList[i-1]%INT_MAX +faibonacciList[i-2]%INT_MAX;
        
        long int overflowValue = INT_MAX;
        
        if (INT_MAX-faibonacciList[i-1]<faibonacciList[i-2]){//两数相加的溢出判断
            overflowValue =static_cast<long int>(faibonacciList[i-1])+static_cast<long int>(faibonacciList[i-2]);
            fnext = overflowValue%INT_MAX;
        }
        
        // fill i
        faibonacciList.push_back(fnext);
        
    }
    
    cout<<faibonacciList[n];
    
    return 0;
}
