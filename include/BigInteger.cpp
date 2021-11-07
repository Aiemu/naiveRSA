//
// Created by Aiemu on 2021/10/19.
//

#include "BigInteger.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <ctime>

using namespace std;

BigInteger::BigInteger() {
    this->sign = true;
    this->num.push_back(0);
}

BigInteger::BigInteger(long long num) {
    this->sign = true;
    this->num.push_back(0);
    *this = num;
}

BigInteger::BigInteger(const char* num) { // todo
//    throw runtime_error("Do not use this init function.");
    std::string str = num;
    this->sign = str[0] != '-';
    for (long long i = str.length() - 1; i > (this->sign ? -1 : 0); i--) {
        this->num.push_back(int(str[i]) - 48);
    }
}

BigInteger::BigInteger(std::vector<unsigned int> num) {
    this->sign = true;
    this->num = num;
}

BigInteger::BigInteger(bool sign, std::vector<unsigned int> num) {
    this->sign = sign;
    this->num = num;
}

BigInteger::~BigInteger() {}

bool& BigInteger::get_sign() {
    return this->sign;
}

std::vector<unsigned int>& BigInteger::get_num() {
    return this->num;
}

void BigInteger::format() {
    for (long long i = this->num.size() - 1; i > 0; i--) {
        if (this->num.at(i) == 0) {
            this->num.pop_back();
        } else {
            break;
        }
    }
    if (this->num.empty()) {
        this->num.push_back(0);
    }
}

void BigInteger::print() {
    std::cout << (this->sign ? "(+) " : "(-) ");

    for (long long i = this->num.size() - 1; i >= 0; i--) {
        std::cout << this->num.at(i) << ' ';
    }
    std::cout << std::endl;
}

//BigInteger::operator long long() {
//    if ((*this > BigInteger((std::numeric_limits<long>::max)()))
//        || *this < BigInteger((std::numeric_limits<long>::min)())) {
//        throw std::runtime_error("Operator long long() failed: overflow.");
//    }
//    long long ret = this->num.at(this->num.size() - 1);
//
//    for (unsigned long long i = this->num.size() - 2; i >= 0; i--) {
//        ret *= 10;
//        ret += this->num.at(i);
//    }
//    return ret;
//}

BigInteger& BigInteger::operator=(long long num_b) { // decimal to 65536
    BigInteger tmp;
    tmp.get_sign() = num_b >= 0;
    tmp.get_num().clear();

    num_b = abs(num_b);
    while (num_b > 0) {
        tmp.get_num().push_back(num_b % 65536);
        num_b /= 65536;
    }
    *this = tmp;
    return *this;
}

BigInteger& BigInteger::operator=(BigInteger num_b) {
    this->sign = num_b.sign;
    this->num = num_b.num;
    return *this;
}

bool BigInteger::operator==(const BigInteger &num_b) {
    this->format();
    return this->sign == num_b.sign && this->num.size() == num_b.num.size() && this->num == num_b.num;
}

bool BigInteger::operator!=(const BigInteger &num_b) {
    return !(*this == num_b);
}

