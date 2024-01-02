#include <iostream>

int* f1() {
    int x = 10;
    return &x;
}

int* f2() {
    int* px;
    *px = 10;
    return px;
}

int* f3() {
    int* px = nullptr;
    px = new int;
    *px = 10;
    return px;
}

int main() {
    f1();
    f2();
    f3();
}