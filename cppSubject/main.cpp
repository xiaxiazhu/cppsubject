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

int gcd(int a ,int b){
    while (b>=0) {
        if (b==0) { return a;}
        int temp = a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    int m,n;
    cin>>m>>n;
    
    cout<<gcd(m,n);

}
