# Lab 1: Setup


## 0. Intro

The purpose of this lab is twofold: to help you get set up with working on CS123 projects locally, and to help you learn the basics of C++ -- The programming language that we will be using for the labs and the assignments.

In the rest of this 1-2h lab, you will:

1. Install Qt 6 locally on your computer, and
2. Build and run a starter Qt program, and
3. ??placeholder for C++ tutorial

**Note:** Overall Qt 6 and the C++ compiler will suck up ??GB of space, approximately. Additional images or scene files can also take up a fair bit of space. Be sure you have room.

##
##
## Installing Qt 6

## **Windows**

1. Install Qt (takes about ?? mins)

    a. [https://www.qt.io/download-qt-installer](https://www.qt.io/download-qt-installer)

    b. Open when done downloading
2. Follow instructions on the installer to create a new Qt account if you do not have one
3. When selecting components:

    a. Choose “Custom Installation”
![](1.png)

    b. Under “Qt”, you’ll need Qt 6.2.4, and select the items as shown in the screenshot for the “Developer and Designer Tools” section. MinGW is what provides the GCC compiler you'll need to compile your C++ code.
![](2.png)
4. Continue and finish the installation process.
5. We'll provide an example on how to open, configure and run a Qt project later on in this guide.

## Placeholders

## Hello World
A simple C++ program that does nothing is provided below:

```cpp
// A C++ program always starts from the main() function
// main() returns an integer indicating the execution state of the program
auto main()->int {
    // you may leave the function body of main() empty if it does nothing
    // the compiler automatically inserts "return 0;" for you
    // indicating the execution is successful
}
```

In a similar way that Python uses `import`s, C++ uses `#include`s. The imported functionalities are normally grouped under a namespace, which is denoted with the double colon `::` symbol. We'll use the C++ Standard Library namespace, also known as _std_, for our Hello World program

The **input/output library** (`iostream` library) is part of the C++ standard library that deals with basic input and output. We'll use the functionality in this library to get input from the keyboard and output data to the console. The _io_ part of _iostream_ stands for _input/output_.

- Available any time via `#include <iostream>`
- `std::cout` is how you will print to the command line
  - i.e. the output window in QtCreator, your IDE for this course :)
- `<<` inserts characters into the current output stream
- Works like string concatenation where the stream is the output string
- `std::endl` ends the line and inserts a newline character
- `std::cin` and `std::cerr` also exist
  - `std::cin` reads from stdin (terminal input)
  - `std::cerr` prints to stderr (terminal error messages)

#### ***Task 1:***

We are ready to write something on the screen!

- Write "Hello World!" in a `std::cout << "" << std::endl;` call in the `main` function.

At this point when you run your program you should see "Hello World!"

Now we can get into the more fun stuff!

## Primitive Types, Variables and Functions

Like many other programming languages, C++ comes with several primitive types including:

- integer-like types (integers, booleans, characters)
- floating point types
- arrays
- functions and lambdas
- pointers and references

Some of these you might already know from languages you learned before, some, such as pointers and references, are C++ concepts which we'll expand in the following sections. It is also worth noting that strings are not a primitive type in C++, string literals are simply character arrays. However, the standard library does provide the `std::string` type which allows us to perform common string operations.

C++ is a _typed_ language, meaning that we either have to declare the type when creating a variable:

```cpp
int x = 42;
double y = 3.14;
```

or use `auto` to tell the compiler to deduce the type for us from the initialization. This could be useful if the type name is very long or if we know roughly about what something is, but we're not sure about its exact type.

```cpp
auto z = 2.71; // type of z deduced as double

// I'm not exactly sure about the type of a string literal
// but I can ask the compiler to deduce it for me using auto
auto w = "random string abcd";
```

The same rules also apply to functions, the basic form of a function requires us to declare its return type, and the type for each parameter.

```cpp
auto PlusOne(int x)->int {
    return x + 1;
}
```

The return type after `->` can be omitted, in such case the compiler will deduce the return type from the return statement in the function body. You may create multiple functions with the same name and this allows you to do something called _overloading_, which you might have heard from languages like Java.

```cpp
auto PlusOne(int x)->int {
    return x + 1;
}

// overloading PlusOne
auto PlusOne(double x) { // return type will be deduced
    return x + 1; // return type deduced as double
}

auto a = PlusOne(123);  // calls PlusOne<int>
auto b = PlusOne(3.14); // calls PlusOne<double>
```

