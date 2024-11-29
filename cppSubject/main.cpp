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
    
    vector<vector<long int>> yanhuiTriangle(n,vector<long int>(n));
    
    for (int i = 0 ; i<n; i++) {
//        yanhuiTriangle[0].resize(n+1);
        
        yanhuiTriangle[i][0]=1;
        yanhuiTriangle[i][i]=1;

        for (int j=1; j < i; j++) {
                        //(2,1)
            yanhuiTriangle[i][j] = yanhuiTriangle[i-1][j-1]+yanhuiTriangle[i-1][j];
            yanhuiTriangle[i][j] %=4294967296;
        }
    }

    for (int h=0;h<n ; h++) {
        for (int k=0; k<=h; k++) {
            cout<< yanhuiTriangle[h][k]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
