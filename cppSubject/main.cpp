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
    
bool ishuiwen(string nStr){
    
    string fanStr=nStr ;

    reverse(nStr.begin(),nStr.end());

    if (nStr ==fanStr) {
        return true;
    }else{
        return false;
    }
}

string jingZhiConvert(int value, int r){
    
    string result = "";
    char charList[] = "0123456789ABCDEF";
    
    while (value>0) {
        
        result = charList[value%r] +result;
        value=value/r;
    }
    
    return result;
    
}

int main(){
    vector<int> input;
    
    bool isPalindrom = false;
    string pBasis = "";

    while (true) {
        int temp;
        cin>>temp;
        if (temp) {
            input.push_back(temp);
        }else{
            break;
        }
    }
    
    for (int t = 0 ; t<input.size(); t++) {
        
        // reset isPalindrom
        isPalindrom=false;
        pBasis="";
        
        vector<int> rList = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        
        
        for(int r:rList){
                        
            string temp = jingZhiConvert(input[t],r);

            if (ishuiwen(temp)) {
                isPalindrom = true;
                pBasis= pBasis+ to_string(r)+" ";
            }
            //Number 19 is not a palindrom
        }
        
        if (isPalindrom) {
            cout<<"Number " + to_string(input[t])+" is palindrom in basis "+ pBasis<<"\n";
        }else{
            cout<<"Number "+to_string(input[t])+" is not a palindrom"+"\n";
        }
        
        
    }
    
}
