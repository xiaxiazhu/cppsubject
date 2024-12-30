//
//  main.cpp
//  main4
//
//  Created by zhuzhuxia on 2024/12/29.
//

#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char * argv[]) {

    int a,b;
    
    cin>>a>>b;
    
    int * apt = &a;
    
//    cout<<apt<<"\n";
    
    swap(&a,&b);
    
    cout<<a<<" "<<b<<"\n";
    
    cout<<"a address"<<"=="<<&a<<" "<<apt<<"\n";
    
    cout<<"a value"<<"=="<<*apt<<"\n";
    
    return 0;
}
