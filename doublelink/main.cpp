//
//  main.cpp
//  doublelink
//
//  Created by zhuzhuxia on 2025/1/4.
//

#include <iostream>
#include "doublelinklib.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    DoubleLink list;
    
    int n;
    cin>>n;
    
    for (int i =0; i<n; i++) {
        int a;
        cin>>a;
        list.append(a);
    }
    
    if (list.huiWenShu()) {
        cout<<"true";
    }else{
        cout<<"false";
    }
    
//    list.deleteElment(x);
    
//    list.showSubLine(x);
    
    
//    int iValue;
//    cin>>iValue;
    
//    list.insert(iValue);
    
//    list.printForward();
//      list.printBackward();
    
    return 0;
}
