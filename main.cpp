//
// Created by Aiemu on 2021/10/20.
//

#include "include/BigInteger.h"

// use Miller-Rabin primality test

int main() {
//    BigInteger a("26");
//    BigInteger b("130");
//    a.print();
//    b.print();
//    a = a % b;
//    a.print();
    BigInteger test_prime("27437");
    std::cout << test_prime.is_probable_prime(5) << "\n";
//    (BigInteger(6704).pow(BigInteger(2743), BigInteger(123))).print();
    return 0;
}