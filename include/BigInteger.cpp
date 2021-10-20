//
// Created by Aiemu on 2021/10/19.
//

#include "BigInteger.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
//#include <cstring>
#include <string>

BigInteger::BigInteger() {
    this->sign = true;
    this->num.push_back(0);
}

BigInteger::BigInteger(long long num) {
    this->sign = true;
    this->num.push_back(0);
    *this = num;
}

BigInteger::BigInteger(const char* num) {
    std::string str = num;
    this->sign = str[0] != '-';
    for (long long i = str.length() - 1; i > (this->sign ? -1 : 0); i--) {
        this->num.push_back(int(str[i]) - 48);
    }
}

BigInteger::~BigInteger() {}

bool& BigInteger::get_sign() {
    return this->sign;
}

void BigInteger::print() {
    std::cout << (this->sign ? "" : "-");

    for (int i = this->num.size() - 1; i >= 0; i--) {
        std::cout << this->num.at(i);
    }
    std::cout << std::endl;
}

std::vector<int>& BigInteger::get_num() {
    std::cout << std::endl;
    return this->num;
}

BigInteger::operator long long() {
    if ((*this > BigInteger((std::numeric_limits<long>::max)()))
        || *this < BigInteger((std::numeric_limits<long>::min)())) {
        throw std::runtime_error("Operator long long() failed: overflow.");
    }
    long long ret = this->num.at(this->num.size() - 1);

    for (unsigned long long i = this->num.size() - 2; i >= 0; i--) {
        ret *= 10;
        ret += this->num.at(i);
    }
}

BigInteger& BigInteger::operator=(long long num_b) {
    BigInteger tmp;
    tmp.get_sign() = num_b >= 0;
    tmp.get_num().clear();

    num_b = abs(num_b);
    while (num_b > 0) {
        tmp.get_num().push_back(num_b % 10);
        num_b /= 10;
    }
    *this = tmp;
    return *this;
}

BigInteger& BigInteger::operator=(BigInteger num_b) {
    this->sign = num_b.sign;
    this->num = num_b.num;
    return *this;
}

bool BigInteger::operator==(BigInteger num_b) {
    return this->sign == num_b.sign && this->num == num_b.num;
}

bool BigInteger::operator!=(BigInteger num_b) {
    return !(*this == num_b);
}

bool BigInteger::operator>(BigInteger num_b) {
    if (this->sign && !num_b.sign) {return true;}
    if (!this->sign && num_b.sign) {return false;}
    if (this->sign) {
        if (this->num.size() > num_b.num.size()) {return true;}
        else if (this->num.size() < num_b.num.size()) {return false;}
        else {
            for (long long i = this->num.size() - 1; i >= 0; i--) {
                if (this->num.at(i) > num_b.num.at(i)) {return true;}
                else if (this->num.at(i) < num_b.num.at(i)) {return false;}
            }
        }
    }
    if (!this->sign) {
        if (this->num.size() > num_b.num.size()) {return false;}
        else if (this->num.size() < num_b.num.size()) {return true;}
        else {
            for (long long i = this->num.size() - 1; i >= 0; i--) {
                if (this->num.at(i) > num_b.num.at(i)) {return false;}
                else if (this->num.at(i) < num_b.num.at(i)) {return true;}
            }
        }
    }
    return false;
}

bool BigInteger::operator<(BigInteger num_b) {
    return num_b > *this;
}

bool BigInteger::operator>=(BigInteger num_b) {
    return *this == num_b || *this > num_b;
}

bool BigInteger::operator<=(BigInteger num_b) {
    return !(num_b > *this);
}

BigInteger BigInteger::operator+(BigInteger num_b) {
    BigInteger ret;
    ret.num.clear();
    if ((this->sign && num_b.sign) || (!this->sign && !num_b.sign)) {
        ret.sign = this->sign;
        bool flag = false;
        for (long long i = 0;
            i < (this->num.size() > num_b.num.size() ? this->num.size() : num_b.num.size()); i++) {
            int tmp = flag ? 1 : 0;
            if (i < this->num.size()) {
                tmp += this->num.at(i);
            }
            if (i < num_b.num.size()) {
                tmp += num_b.num.at(i);
            }
            flag = tmp >= 10;
            ret.num.push_back(tmp % 10);
        }
        if (flag) {ret.num.push_back(1);}
    } else {
        BigInteger tmp;
        tmp.num = this->sign ? num_b.num : this->num;
        tmp.sign = true;
        ret = (this->sign ? *this : num_b) - tmp;
    }
    return ret;
}

BigInteger BigInteger::operator-(BigInteger num_b) {
    BigInteger ret;
    ret.num.clear();
    if ((this->sign && num_b.sign) || (!this->sign && !num_b.sign)) {
        if (*this == num_b) {
            // abs(*this) == abs(num_b)
            ret = BigInteger();
            return ret;
        } else if ((*this > num_b && (this->sign && num_b.sign)) || (*this < num_b && (!this->sign && !num_b.sign))) {
            // abs(*this) > abs(num_b)
            bool flag = false;
            for (long long i = 0; i < this->num.size(); i++) {
                int tmp = flag ? this->num.at(i) - 1 : this->num.at(i);
                flag = false;
                if (i < num_b.num.size()) {
                    tmp -= num_b.num.at(i);
                    if (tmp < 0) {
                        tmp += 10;
                        flag = true;
                    }
                }
                if (!(i == this->num.size() - 1 && tmp == 0)) {
                    ret.num.push_back(tmp);
                }
            }
            ret.sign = *this > num_b;
        } else {
            // abs(*this) < abs(num_b)
            bool flag = false;
            for (long long i = 0; i < num_b.num.size(); i++) {
                int tmp = flag ? num_b.num.at(i) - 1 : num_b.num.at(i);
                flag = false;
                if (i < this->num.size()) {
                    tmp -= this->num.at(i);
                    if (tmp < 0) {
                        tmp += 10;
                        flag = true;
                    }
                }
                if (!(i == num_b.num.size() - 1 && tmp == 0)) {
                    ret.num.push_back(tmp);
                }
            }
            ret.sign = *this > num_b;
        }
    } else {
        BigInteger tmp;
        tmp.num = this->sign ? num_b.num : this->num;
        tmp.sign = true;
        ret = (this->sign ? *this : num_b) + tmp;
        ret.sign = this->sign;
    }
    return ret;
}

BigInteger BigInteger::operator*(BigInteger num_b) {}

BigInteger BigInteger::operator/(BigInteger num_b) {}

BigInteger BigInteger::operator%(BigInteger num_b) {}

BigInteger BigInteger::operator++() {}

BigInteger BigInteger::operator--() {}

BigInteger BigInteger::operator+=(BigInteger num_b) {}

BigInteger BigInteger::operator-=(BigInteger num_b) {}

BigInteger BigInteger::operator*=(BigInteger num_b) {}

BigInteger BigInteger::operator/=(BigInteger num_b) {}

BigInteger BigInteger::operator%=(BigInteger num_b) {}