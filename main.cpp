//
// Created by Aiemu on 2021/10/20.
//

#include <ctime>

#include "include/BigInteger.h"

// use Miller-Rabin primality test

int main() {
//    BigInteger a("26");
//    BigInteger b("130");
//    a.print();
//    b.print();
//    a = a % b;
//    a.print();
//    BigInteger test_prime("21312113");
//    std::cout << test_prime.is_probable_prime(5) << "\n";
//    (BigInteger(6704).pow(BigInteger(2743), BigInteger(123))).print();
    std::vector<unsigned int> a;
    std::vector<unsigned int> b;
//    srand(unsigned(time(NULL)));
//    for (int i = 0; i < 48; i++) {
//        a.push_back(rand() % 65536);
//    }
//    for (int i = 0; i < 24; i++) {
//        b.push_back(rand() % 65536);
//    }
    a.push_back(0);
    a.push_back(2);
    b.push_back(2);

    BigInteger Bia(a);
    Bia.print();
    BigInteger Bib(b);
    Bib.print();

    (Bia / Bib).print();

//    std::cout << BigInteger::bigger_than(Bia, 0, 2, Bib);
//    clock_t start = clock();
//    for (int i = 0; i < 10000; i++) {
//        Bia / Bib;
//    }
//    clock_t end = clock();
//    std::cout << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
//
//    start = clock();
//    for (int i = 0; i < 10000; i++) {
//        Bia % Bib;
//    }
//    end = clock();
//    std::cout << (double)(end - start) / CLOCKS_PER_SEC << "s\n";

//    for (int i = 0; i < 100; i++) {
//        b.push_back(rand() % 65536);
//    }
    return 0;
}