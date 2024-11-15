#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class BigInt {
private:
    std::string number;
    bool isNegative;

    // 去除前导零
    void removeLeadingZeros() {
        while (number.size() > 1 && number.back() == '0') {
            number.pop_back();
        }
        if (number == "0") {
            isNegative = false;
        }
    }

public:
    // 构造函数
    BigInt(std::string num = "0") {
        isNegative = (num[0] == '-');
        number = isNegative ? num.substr(1) : num;
        std::reverse(number.begin(), number.end());
        removeLeadingZeros();
    }

    // 输出重载
    friend std::ostream& operator<<(std::ostream& os, const BigInt& b) {
        if (b.isNegative) os << '-';
        for (auto it = b.number.rbegin(); it != b.number.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    // 取反
    BigInt operator-() const {
        BigInt result = *this;
        result.isNegative = !isNegative;
        return result;
    }

    // 大数加法
    BigInt operator+(const BigInt& other) const {
        if (isNegative == other.isNegative) {
            std::string result;
            int carry = 0, len = std::max(number.size(), other.number.size());
            for (int i = 0; i < len || carry; ++i) {
                int digit1 = i < number.size() ? number[i] - '0' : 0;
                int digit2 = i < other.number.size() ? other.number[i] - '0' : 0;
                int sum = digit1 + digit2 + carry;
                result.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
            BigInt res;
            res.number = result;
            res.isNegative = isNegative;
            res.removeLeadingZeros();
            return res;
        } else {
            return *this - (-other);
        }
    }

    // 大数减法
    BigInt operator-(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        bool negResult = false;
        const BigInt *bigger = this, *smaller = &other;
        if (*this < other) {
            negResult = true;
            std::swap(bigger, smaller);
        }
        std::string result;
        int borrow = 0;
        for (int i = 0; i < bigger->number.size(); ++i) {
            int digit1 = bigger->number[i] - '0';
            int digit2 = i < smaller->number.size() ? smaller->number[i] - '0' : 0;
            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(diff + '0');
        }
        BigInt res;
        res.number = result;
        res.isNegative = negResult;
        res.removeLeadingZeros();
        return res;
    }

    // 大数乘法
    BigInt operator*(const BigInt& other) const {
        BigInt result("0");
        result.isNegative = isNegative != other.isNegative;
        for (int i = 0; i < number.size(); ++i) {
            int carry = 0;
            std::string temp(i, '0');
            for (int j = 0; j < other.number.size() || carry; ++j) {
                int digit1 = number[i] - '0';
                int digit2 = j < other.number.size() ? other.number[j] - '0' : 0;
                int prod = digit1 * digit2 + carry;
                temp.push_back(prod % 10 + '0');
                carry = prod / 10;
            }
            result = result + BigInt(temp);
        }
        result.removeLeadingZeros();
        return result;
    }

    // 大数除法（返回商）
    BigInt operator/(const BigInt& other) const {
        if (other == BigInt("0")) throw std::overflow_error("Division by zero");
        BigInt dividend = *this;
        dividend.isNegative = false;
        BigInt divisor = other;
        divisor.isNegative = false;
        BigInt quotient("0"), one("1");

        while (dividend >= divisor) {
            BigInt tempDivisor = divisor;
            BigInt tempQuotient("1");
            while (dividend >= (tempDivisor + tempDivisor)) {
                tempDivisor = tempDivisor + tempDivisor;
                tempQuotient = tempQuotient + tempQuotient;
            }
            dividend = dividend - tempDivisor;
            quotient = quotient + tempQuotient;
        }
        quotient.isNegative = isNegative != other.isNegative;
        quotient.removeLeadingZeros();
        return quotient;
    }

    // 大数取模（返回余数）
    BigInt operator%(const BigInt& other) const {
        BigInt result = *this - (*this / other) * other;
        result.removeLeadingZeros();
        return result;
    }

    // 比较运算符
    bool operator<(const BigInt& other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (number.size() != other.number.size()) {
            return (number.size() < other.number.size()) ^ isNegative;
        }
        for (int i = number.size() - 1; i >= 0; --i) {
            if (number[i] != other.number[i]) {
                return (number[i] < other.number[i]) ^ isNegative;
            }
        }
        return false;
    }

    bool operator==(const BigInt& other) const {
        return number == other.number && isNegative == other.isNegative;
    }

    bool operator>(const BigInt& other) const {
        return !(*this < other || *this == other);
    }

    bool operator<=(const BigInt& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const BigInt& other) const {
        return *this > other || *this == other;
    }
};


BigInt factorial(BigInt n){
        BigInt num1("1");
        if (num1 >= n ) {
            return num1;
        }else{
            return n*factorial(n-num1);
        }
    return BigInt("1");
}



bool isPrime(int x){

    if(x <= 1){ return false;}
    if(x==2||x==3) {return true;}

    for (int i = 2; i <= sqrt(x); i++)
    {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

std::vector<int> nthPrimeMax(int n) {

//    int n;
//    cin>>n;

    std::vector<int> primeNumList = {};

    int di=0;

    while (true) {
            di++;
            if (isPrime(di)) {
                primeNumList.push_back(di);
            }

            if (primeNumList.size() == n) {
                break;
            }
    }

    return primeNumList;
}

int runBigIntDemo() {

//    cout<<factorial(11)<<endl;
    string n;
    cin >> n;



    BigInt facValue = factorial(n);

    int dn=0; // 切换质数
    int i = 1; // 到底步长，取质数
    vector<int> pArray={};// 质数列表

    while (true) {
        int a = 0 ;
        int bc = 100; //步长

        if (dn==0) {
            //init parray
            pArray = nthPrimeMax(bc*i);
        }
        if (dn>(bc*i)){
                i++;
                pArray = nthPrimeMax(bc*i);
            }

        int p = pArray[dn];// 2 3 5 7 11 13 17 19 23 27 29

            string pStr = to_string(p);

        BigInt bigP(pStr);

//        facValue('asdf');

            while (facValue % bigP == BigInt("0")) { // 整除
                cout<<facValue<<endl;
                facValue=facValue/bigP;
                a++;
            }// 不能整除

            cout << p <<" "<<a<<endl;
            if (facValue==BigInt("1")) {
                break;
            }
        dn++; //切换质数
    }

    // 2 3 5 7 11 13 17 19 23
//    cout<<nthPrimeMax(9)<<endl;

    return 1;
}



int main() {
    BigInt a("150");
    BigInt b("36");
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << "a % b = " << (a % b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    return 0;
}


