#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <concepts>

// task 2, task 3: TimesTwo() here

struct Rectangle {
    double Length; // data member, also known as a field
    double Width = 1; // field can have a default value
    // fields must be explicitly typed, you cannot use type deduction here

    // member function, also known as a method
    double CalculateArea() {
        return Length * Width;
    }

    // member function that modifies the state of an object
    void MakeItSquare(double SideLength) {
        Length = SideLength;
        Width = SideLength;
    }

    // task 4: CalculatePerimeter() here
};

// task 5: struct Circle here

// task 6:
void PrintShape(auto Shape) {
    // Your code here
}

// task 9:
void DoubleEachElement(/* ??? Container */) {
    // your code here
}

// task 10, task 11:
void PrintEachObject(auto* PointerToTheFirstObject, std::size_t NumberOfObjects) {
    // your code here
}

int main() {
    // task1: write "Hello World!" in an std::cout << "" << std::endl; call

    // task2
    // std::cout << TimesTwo(21) << std::endl;

    // task3
    // std::cout << TimesTwo(123) << std::endl;
    // std::cout << TimesTwo(3.14) << std::endl;
    // std::cout << TimesTwo(std::string{ "abc" }) << std::endl;

    // task4
    // std::cout << Rectangle{ 7, 8 }.CalculatePerimeter() << std::endl;

    // task5: create a few instances of Circle, and call their member functions

    // task6: call PrintShape with different Rectangle and Circle objects

    // task7: create a container of strings, fill the container with some strings
    //        repeat each string element in the container, print each string element in the container

    // task8
    // auto x = 42;
    // auto px = &x;
    // auto ppx = &px;
    // static_assert(std::same_as<decltype(*ppx), /* type of *ppx here */>);
    // static_assert(std::same_as<decltype(**ppx), /* type of **ppx here */>);

    // task9: pass different std::array and std::vector objects to DoubleEachElement
    //        print the results after DoubleEachElement calls

    // task10:
    // auto v1 = std::vector{ "aaa", "bbb", "ccc", "hello" };
    // auto v2 = std::array{ 7, 8, 9, 10, 11 };
    // PrintEachObject(v1.data(), v1.size());
    // PrintEachObject(v2.data(), v2.size());
}