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
    int c = 5;
    vector<vector<long int>> matrix(c,vector<long int>(c));
    
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            cin>> matrix[i][j];
        }
    }
    int m,n;
    cin>>m>>n; // （1 <= m,n <= 5）
    
    vector<long int> temp(c);
    
    temp = matrix[m-1];
    matrix[m-1]=matrix[n-1];
    matrix[n-1] = temp;
    
    for (int k=0; k<n; k++) {
        for (int h=0; h<n; h++) {
            cout << matrix[k][h]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
