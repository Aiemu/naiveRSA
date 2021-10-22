//
// Created by Aiemu on 2021/10/20.
//

#include "include/BigInteger.h"

// use Miller-Rabin primality test
// RSA-768（768 bits, 232 digits）
// 1. find prime p, q, n = p * q, phi(n) = (p - 1) * (q - 1)
// 2. find e, let 1 < e < phi(n), and gcd(e, phi(n)) == 1, usually 3 or 65537
// 3. compute d = e^-1, ed = 1 (mod phi(n)) <=> compute ex + phi(n)y = 1 (hint: The extended Euclidean algorithm)
// 4. public key: (n, e), private key: (n, d)
// 5. encryption(to compute c): m^e = c (mod n)
// 6. decryption(to compute m): c^d = m (mod n)

int main() {
//    BigInteger a("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
//    BigInteger b("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
//    a.print();
//    b.print();
//    a = a * b;
//    a.print();
//    BigInteger test_prime("155251809230070893514897948846250255525688601711663681113905203802605095268637688232123840882864647795048773069713113");
//    std::cout << test_prime.is_probable_prime(5) << "\n";
//    (BigInteger(6704).pow(BigInteger(2743), BigInteger(123))).print();
    return 0;
}