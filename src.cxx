#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <concepts>

// task 2, task 3: timesTwo() here

struct Rectangle {
    double length; // data member, also known as a field
    double width = 1; // field can have a default value
    // fields must be explicitly typed, you cannot use type deduction here

    // member function, also known as a method
    double calculateArea() {
        return length * width;
    }

    // member function that modifies the state of an object
    void makeItSquare(double sideLength) {
        length = sideLength;
        width = sideLength;
    }

    // task 4: calculatePerimeter() here
};

// task 5: struct Circle here

// task 6:
void printShape(auto shape) {
    // Your code here
}

// task 9:
void doubleEachElement(/* ??? container */) {
    // your code here
}

// task 10, task 11:
void printEachObject(auto* pointerToTheFirstObject, std::size_t numberOfObjects) {
    // your code here
}

int main() {
    // task1: write "Hello World!" in an std::cout << "" << std::endl; call

    // task2
    // std::cout << timesTwo(21) << std::endl;

    // task3
    // std::cout << timesTwo(123) << std::endl;
    // std::cout << timesTwo(3.14) << std::endl;
    // std::cout << timesTwo(std::string{ "abc" }) << std::endl;

    // task4
    // std::cout << Rectangle{ 7, 8 }.calculatePerimeter() << std::endl;

    // task5: create a few instances of Circle, and call their member functions

    // task6: call printShape with different Rectangle and Circle objects

    // task7: create a container of strings, fill the container with some strings
    //        repeat each string element in the container, print each string element in the container

    // task8
    // auto x = 42;
    // auto px = &x;
    // auto ppx = &px;
    // static_assert(std::same_as<decltype(*ppx), /* type of *ppx here */>);
    // static_assert(std::same_as<decltype(**ppx), /* type of **ppx here */>);

    // task9: pass different std::array and std::vector objects to doubleEachElement
    //        print the results after doubleEachElement calls

    // task10:
    // auto v1 = std::vector{ "aaa", "bbb", "ccc", "hello" };
    // auto v2 = std::array{ 7, 8, 9, 10, 11 };
    // printEachObject(v1.data(), v1.size());
    // printEachObject(v2.data(), v2.size());
}