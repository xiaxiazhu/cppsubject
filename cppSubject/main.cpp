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
using namespace std;

// 实现大整数加法
string addLargeNumbers(const string &num1, const string &num2) {
    string result = "";
    int carry = 0; // 进位
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0'); // 当前位
        carry = sum / 10; // 更新进位
    }

    reverse(result.begin(), result.end()); // 反转得到正确结果
    return result;
}


string subtractLargeNumbers(const string &num1, const string &num2) {
    string result = "";
    int borrow = 0; // 借位
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0) {
        int digit1 = num1[i--] - '0';
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10; // 借位
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }

    // 去掉前导零
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end()); // 反转得到正确结果
    return result;
}



string multiplyLargeNumbers(const string &num1, const string &num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int len1 = num1.size();
    int len2 = num2.size();
    
    vector<int> result(len1 + len2 ,0);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10; // 当前位
            result[i + j] += sum / 10;   // 进位
        }
    }

    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) { // 去掉前导零
            product.push_back(num + '0');
        }
    }
    return product;
}

// 大整数除法，返回商（假设 divisor 是小整数）
string divideLargeNumber(const string &num, int divisor) {
    string result = "";
    int remainder = 0;

    for (char digit : num) {
        remainder = remainder * 10 + (digit - '0');
        result.push_back((remainder / divisor) + '0');
        remainder %= divisor;
    }

    // 去除前导零
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

// 大整数求余运算
int modLargeNumber(const string &num, int divisor) {
    if (divisor == 0) {
        throw invalid_argument("除数不能为零！");
    }

    int remainder = 0; // 当前余数
    for (char digit : num) {
        remainder = (remainder * 10 + (digit - '0')) % divisor;
    }
    return remainder;
}

// 二分查找法求平方根
double sqrtBinarySearch(double x, double epsilon = 1e-6) {
    if (x < 0) {
        throw std::invalid_argument("输入必须是非负数");
    }

    double left = (x < 1) ? x : 0;
    double right = (x < 1) ? 1 : x;

    while (right - left > epsilon) {
        double mid = (left + right) / 2;
        if (mid * mid < x) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return (left + right) / 2;
}

// 比较两个大整数的大小
// 返回值：
//  1  -> num1 > num2
// -1  -> num1 < num2
//  0  -> num1 == num2
int compareLargeNumbers(const string &num1, const string &num2) {
    // 去掉前导零
    string n1 = num1, n2 = num2;
    n1.erase(0, n1.find_first_not_of('0')); // 去掉 num1 前导零
    n2.erase(0, n2.find_first_not_of('0')); // 去掉 num2 前导零

    // 长度比较
    if (n1.size() > n2.size()) return 1;  // num1 长度大于 num2
    if (n1.size() < n2.size()) return -1; // num1 长度小于 num2

    // 逐位比较
    for (size_t i = 0; i < n1.size(); ++i) {
        if (n1[i] > n2[i]) return 1;  // num1 当前位大于 num2
        if (n1[i] < n2[i]) return -1; // num1 当前位小于 num2
    }

    // 相等
    return 0;
}


string factorial(int n)
{
    string mutlValue = "1";
    
    for (int i =1 ; i <= n; i++) {
        
        mutlValue = multiplyLargeNumbers(mutlValue,to_string(i)) ;
        
    }
    return  mutlValue;
}

int main() {
//    cout<< factorial(10)<<endl;
    
    int n ;
    cin>>n;
    string yinshu = factorial(n);
    
    // 处理2
    int a2 = 0;
    
    while (modLargeNumber(yinshu, 2)==0) {
        a2++;
        //yinshu/=2
        yinshu = divideLargeNumber(yinshu, 2);
    }
    
    if (a2>0) {cout<<2<<" "<<a2<<endl;}
    
    // 处理3以及以上质因数
    for (int i = 3 ;compareLargeNumbers(to_string(i*i),yinshu)<=0; i+=2) {
        int aa = 0;
        while (modLargeNumber(yinshu, i) == 0 ) {
            aa++;
            yinshu = divideLargeNumber(yinshu, i);
        }
        if ( aa > 0) {
            cout<<i<<" "<<aa<<endl;
        }
    }
    
    if (compareLargeNumbers(yinshu, "2")>=0) {
        cout<<yinshu<<" "<<1<<endl;
    }
    
    return 0;
}
