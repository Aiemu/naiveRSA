//
// Created by Aiemu on 2021/10/20.
//

#include "include/BigInteger.h"

// use Miller-Rabin primality test

int main() {
//    BigInteger a("73910485793485713875831573045738503957019483750139847503985709845709834752584767845610397634581435613756134598135897136495");
//    BigInteger b("78465287456247545634532958345638754");
//    a.print();
//    b.print();
//    a = a % b;
//    a.print();
    BigInteger test_prime("123773");
    std::cout << test_prime.is_probable_prime(5) << "\n";
//    (BigInteger(324235).pow(BigInteger(123))).print();
    return 0;
}