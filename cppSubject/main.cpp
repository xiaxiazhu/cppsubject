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

//个位数上的数字减去千位数上的数字，再减去百位数上的数字， 再减去十位数上的数字的结果大于等于零
bool fuhe(int n){
    vector<int> weishu;
    while (n>0) {
        weishu.push_back(n%10);
        n=n/10;
    }
    //1234 1234 1349 6119 2123 5017
//    reverse(weishu.begin(), weishu.end());
    if (weishu[0]-weishu[3]-weishu[2]-weishu[1]>=0) {
        return true;
    }else{
        return  false;
    }
}

int main(){
    int number;
    cin>>number;
    
    vector<int> nlist(number);
    
    for (int i =0; i<number; i++) {
        cin>>nlist[i];
    }
    
    int fuheSum=0;
    for(int elem : nlist){
        if(fuhe(elem)){
            fuheSum++;
        };
    }
    cout<<fuheSum;
    return 1;
}
