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

//int decToBinaryCursive(int dec){
//    if (dec==0) {
//        return "0";
//    }
//
//    string binaryString = "";
//
//    while (dec>0) {
//        binaryString = to_string(dec%2)+ binaryString;
//        dec/=2;
//    }
//
//    return  binaryString;
//}

int bitOneNumber(int num){
    int count =0;
    
    while (num) {
        num=num &(num-1);
        count++;
    }
    return count;
}


int main(){
    int s,t;
    cin>>s>>t;
    
    int canBiaoshi = 0 ;
    
    for (int i =s; i<=t; i++) {
        //求牛可以表示的数 四个1
        
        if (bitOneNumber(i)<5) {
            canBiaoshi++;
        }
    }
    cout<<canBiaoshi;

    
}
