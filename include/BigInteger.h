//
// Created by Aiemu on 2021/10/19.
//

#ifndef NAVIERSA_BIGINTEGER_H
#define NAVIERSA_BIGINTEGER_H

#include <iostream>
#include <vector>
#include <cstring>

class BigInteger {
    private:
        bool sign;
        std::vector<int> num;

    public:
        BigInteger();
        explicit BigInteger(long long num);
        explicit BigInteger(const char* num);
        ~BigInteger();

        explicit operator long long();
        BigInteger& operator=(long long num);
        BigInteger& operator=(BigInteger num);

        bool operator==(BigInteger num_b);
        bool operator!=(BigInteger num_b);
        bool operator<(BigInteger num_b);
        bool operator>(BigInteger num_b);
        bool operator<=(BigInteger num_b);
        bool operator>=(BigInteger num_b);

        BigInteger operator+(BigInteger num_b);
        BigInteger operator-(BigInteger num_b);
        BigInteger operator*(BigInteger num_b);
        BigInteger operator/(BigInteger num_b);
        BigInteger operator%(BigInteger num_b);

        BigInteger operator++();
        BigInteger operator--();
        BigInteger operator+=(BigInteger num_b);
        BigInteger operator-=(BigInteger num_b);
        BigInteger operator*=(BigInteger num_b);
        BigInteger operator/=(BigInteger num_b);
        BigInteger operator%=(BigInteger num_b);

        bool& get_sign();
        std::vector<int>& get_num();

        void print();

};


#endif //NAVIERSA_BIGINTEGER_H
