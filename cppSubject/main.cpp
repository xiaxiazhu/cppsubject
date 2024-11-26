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

using namespace std;

int main() {

    int n = 0;
    cin>>n;
    
    vector<int> data;
    
    while (n>0) {
        int temp = 0;
        cin>>temp;
        data.push_back(temp);
        n--;
    }
    
    unordered_map<int,int>freqMap;
    int maxFreq = 0 ;
    
    vector<int> zhongshu;
    
    for (int num : data) {
        freqMap[num]++;
        maxFreq = max(maxFreq, freqMap[num]);
    }
    
    for(auto &pair : freqMap){
        if (pair.second==maxFreq) {
            zhongshu.push_back(pair.first);
        }
    }
    
    // sort
    sort(zhongshu.begin(), zhongshu.end());
    
    cout<<zhongshu.size()<<"\n";
    
    for (int j =0; j<zhongshu.size(); j++) {
        cout<<zhongshu[j]<<" ";
    }
    
    return 0;
}