bool BigInteger::operator>(const BigInteger &num_b) {
    this->format();
    if (this->sign && !num_b.sign) {return true;} // + > -
    if (!this->sign && num_b.sign) {return false;} // - > +
    if (this->sign) { // +
        if (this->num.size() > num_b.num.size()) {return true;}
        else if (this->num.size() < num_b.num.size()) {return false;}
        else {
            for (long long i = this->num.size() - 1; i >= 0; i--) {
                if (this->num.at(i) > num_b.num.at(i)) {return true;}
                else if (this->num.at(i) < num_b.num.at(i)) {return false;}
            }
        }
    }
    else { // -
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

bool BigInteger::operator>=(const BigInteger &num_b) {
    return *this == num_b || *this > num_b;
}

bool BigInteger::operator<(const BigInteger &num_b) {
    return !(*this >= num_b);
}

bool BigInteger::operator<=(const BigInteger &num_b) {
    return *this < num_b || *this == num_b;
}

BigInteger BigInteger::get_abs() {
    BigInteger ret;
    ret.num = this->num;
    ret.sign = true;
    return ret;
}

BigInteger BigInteger::operator+(const BigInteger &num_b) {
    BigInteger ret;
    ret.num.clear();
    if ((this->sign && num_b.sign) || (!this->sign && !num_b.sign)) {
        ret.sign = this->sign;
        bool flag = false;
        for (long long i = 0; i < (this->num.size() > num_b.num.size() ? this->num.size() : num_b.num.size()); i++) {
            int tmp = flag ? 1 : 0; // 0 <= tmp <= 1
            if (i < this->num.size()) {
                tmp += this->num.at(i); // 0 <= tmp <= 65536
            }
            if (i < num_b.num.size()) {
                tmp += num_b.num.at(i); // 0 <= tmp << 65535 + 65536
            }
            flag = tmp >= 65536;
            ret.num.push_back(tmp - (flag ? 65536 : 0));
        }
        if (flag) {ret.num.push_back(1);}
    } else {
        throw runtime_error("Do not add positive to negative;");
//        const BigInteger tmp(true, this->sign ? num_b.num : this->num);
//        ret = (this->sign ? *this : num_b) - tmp;
    }
    ret.format();
    return ret;
}

BigInteger BigInteger::operator-(const BigInteger &num_b) {
    BigInteger ret;
//    ret.num.clear();
    if ((this->sign && num_b.sign) || (!this->sign && !num_b.sign)) {
        if (*this == num_b) { // abs(*this) == abs(num_b)
//            ret = BigInteger();
            return ret;
        } else if ((*this > num_b && (this->sign && num_b.sign))
            || (*this < num_b && (!this->sign && !num_b.sign))) { // abs(*this) > abs(num_b)
            ret.num.clear();
            bool flag = false;
            for (long long i = 0; i < this->num.size(); i++) {
                int tmp = flag ? this->num.at(i) - 1 : this->num.at(i);
                flag = false;
                if (tmp < 0) {
                    flag = true;
                    tmp += 65536;
                }
                if (i < num_b.num.size()) {
                    tmp -= num_b.num.at(i);
                    if (tmp < 0) {
                        tmp += 65536;
                        flag = true;
                    }
                }
                ret.num.push_back(tmp);
            }
            ret.sign = *this > num_b;
        } else { // abs(*this) < abs(num_b)
            ret.num.clear();
            bool flag = false;
            for (long long i = 0; i < num_b.num.size(); i++) {
                int tmp = flag ? num_b.num.at(i) - 1 : num_b.num.at(i);
                flag = false;
                if (tmp < 0) {
                    flag = true;
                    tmp += 65536;
                }
                if (i < this->num.size()) {
                    tmp -= this->num.at(i);
                    if (tmp < 0) {
                        tmp += 65536;
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
        throw runtime_error("Do not do - with different sign;");
//        ret.num.clear();
//        BigInteger tmp(true, this->sign ? num_b.num : this->num);
//        ret = (this->sign ? *this : num_b) + tmp;
//        ret.sign = this->sign;
    }
    ret.format();
    return ret;
}

BigInteger BigInteger::operator*(const BigInteger &num_b) {
    BigInteger ret;
    if (ret == num_b || *this == ret) {} else {
        for (long long i = 0; i < this->num.size(); i++) {
            BigInteger loop;
            unsigned int add = 0;
            loop.num.clear();
            for (long long j = 0; j < num_b.num.size(); j++) {
                unsigned int tmp = this->num.at(i) * num_b.num.at(j) + add;
                add = tmp / 65536;
                loop.num.push_back(tmp % 65536);
            }
            if (add > 0) {
                loop.num.push_back(add);
            }
            for (long long k = 0; k < i; k++) {
                loop.num.insert(loop.num.begin(), 0);
            }
            ret += loop;
        }
        ret.sign = (this->sign && num_b.sign) || (!this->sign && !num_b.sign);
    }
    ret.format();
    return ret;
}

BigInteger BigInteger::operator/(const BigInteger &num_b) {
    BigInteger ret;
    BigInteger num_b_abs(true, num_b.num);
    if (ret == num_b) {
        throw std::runtime_error("Divider can not be zero.");
    }
    else if (*this == ret) {}
    else if (this->get_abs() == num_b_abs) {
        if ((num_b.sign && this->sign) || (!num_b.sign && !this->sign)) {
            return BigInteger(1);
        } else {
            return BigInteger(-1);
        }
    }
    else if (this->get_abs() > num_b_abs) {
        ret.num = vector<unsigned int>(this->num.size(), 0);
        BigInteger reminder = *this;
        long long len_reminder = reminder.num.size();
        for (long long i = len_reminder - num_b.num.size(); i >= 0; i--) {
            BigInteger tmp(true, num_b.num);
            for (long long j = 0; j < i; j++) {
                tmp.num.insert(tmp.num.begin(), 0);
            }
            while (BigInteger::bigger_than(reminder, i, len_reminder, num_b)) {
                BigInteger tmp_b(num_b.num);
                for (BigInteger double_tmp_b(num_b.num);
                    BigInteger::bigger_than(reminder, i, len_reminder, double_tmp_b);) {
                    tmp_b = double_tmp_b;
                    cout << "tmp_b:";
                    tmp_b.print();
                    double_tmp_b *= BigInteger(2);
                    cout << "double_tmp_b:";
                    double_tmp_b.print();
                }
                cout << "tmp_b:";
                tmp_b.print();
                cout << "end\n";
                long long len_tmp_b = tmp_b.num.size();
                for (long long j = i; j < i + len_tmp_b; j++) {
                    if(reminder.num[j] >= tmp_b.num[j - i]) {
                        reminder.num[j] = reminder.num[j] - tmp_b.num[j - i];
                    }
                    else {
                        for(long long k = j + 1; k < len_reminder; k++) {
                            if(reminder.num[k] > 0){
                                reminder.num[k]--;
                                for(long long l = k - 1; l > i; l--) {
                                    reminder.num[l] = 65535;
                                }
                                reminder.num[j] = (65535 - tmp_b.num[j - i]) + 1 + reminder.num[j];
                                break;
                            }
                        }
                    }
                }
                ret.num[i]++;
                reminder.format();
                len_reminder = reminder.num.size();
            }
        }
    }
    else if (this->get_abs() < num_b_abs) {}
    ret.format();
    return ret;
}

BigInteger BigInteger::operator%(const BigInteger &num_b) {
    BigInteger ret;
    BigInteger num_b_abs(true, num_b.num);
    if (ret == num_b) {
        throw std::runtime_error("Divider can not be zero.");
    }
    else if (*this == ret) {}
    else if (this->get_abs() == num_b_abs) {}
    else if (this->get_abs() > num_b_abs) {
        ret.num.clear();
        BigInteger reminder = *this;
        for (long long i = this->num.size() - num_b.num.size(); i >= 0; i--) {
            BigInteger tmp(true, num_b.num);
            for (long long j = 0; j < i; j++) {
                tmp.num.insert(tmp.num.begin(), 0);
            }
            int cnt = 0;
            while (reminder >= tmp) {
                cnt++;
                reminder -= tmp;
            }
        }
        ret = reminder;
    }
    else if (this->get_abs() < num_b_abs) {return *this;}
    return ret;
}

BigInteger BigInteger::operator++() {
    *this = *this + BigInteger(1);
    return *this;
}

BigInteger BigInteger::operator--() {
    *this = *this + BigInteger(-1);
    return *this;
}

BigInteger BigInteger::operator++(int) {
    *this = *this + BigInteger(1);
    return *this;
}

BigInteger BigInteger::operator--(int) {
    *this = *this + BigInteger(-1);
    return *this;
}

BigInteger BigInteger::operator+=(BigInteger num_b) {
    *this = *this + num_b;
    return *this;
}

BigInteger BigInteger::operator-=(BigInteger num_b) {
    *this = *this - num_b;
    return *this;
}

BigInteger BigInteger::operator*=(BigInteger num_b) {
    *this = *this * num_b;
    return *this;
}

BigInteger BigInteger::operator/=(BigInteger num_b) {
    *this = *this / num_b;
    return *this;
}

BigInteger BigInteger::operator%=(BigInteger num_b) {
    *this = *this % num_b;
    return *this;
}

BigInteger BigInteger::pow(BigInteger k) {
    BigInteger ret(1);
    BigInteger tmp = *this;
    while (k > BigInteger()) {
        if (k % BigInteger(2) == BigInteger(1)) {
            ret *= tmp;
        }
        tmp *= tmp;
        k /= BigInteger(2);
    }
    return ret;
}

BigInteger BigInteger::pow(BigInteger k, BigInteger mod) {
    BigInteger ret(1);
    BigInteger tmp = *this;
    while (k > BigInteger()) {
        if (k % BigInteger(2) == BigInteger(1)) {
            ret = ret * tmp % mod;
        }
        tmp = tmp * tmp % mod;
        k /= BigInteger(2);
    }
    return ret;
}

bool BigInteger::bigger_than(const BigInteger &num_a, long long begin, long long end, const BigInteger &num_b) {
    long long len_a = end - begin;
    if (len_a > num_b.num.size()) {
        return true;
    }
    else if (len_a < num_b.num.size()) {
        return false;
    }
    for (long long i = len_a - 1; i >= 0; i--) {
        if (num_a.num[i + begin] > num_b.num[i]) return true;
        else if (num_a.num[i + begin] < num_b.num[i]) return false;
    }
    return true;
}

BigInteger BigInteger::generate_rand_big_integer(long long len) {
    BigInteger ret;
    ret.num.clear();
    for (long long i = 0; i < len - 1; i++) {
        ret.num.push_back(rand() % 10);
    }

    int tmp = 0;
    do {
        tmp = rand() % 10;
    } while (tmp == 0);
    ret.num.push_back(tmp);
    ret.format();

    if (ret.num.size() != len) {
        ret.print();
        cout << "len: " << len << "\nsize: " << ret.num.size() << "\n";
        throw runtime_error("Generate rand big integer with wrong length.");
    }
    return ret;
}

BigInteger BigInteger::generate_rand_big_integer(BigInteger begin, BigInteger end) {
    BigInteger ret;
    ret.num.clear();
    for (long long i = 0; i < end.num.size(); i++) {
        ret.num.push_back(rand() % 10);
    }
    ret.format();
    return ret % (end - begin + BigInteger(1)) + begin;
}

bool BigInteger::try_composite(BigInteger a, BigInteger m, BigInteger k) {
    if (a.pow(m, *this) == BigInteger(1)) {return false;}
    for (BigInteger j; j < k; j++) {
        if (a.pow(BigInteger(2).pow(j) * m, *this) == *this - BigInteger(1)) {return false;}
    }
    return true;
}

bool BigInteger::is_probable_prime(int certainty) {
    if (*this == BigInteger(2)) {return true;}
    if (*this <= BigInteger(2)) {return false;}
    if (*this % BigInteger(2) == BigInteger()) {return false;}
    BigInteger m = *this - BigInteger(1);
    BigInteger k;
    while (m % BigInteger(2) == BigInteger()) { // *this - 1 = m * 2^k
        m = m / BigInteger(2);
        k++;
    }
    srand(unsigned(time(NULL)));

    for (int i = 0; i < certainty; i++) {
        BigInteger a = this->generate_rand_big_integer(BigInteger(2), *this - BigInteger(1));
        a.print();
        if (this->try_composite(BigInteger(3), m, k)) {
            return false;
        }
    }
    return true;
}
