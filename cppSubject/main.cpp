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

int gcd(int a,int b){
    while (b>=0) {
        if (b==0) {
            return a;
        }
        int temp = b;
        b=a%b;
        a=temp;
    }
    
    return a;
}

int main(){
    //输入样例中有3个学校，人数分别为12、16、20，因为12=4×3，16=4×4，20=4×5，所以最多可以分成4个队，3个学校//在每个队中的人数分别为3人、4人、5人。
    int n ;
    cin >> n;
    
    vector<int> schoolList(n);
    
    for (int i =0; i<n; i++) {
        cin>>schoolList[i];
    }
    int dn=0;
    //求最大公约数。
    for (int j=0; j<n; j++) {
        if (j==0) {
            dn = gcd(schoolList[j],schoolList[j+1]);
        }else{
            dn = gcd(schoolList[j], dn);
        }
    }
    
    cout<<dn<<" ";
    
}
