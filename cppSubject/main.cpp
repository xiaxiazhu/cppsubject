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


int trigleMaxLujing(vector<vector<int>> &triangle,int n)
{
    for (int i=n-2; i >=0 ; i--) {
        for (int j =0; j<=i; j++) {
            triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}


int main() {
    
    int n;
    
    cin >> n;
    
    vector<vector<int>> trigle(n,vector<int>(n));

    for (int i =0; i< n; i++) {
        for (int j=0; j<=i; j++) {
            cin>>trigle[i][j];
        }
    }
    
    // 从底部开始算
    cout << trigleMaxLujing(trigle,n)<<endl;
    
    return 0;
}
