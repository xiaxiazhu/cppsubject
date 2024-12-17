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
////#include <cmath>
//#include <climits>
////#include <unordered_map>
////#include <stack>
//#include <sstream>
//#include <algorithm>
//#include <cctype>
//#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    // init list
    list<int> circle;
    for (int i=1; i<=n; ++i) {
        circle.push_back(i);
    }
    
    
    auto it = circle.begin();

//    cout<< *it<<endl;
    
    while (circle.size()>0) {
        
        for (int j=0; j<m-1; j++) {
            it++;
                if (it == circle.end() ) {
                    it = circle.begin();
                }
        }
        cout<< *it <<" ";
        
        it = circle.erase(it);

        if (it == circle.end()) {
            it = circle.begin();
        }

        
    }
}
