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

bool swapAB(int &a ,int &b ){
    int temp = a ;
    a = b;
    b = temp;
    
    return  true;
}

int main(){

    int a,b;
    cin>>a>>b;
    swapAB(a, b);
    cout<<a<<" "<<b;
    
}