Now, we can restructure the example above a little bit better if we make `PlusOne` generic. This is easy to do in C++, we simply change the type of the corresponding parameters to `auto`, meaning they could be anything.
<details><summary>Hidden magic</summary>
    Your function would technically be a <a href="https://en.cppreference.com/w/cpp/language/function_template#Abbreviated_function_template">function template</a> if it contains at least one <em>auto</em> parameter.
</details>

```cpp
// generic PlusOne
auto PlusOne(auto x) {
    return x + 1;
}

auto a = PlusOne(123); // a == 124
auto b = PlusOne(3.14); // b == 4.14
```

There are another function-like entities in C++ called _lambdas_. We'll not explain it in detail since functional programming is outside the scope of this lab. However, we encourage you to play with it and ask questions either in TA hours or on Ed. You will likely need to use lambdas for certain extra credit features such as multithreading in your future assignments. Below shows you a toy example to get started with lambdas.

```cpp
auto Plus(auto Increment) {
    return [=](auto x) {
        return x + Increment;
    };
}

auto Apply(auto Operation, auto x) {
    return Operation(x);
}

auto x = Apply(Plus(20), 22); // x == 42
auto y = Apply(Plus(-1.1), 4.24); // y == 3.14
```

You can find more information about lambdas [here](https://en.cppreference.com/w/cpp/language/lambda).

You've probably noticed that type deduction is very powerful in C++, pushing it to the extreme could make your coding experience largely resemble working with an _untyped_ language like Python or JavaScript. However, overusing it has a negative impact on the readability and maintainability of your code.
<details><summary>Evil don't click</summary>
    And crazy compilation errors or even <a href="https://godbolt.org/z/8ozn45cMs">compiler crash</a> if your code is buggy in a certain way.
</details>
You should be careful to strike a balance between explicit type declaration and type deduction to maximize your code readability. The balance would likely be different for everybody, however, as a rule of thumb, we recommend to use type deduction for local variables in the function body, and explicitly declare the types in the function signature, unless, of course, when your function is generic and you have to use `auto` for your generic parameters and omit the return type if it depends on the generic parameters.

#### ***Task 2:***

We can now write functions and use them to process different things!

- Write a function `TimesTwo` which takes an `int`, returns an `int`, and does what the function name suggests.
- Add `std::cout << TimesTwo(21) << std::endl;` to your `main` function.

You should see `42` when you run the program.

#### ***Task 3:***

Let's use what we learned and make `TimesTwo` more interesting!

- Change the signature of `TimesTwo` and make it generic.
- You might also need to change the definition in the function body of `TimesTwo` if you used multiplication for the previous task. Note that multiplication is not defined for `std::string`, but addition is, so how do you express "times 2" in the form of addition?
- Add the following print statements to your `main` function

```cpp
std::cout << TimesTwo(123) << std::endl;
std::cout << TimesTwo(3.14) << std::endl;
std::cout << TimesTwo(std::string{ "abc" }) << std::endl;
```

You should see `246`, `6.28` and `abcabc` when you run the program.

## Create Your Own Types

Similar to how we create custom types in other languages, we can combine existing types to make a data structure, and bundle it with dedicated functions to create new types in C++. Custom types are also known as _classes_ in many languages including C++. We can use the keyword `struct` or `class` to create custom types, `struct`s and `class`es are almost the exact same thing in C++, with the only difference being that `struct`s have public member access by default and `class`es have private access by default. We'll use `struct` to refer to both `struct`s and `class`es from here. The basic form of a `struct` is shown as follows

```cpp
struct Rectangle {
    double Length; // data member, also known as a field
    double Width = 1; // field can have a default value
    // fields must be explicitly typed, you cannot use type deduction here

    // member function, also known as a method
    auto CalculateArea()->double {
        return Length * Width;
    }

    // member function that modifies the state of an object
    auto MakeItSquare(double SideLength)->void {
        Length = SideLength;
        Width = SideLength;
    }
};
```

and here's how we can use the `Rectangle` type that we just created!

```cpp
// create an instance of Rectangle
auto x = Rectangle{ .Length = 2, .Width = 4 }; 

// field names can be omitted
// in such case values in the brackets 
// will be assigned to each field sequentially 
auto y = Rectangle{ 4, 3 }; // equivalent to Rectangle{ .Length = 4, .Width = 3 }

// equivalent to Rectangle{ .Length = 5, .Width = 1 } because of the default value
auto z = Rectangle{ 5 };

// member access
auto OldLength = x.Length;
x.Length = 4;

// call member functions
auto NewArea = x.CalculateArea(); // NewArea == 16
x.MakeItSquare(OldLength); // now Length = Width = 2 for x
```

#### ***Task 4:***

Let's add more behaviors to our `Rectangle` type and enhance its capabilities!

- Add a member function `CalculatePerimeter` to `Rectangle`.
- Add `std::cout << Rectangle{ 7, 8 }.CalculatePerimeter() << std::endl;` to your `main` function.

You should see `30` when you run the program.

#### ***Task 5:***

Now that we've seen what we can do with `Rectangle`, are you ready to create a new type from ground zero?

- Create a `Circle` type using `struct`.
- `Circle` should contain a data member `Radius`, and two member functions `CalculateArea` and `CalculatePerimeter`.
- After completing your `Circle` type, create a few instances of `Circle` in your `main` function, and call their member functions.

See if your `Circle` instances exhibit the expected behaviors when you run the program.

Oof! Look what we've achieved! You might not believe it but I assure you that we've learned enough to do some non-trivial things in C++. If you had previous experience in object oriented programming, you probably know that there's something called _polymorphism_ which allows us to deal with different subtypes in the same way, as long as they're derived from the same supertype (a.k.a base type). This however requires us to define an interface (the supertype), and implement the interface for all related types. Sometimes it's hard to reason our program this way because more often, we understand things bottom-up rather than top-down. What it means is that instead of defining an interface first, and then implementing the interface for various concrete type, we start from simple concrete types without worrying about what kind of interfaces it satisfies, then we notice that some types _happen_ _to_ exhibit similar behaviors which allow us to process them uniformly. Indeed, this is the case for our `Rectangle` and `Circle`, as they come with the same member functions `CalculateArea` and `CalculatePerimeter`.

But we haven't declared a common interface for `Rectangle` and `Circle`! Can we still write something to deal with them uniformly in C++? And more importantly, have we learned the necessary tool to do that? The answer is yes, and yes we have. Remember the generic functions we learned in the previous section? It has the magic property of allowing us to do _anything_ with the `auto` parameters. So all we have to do is to pass `Rectangle` and `Circle` instances to a generic parameter.
<details><summary>Nerd talk for people who have taken CSCI1730</summary>
    The reason behind this magic is that C++ templates are <a href="https://en.wikipedia.org/wiki/Structural_type_system">structurally typed</a>, and they do not enforce <a href="https://en.wikipedia.org/wiki/Parametricity">parametricity</a>.
</details>

#### ***Task 6:***

- Navigate to the empty function `PrintShape`

```cpp
auto PrintShape(auto Shape)->void {
    // Your code here
}
```

- Complete the definition, so when you pass in either a `Rectangle` object or a `Circle` object, it prints

```cpp
Area: /* area of the shape */
Perimeter: /* perimeter of the shape */
```

- Call `PrintShape` in your `main` function with different `Rectangle` and `Circle` objects.

See if `PrintShape` exhibits the expected polymorphic behavior.
<details><summary>Nerd talk 2 for people who have taken CSCI1730</summary>
    Generic functions like PrintShape are technically known as parametric polymorphism, which is a universal quantification over types. The classic OOP polymorphism, technically known as subtype polymorphism, is an existential quantification over types. They both correspond to second order logic and in many cases, one may replace another.
</details>

## Containers and Strings

The C++ standard library provides us many useful utilities, and we'll focus on three most commonly used things:

- std::array
- std::vector
- std::string

`std::array` is a fixed length array and we can use it like the following

```cpp
#include <array> // import std::array

auto x = std::array<int, 3>{}; // need to declare element type and length

// element type and length can be deduced
// if you initialize the array immediately with values
auto y = std::array{ 3.14, 2.71 }; // deduced to std::array<double, 2>

// element access
auto z = y[0]; // z == 3.14
x[0] = 42; // now the first element of x is 42
auto [a, b, c] = x; // can be unpacked, a == 42, b == 0, c == 0

// commonly used array methods
auto LengthX = x.size(); // query length
auto UnderlyingPointer = x.data(); // we'll explain what a pointer is in the following section

// can be looped over element-wise
for (auto Element : y)
    std::cout << Element << " "; // prints 3.14 2.71
```

You can learn more about `std::array` over [here](https://en.cppreference.com/w/cpp/container/array).

`std::vector` is a dynamic size array, unlike `std::array`, it allows us to insert or remove elements anytime. It has almost all capabilities of `std::array`, however, we'd prefer `std::array` over `std::vector` whenever possible because using `std::vector` triggers dynamic memory allocation (which we'll talk about later), and thus it has a performance penalty compared to `std::array`. Below shows you the basics of `std::vector`

```cpp
#include <vector> // import std::vector

auto x = std::vector<int>{}; // need to declare element type

// element type can be deduced
// if you initialize the vector immediately with values
auto y = std::vector{ 3.14, 2.71 }; // deduced to std::vector<double>

// element manipulation
auto z = y[0]; // z == 3.14
x.push_back(42); // add an element to the end of the vector
x.push_back(123); // add another element after the 42 we just inserted
x.pop_back(); // remove the element we just added

// commonly used vector methods
x.resize(10); // resize the vector, change the number of elements it contains
y.reserve(20); // pre-allocate memory for more elements, but the number of elements stays the same
auto LengthX = x.size(); // query length
auto UnderlyingPointer = x.data(); // we'll explain what a pointer is in the following section

// can be looped over element-wise
for (auto Element : y)
    std::cout << Element << " "; // prints 3.14 2.71
```

You can learn more about `std::vector` over [here](https://en.cppreference.com/w/cpp/container/vector).

`std::string` provides basic string operations in C++, it has many methods which you can find [here](https://en.cppreference.com/w/cpp/string/basic_string). Below shows you how to create string objects, or convert string literals to `std::string`

```cpp
#include <string> // import std::string

auto x = std::string{}; // create an empty string
auto y = std::string{ "abcd hello" };  // convert a string literal to std::string

y += "efgh"; // use + to concatenate strings
```

You might have noticed that it is cumbersome to convert string literals to `std::string`, and the standard library provides us a convenient solution by simply adding an _s_ [suffix](https://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s) after a string literal.

```cpp
// need to use this namespace to gain access to custom literals in the standard library
using namespace std::literals;

auto x = "hello world"s; // x is of type std::string
```

#### ***Task 7:***

We learned the basics of containers and strings, let's trying using them!

- Create a container of strings, you're free to pick either `std::array` or `std::vector`.
- Fill the container with some strings.
- repeat each string element in the container.

Now print each string element in the container, and see if the result is as expected.

## Pointers and References

Every entity in our program, variables, functions, constants, values that a register cannot hold, they all exist somewhere in memory, and they all have a unique memory location called _memory_ _address_.

A pointer is an integer storing a memory address, and it allows us to manipulate the object at that address. We can obtain a pointer to almost anything in C++ by taking its address using the _address_ _of_ operator `&`. The obtained address will be of a pointer type, denoted by the target object type followed by a star `*`.

```cpp
int x = 42;

int* px = &x; // px is a pointer to an integer, pointing to x
auto px2 = &x; // type deduction works for pointers too, type of px2 deducted to int*
auto* px3 = &x; // partial type deduction works too, px3 is a pointer to some deduced type, auto deduced to int

// pointer variables themselves also reside somewhere in memory, you can get a pointer to pointer
auto ppx = &px; // ppx is of type int**, a pointer to a pointer to an integer

// let's see where x is located in (virtual) memory!
auto MemoryAddressOfX = reinterpret_cast<unsigned long long>(px); // cast pointer to largest integer type
std::cout << MemoryAddressOfX;
```

The first thing we can do with a pointer is to _dereference_ it, meaning obtaining the entity at the address that the pointer points to. This can be achieved by using the dereference operator which also has the form of a star `*`. Dereferencing a pointer gives us something called a _reference_, meaning the entity at a particular memory address. The reference type is denoted by the entity type followed by `&`.

```cpp
int x = 42;

int* px = &x;
int& refx = *px; // obtain a reference to x by dereferencing its pointer
int& refx2 = x; // another way to obtain a reference is to directly 'reference' it.

refx = 123; // this sets x to 123 too, because refx and x share the same memory address, they are the exact same thing!
std::cout << x; // you should see 123 here
```

#### ***Task 8:***

What is the type of `*ppx`? What about `**ppx`? Compare your answers with the TA while getting checked off!

One thing we have to be careful with references is that we **always** have to spell out `&` in the type declaration when creating a reference, whether we're using type deduction or not. Otherwise we'd be creating a copy rather than a reference.

```cpp
int x = 42;
int* px = &x;

int& refx = *px; // a reference to x, same memory address as x
auto& refx2 = x; // also a reference to x, with type deduction, same memory address
auto& refx3 = refx; // same, since refx is the same thing as x

int y = *px; // this is a copy of x! it's a new variable with its own unique address!
auto y2 = *px; // again, it's a copy with its own unique address!
auto y3 = x; // same as above
```

This is because C++ has _value_ _semantics_ by default.
<details><summary>Just to be pedantic...</summary>
    This is known as lvalue-to-rvalue <a href="https://en.cppreference.com/w/cpp/language/implicit_conversion#Lvalue_to_rvalue_conversion">type decay</a> in C++ terminology.
</details>
Now that we know C++ makes a copy when creating something from another, unless specified otherwise (i.e. creating a reference). We should really change most of the parameter types in our function signature to references, unless it's something trivial like an `int` or `double`. Otherwise, a full copy will be made for every object we passed to the function, and it could lead to serious performance problems!

```cpp
auto F(std::vector<int> Things)->void {
    // empty
}
auto BetterF(std::vector<int>& Things)->void {
    // empty
}

auto Things = std::vector{ 1, 2, 3, 4 };
F(Things); // 'Things' will be copied when you call F() because it gets passed by value!
BetterF(Things); // no copy will be made here! because 'Things' gets passed by reference!
// This also means if BetterF modifies 'Things' in any way in its function body, it will be reflected here
```

The same also applies to looping over containers.

```cpp
auto Things = std::vector{ 1, 2, 3, 4 };

// this copies every element in 'Things'
// not ideal if element type is not trivial to copy
for (auto x : Things)
    std::cout << x << std::endl;

for (auto& x : Things) // this loops over each element by reference
    x += x; // which also enables you to modify the elements
// now Things = [2, 4, 6, 8]
```

#### ***Task 9:***

Let's try our hand at references!

- Navigate to the empty function `DoubleEachElement`, this function takes any container and doubles each element in the container.

```cpp
auto DoubleEachElement(/* ??? Container */)->void {
    // your code here
}
```

- Uncomment the `Container` parameter, replace `???` with a proper type declaration. (hint: references work with generic parameters too!).
- Complete the function body using what we learned.
- Pass different `std::array` and `std::vector` objects to `DoubleEachElement` in your `main` function.

Print the results after `DoubleEachElement` calls, see if it matches your expectation!

One problem with the basic form of references we've learned so far, is that they cannot bind to _values_ ([rvalue](https://en.cppreference.com/w/cpp/language/value_category#rvalue) in C++ terminology). The reason is obvious, values such as `123` or `3.14` do not have a memory address because they are not stored in memory by some variable. The same applies to function parameters, we cannot pass values to reference parameters.

```cpp
auto BetterF(std::vector<int>& Things)->void {
    // empty
}

auto x = 42;
auto Things = std::vector{ 1, 2, 3, 4 };

auto& refx = x; // OK, bind to a variable
// auto& IncorrectRef = 42; // error, (lvalue) reference cannot bind to (r)value

BetterF(Things); // OK, reference parameter binds to 'Things'
// BetterF(std::vector{ 1, 2, 3, 4 }); // error, (lvalue) reference parameter cannot bind to (r)value
```

This can be inconvenient in some cases. Ideally, we'd want something that behaves like a reference when we bind it to a variable, and like a new variable when we provide it a value. Luckily, we do have something exactly like this in C++ called _forwarding_ _references_ in the form of `auto&&`.
<details><summary>Be careful though</summary>
    && after a concrete type, like int&& or std::vector&lt;int&gt;&&, does not form a forwarding reference! These are rvalue references which are outside the scope of this lab. However, you can learn more about rvalue references <a href="https://en.cppreference.com/w/cpp/language/reference#Rvalue_references">here</a>, if you're interested.
</details>

```cpp
auto EvenBetterF(auto&& Things)->void {
    // empty
}

auto x = 42;
auto Things = std::vector{ 1, 2, 3, 4 };

auto&& refx = x; // OK, bind to a variable, same as 'auto& refx = x;'
auto&& ForwardRef = 42; // OK, creates a new variable as if 'auto ForwardRef = 42;'

EvenBetterF(Things); // OK, reference parameter binds to 'Things'
EvenBetterF(std::vector{ 1, 2, 3, 4 }); // OK, as if the parameter type is non-reference
```

## Pointer Arithmetic (consider moving to Pencil)

## Dynamic Memory Management and Smart Pointers (consider moving to Pencil)