//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>

using namespace std;

std::vector<std::string> splitByDelimiter(const std::string& str, char delimiter) {
    std::vector<std::string> segments;
    std::istringstream stream(str);
    std::string segment;

    while (std::getline(stream, segment, delimiter)) {
        segments.push_back(segment);
    }

    return segments;
}


int main(){
    
    string words;
    
    getline(cin, words);
    
    vector<string> segments =  splitByDelimiter(words, '+');
    
    int sum=0;
    for(auto seg:segments){
        sum+= stoi(seg);
    }
    
    cout<<sum<<"\n";
        
    return 0;
}
