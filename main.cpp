//
// Created by Aiemu on 2021/10/20.
//

#include "include/BigInteger.h"

#include <iostream>
#include <limits>

int main() {
    BigInteger a("55");
    BigInteger b("100");
    a.print();
    b.print();
    a = a - b;
    a.print();
    return 0;
}