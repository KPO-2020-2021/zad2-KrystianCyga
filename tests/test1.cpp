#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test2 LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x+y == z);
}

TEST_CASE("test3 LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 0.1;
    x.im = 0.1;

    y.re = 0.1;
    y.im = 0.1;

    z.re = 0.2;
    z.im = 0.2;
    
    CHECK(x+y == z);
}

TEST_CASE("test4 LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00002;
    z.im = 0.00002;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re = 0.00002;
    x.im = 0.00002;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.00001;
    z.im = 0.00001;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 0.01;
    x.im = 0.01;

    y.re = 0.02;
    y.im = 0.02;

    z.re = 0;
    z.im = 0.0004;
    
    CHECK(x*y == z);
}

TEST_CASE("test2 LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}

TEST_CASE("test3 LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 0;
    z.im = 1;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Iloraz"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 1.41421;
    z.im = 0;
    
    CHECK(x/y == z);
}
TEST_CASE("test2 LZespolona Iloraz"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.1;

    y.re = 1.2;
    y.im = 1.2;

    z.re = 1.55563;
    z.im = 0;
    
    CHECK(x/y == z);
}