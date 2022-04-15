# ⭐️ **CS111 Mid Term Project** ⭐️

This project is intended to give the proper calculations for time effiency of the Sorting Algorithms _(Insertion Sort, Merge Sort, Quick Sort, Heap Sort)_

---

![Logo](https://static.vecteezy.com/system/resources/previews/000/371/208/original/vector-welcome-hand-drawn-text.jpg)

## Members

- [Joemar Cardiño](https://github.com/joemar25 "Joemar's Github Link") 👋🏻
- [Paolo Cuenca](link) ✌🏻
- [Adrian Abache](link) 🤙🏻

## Tables of Contents

1. [a](#the-programs-behaviour-and-features)
2. b
3. [c](#implementation)

---

## The Program's Behaviour and Features

1. User is asked for `N` values.
2. Generates `N` integers which are either Randomly and Sorted (in increasing order).
3. Sorts the values using different Algorithms.
4. Output a file containing the `T(n)` that spends on using the different algorithms for sorting and the generated 'N' integers (original and sorted).
5. The sorting algorithms are implemented on different functions.
6. Use `#include <ctime>` header to use `clock()` function on helping us to calculate the T(n).
7. Note: `#include <time.h>` for C, is same as `#include <ctime>` in C++.

   🤍 ~ `Extra` \~ 🤍

8. User has the choice if he/she want to use randomly generated values or the sorted increasing order at the start of the program - So there is no need for the user to modify the code to alter the results.
9. Input checker if value `<= 0`, preventing errors and check if it exceeds the MAXIMUM VALUE.

10. Uses only the standard functions to work on multiple platforms.

> Programming Language used: `C++`.

---

## Implementation

> For printing the array values without using a lot of for-loops in the main function, we have used the function below:

```c++
std::string GetArray(const int *ARRAY, const int &N)
{
    std::stringstream stream;
    std::string stored_value = "";
    std::string temp;

    for (int i = 0; i < N; i++)
    {
        stream << ARRAY[i];
        stream >> temp;
        stored_value += " " + temp;
        stream.clear();
    }
    return stored_value; // return string
}
```

> It uses both `sstream` and `cstring`.

```c++
#include <sstream>
#include <cstring>
```

Analysis:

| N      | Insertion sort | Merge sort | Quicksort | Heapsort |
| ------ | -------------- | ---------- | --------- | -------- |
| 10     | 0              | 0          | 0         | 0        |
| 100    | 0              | 0          | 0         | 0        |
| 1000   | 0              | 0          | 0         | 0        |
| 10000  | 0              | 0          | 0         | 0        |
| 100000 | 0              | 0          | 0         | 0        |
