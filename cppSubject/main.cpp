//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
using namespace std;


int main() {
    
    string result =".";
    int dividend;
    int divisor;
    int decimalPlaces;
    
    cin>> dividend>> divisor >> decimalPlaces;
    
    if (dividend % divisor ==0) {
        cout<<dividend/divisor<<endl;
    }else{
        // 有小数
        int tempDived = dividend % divisor;
                
        
        for (int i =0 ; i < decimalPlaces; i++) {
            
            tempDived *=10;
            
            result += to_string(tempDived / divisor);
            
            tempDived %=  divisor;

        }
        
        cout<<to_string(dividend/divisor)+result<<endl;
        
    }
    
    
    
    return 0;
}
