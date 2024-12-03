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

    int n;
    cin>>n;
    
    vector<int> list(n);
    
    for (int i = 0; i<n; i++) {
        cin>>list[i];
    }
    
    sort(list.begin(), list.end(),[](int a,int b){
        return a>b;
    });
    
    for(int t:list){
        cout<<t<<" ";
    }
}
