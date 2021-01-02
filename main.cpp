#include <iostream>
#include "MenuLib/MenuSystem.h"

void test1 () {
    std::cout << "test1\n";
}

void test3 (std::vector<std::any> args) {
    int* a = std::any_cast<int*>(args[0]);
    std::cout << *a;
}

int main() {
    Menu test;
    Menu test2;
    int a = 8;
    bool b = true;

    test.addOption(new LinkOption ("1", test1, &test));
    test.addOption(new LinkOption ("2", &test2, &test));
    test.addOption(new BoolOption ("bool value", b));
    test.addOption(new IntOption ("a var", a, 1, 6, 2));

    test2.addOption(new LinkOption ("65", test1, &test2));
    std::vector<std::any> test3Args = {&a};
    test2.addOption(new LinkOption ("a var", test3, test3Args, &test2));

    test.display();
    return 0;
}