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
        explicit BigInteger(bool sign, std::vector<int> num);
        ~BigInteger();

        // Operator overload
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

        BigInteger operator++(); // front
        BigInteger operator--();
        BigInteger operator++(int); // back
        BigInteger operator--(int);
        BigInteger operator+=(BigInteger num_b);
        BigInteger operator-=(BigInteger num_b);
        BigInteger operator*=(BigInteger num_b);
        BigInteger operator/=(BigInteger num_b);
        BigInteger operator%=(BigInteger num_b);
        BigInteger pow(BigInteger k);
        BigInteger pow(BigInteger k, BigInteger mod);

        // Functions to get attributes
        bool& get_sign();
        std::vector<int>& get_num();
        BigInteger get_abs();

        // Functions for auxiliary
        void print();
        void format();

        BigInteger generate_rand_big_integer(long long len);
        BigInteger generate_rand_big_integer(BigInteger begin, BigInteger end);
        bool try_composite(BigInteger a, BigInteger m, BigInteger k);
        bool is_probable_prime(int certainty);

};


#endif //NAVIERSA_BIGINTEGER_H
