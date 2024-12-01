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


int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> matrix(n,vector<int>(n,-1));
    
    int top = 1, right=n,bottom=n,left=1;
    
    int sum=0;
    
    while (top<=bottom && left<=right) {
        
        // 从左到右
        for (int t=top; t<=right;t++) {
            matrix[top-1][t-1] = ++sum;
        }
        top++;
        
        // 从上到下
        for (int r= top; r<=bottom; r++) {
            matrix[r-1][right-1]= ++sum;
        }
        right--;
        
        //从右到左
        for (int b=right; b>=left; b--) {
            matrix[bottom-1][b-1]=++sum;
        }
        bottom--;
        
        // 从下倒上
        for (int l =bottom; l>=top; l--) {
            matrix[l-1][left-1]= ++sum;
        }
        left++;
    }
    for(auto m:matrix){
        for(auto ma:m){
            cout<<ma<<" ";
        }
        cout<<"\n";
    }

    
}
