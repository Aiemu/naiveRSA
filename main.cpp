//
// Created by Aiemu on 2021/10/20.
//

#include <ctime>

#include "include/BigInteger.h"

// RSA-768（768 bits, 232 digits）
// 1. find prime p, q, n = p * q, phi(n) = (p - 1) * (q - 1)
// 2. find e, let 1 < e < phi(n), and gcd(e, phi(n)) == 1, usually 3 or 65537
// 3. compute d = e^-1, ed = 1 (mod phi(n)) <=> compute ex + phi(n)y = 1 (hint: The extended Euclidean algorithm)
// 4. public key: (n, e), private key: (n, d)
// 5. encryption(to compute c): m^e = c (mod n)
// 6. decryption(to compute m): c^d = m (mod n)
// 7. generate(<RSA-786) time < 1s

int main() {
//    BigInteger a("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
//    BigInteger b("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
//    a.print();
//    b.print();
//    a = a * b;
//    a.print();
<<<<<<< HEAD
//    BigInteger test_prime("21312113");
=======
//    BigInteger test_prime("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
>>>>>>> f05c2c274f719be84e277f31c008aee0e45f4f41
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