# ⭐️ **CS111 Mid Term Project** ⭐️

This project is intended to give the proper calculations for time effiency of the Sorting Algorithms _(Insertion Sort, Merge Sort, Quick Sort, Heap Sort)_

<br>

---

<br>

![Logo](https://static.vecteezy.com/system/resources/previews/000/371/208/original/vector-welcome-hand-drawn-text.jpg)

## Members

- [Joemar Cardiño](https://github.com/joemar25 "Joemar's Github") 👋🏻
- [Paolo Bono Cuenca](https://www.facebook.com/100004747590876/ "Paolo's Profile Page") ✌🏻
- [Adrian Jones Abache](https://github.com/AdrianJones23 "Adrian's Github") 🤙🏻

## Tables of Contents

1. [The Program's Behaviour and Feature](#the-programs-behaviour-and-features)
2. [Actual Test Run](#test-run)
3. [Actual Output](#the-output)
4. [What are the Problems we encountered?](#problems-encuntered)
5. [How did we solve those problems?](#solving-problems)
6. [What do we use and the implementations](#the-program)
7. [Sorting Algorithms](#sorting-algorithms)
8. [Analysis](#analysis)
9. [References Used](#references)

<br>

---

<br>

## The Program's Behaviour and Features

1. User is asked for `N` values.

2. Generates `N` integers which are either Randomly and Sorted (in increasing order).

3. Sorts the values using different Algorithms.

4. Output a file containing the `T(n)` that spends on using the different algorithms for sorting and the generated 'N' integers (original and sorted).

5. The sorting algorithms are implemented on different functions.

6. Use `#include <ctime>` header to use `clock()` function on helping us to calculate the T(n).

7. Note: `#include <time.h>` for C, is the same as `#include <ctime>` in C++.

   🤍 ~ `Extra` ~ 🤍

8. The user has the choice if he/she wants to use randomly generated values or the sorted increasing order at the start of the program - So there is no need for the user to modify the code to alter the results.

9. Input checker `if (num <= 0)`, prevent errors and checks if it exceeds the MAXIMUM VALUE.

10. Uses only the standard functions to work on multiple platforms.

> Programming Language used: `C++`.

<br>

---

<br>

## Test Run

Below is the test run (Restrictions) for inputs on selecting if the user wants to use array that are randomly initialized or sorted initialized.

https://user-images.githubusercontent.com/80235976/163752931-ad70ead9-d20c-4cee-9f40-03089bde1c99.mp4

Below is the test run for all values that are need to analyze if the array has random values.

https://user-images.githubusercontent.com/80235976/163754897-e695b4e3-d93b-4b13-8c7e-02823d4eb5d5.mp4

Below is the test run for all values that are need to analyze if the array has sorted values.

https://user-images.githubusercontent.com/80235976/163755648-ab8ad641-82f3-48f7-af49-db33c375e6be.mp4

<br>

> Note: Video file uploading size in README.md must be below 10mb. So, we apologize for the quality.

<br>

---

<br>

## The Output

##### _NEED TO OUTPUT_

- original and sorted values
- computation time T(N) for sorting N integers (not the time spent by user inputing)

<br>

Randomize Initialized Array Values

> Using N = 100000

![RANDOMIZE](https://user-images.githubusercontent.com/80235976/163756226-42a76de3-d5e7-4dc5-91ff-05cddc2d5710.PNG)

<br>

Sorted Initialized Array Values

> Using N = 100000 and X = 7

![ALREADY SORTED](https://user-images.githubusercontent.com/80235976/163756230-ceeb10d5-1007-4a54-aeb1-6f93bde0afa8.PNG)

<br>

Using the default text editor for Windows is a pain since it generates a lot of unnecessary characters - mainly Chinese keywords instead of numbers. This always happened in `[Sorted Generated Values]` when N is equals to 10000. As a group, we have solved this. At first, we use the typical `.txt` as output. But that does not change the old output for other Copmuters. We have tested `.out` and it works fine but still generated Chinese keywords for other Computers. While attempting to resolve the issue, we discovered that the output is fine when the value of x is greater. As a result, we conducted a trial and error to find the smallest value of X that will provide acceptable results. The value of X should be 41 and higher.

`[Sorted Generated Values]` For Joemar, it was fine (both runtime and seeing the results) but for Paolo and Adrian after using the program (is ok) - but after cheking the result to a notepad viewer they observed a lot of generated Chinese Characters instead of the array value.

`[Random Generated Values]` works properly as it had not generated a single problem for us.

`In conclusion:` It is highly suggested to use other text viewers to view the results incase the generated arrays are unreadable or in Chinese Characters. (VS code, DevC++, MS Word...)

<br>

---

<br>

## Problems Encountered

1. Too many T(n) values yielded zeroes for set values of N when using the clock() when getting processor times.
2. Group member availability.
3. Sorted initializations, specifically with N values of 10000 would produce outputs that displayed Chinese characters when opened in Notepad. This behavior is only present with Notepad, other text viewers properly show the intended output of the program.

## Solving Problems

- Making a function to lessen or remove the loop in our main function (_see: [The Program : String Function](#the-program)_).

- Using constant (`const data_type var_name`) to make variable unchangable during the function call is a handy way to secure the data that we need to handle.

- Using reference (`data_type &var_name`) instead of typical pass by value to a function, making sure that we only have one variable declaration instead of making another copy of that variable.

- `Getting The sorted values`

```
(TEST)
N = 3
X = 6

NOTE: N + (2)X = N + (2 * X)
        our program will use N + ((i + 1) * X)

let i = 0
    array[0] = N+(1)X => 3+(i+1)6 => 3+( (0 + 1) * 6) => 3+( 1 * 6) = 9
    array[1] = N+(2)X => 3+(i+1)6 => 3+( (1 + 1) * 6) => 3+( 2 * 6) = 15
    array[2] = N+(3)X => 3+(i+1)6 => 3+( (2 + 1) * 6) => 3+( 3 * 6) = 21

array values = 8, 13, 18
```

<br>

---

<br>

## The Program

The Array Used

> As programmers, we need to efficiently manage and manipulate the computer's memory.

> So we have to take advantage of dynamic memory allocation using C++.

> “In dynamic memory allocation, memory is allocated during runtime. But, in this case, it is the responsibility of a programmer to deallocate the dynamically allocated memory when it’s no longer in use. Otherwise, it leads to memory leaks.”

> In the given problem, we are tasked to ask the user to get input in which we need to adjust the size of the array. “We do not know in advance the amount of memory required to store some data.” So, Dynamic allocation is the solution for that.

```c++
    int *array = NULL;
    array = new int[N];
```

<br>

For the include files used by the program.

```c++
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#define MAXRANGE 1000000
```

> `<iostream>`helps us to use cout and cin (basically we need it, for us to input and output something.)

> `<cstdlib>` helps us to use several general-purpose functions that are defined in this header, including dynamic memory management, random number generation, communication with the environment, integer arithmetic, searching, sorting, and converting.

> `<cstring>` helps us to use string in our code

> `<sstream>` helps us to use sstream, which is an object that was declared to perform the input/output operations on strings _(we use this to convert the integer to a string for us to easily output them without using repeated loops in our main._

> `<fstream>` helps us to use File, to output/write to files.

> `<ctime>` helps us to use

> `MAXRANGE 1000000` is used as a default value for the maximum range

<br>

For printing the array values without using a lot of for-loops in the main function, we have used the function below:

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
    return stored_value;
}
```

> Above It uses both `sstream` and `cstring`.

```c++
#include <cstring>
#include <sstream>
```

> The string stream associates a string object with a string. Using this we can read from string as if it were a stream like cin. As said, we use this to perform a convertion from integer to string. Why? we want to lessen the loop inside the main function.

<br>

For Getting the input, we have again used the function.

```c++
void Input(int *num, const char var_initial)
{
    int num_in = 0;
    while (!(num_in > 0 && num_in <= MAXRANGE))
    {
        printf("Input value for %c: ", var_initial);
        std::cin >> num_in;
        if (num_in < 1 || num_in > MAXRANGE)
            printf("Invalid value for %c. Please Try Again.\n\n", var_initial);
    }
    *num = num_in;
}
```

> First, we will needing the memory address of the number from the main function, and determmine whether it is for `N` or `X`. This is a good implementation for us since again, _We have a goal to lessen or remove all the loop inside our main function_.

> This limits the users from entering wrong inputs. That is why we have included this in our program.

> Why is it the var initial does not use `&var_initial`? it is because throught the program we will use this function 2 times. It is one of the rules of references to referece only one variable, so in respect for the rule, we only use constant - for the data to be unmodified.

<br>

For Randomize Initialization of values for arrays.

```c++
void RandomizeInitialization(int *ARRAY, const int &N)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        ARRAY[i] = (rand() % MAXRANGE);
}
```

> If random numbers are generated with rand() without first calling srand(), your program will create the same sequence of numbers each time it runs.

> If statement does not contain srand set to time(0) or srand set to time(NULL), then running the program again and again will result to same random numbers. Else each execution of the program will have different random results that will be set as array values.

<br>

For Sorted Initialization of values for arrays.

```c++
void SortedInitialization(int *ARRAY, const int &N, const int &X)
{
    for (int i = 0; i < N; i++)
        ARRAY[i] = N + ((i + 1) * X);
}
```

> (_see: [Solving the problem : Getting The sorted values](#solving-problems)_).

<br>

For a convinient way to copy array to another array.

```c++
void Copy(int *ORIGINAL_COPY, int *HOLDER, const int &N, const int &option)
{
    if (option != 1)
        return;
    for (int i = 0; i < N; i++)
        HOLDER[i] = ORIGINAL_COPY[i];
}
```

> The function gets two sets of array, and depending on the constant references option - the loop will copy the array to another or not. This keep the memory usage less and more effiencient than. Randoming again and again if the user chooses to have a randomize values for the array.

<br>

---

<br>

## Sorting Algorithms

> Insertion Sort:

It uses the functions below to use the sorting method for Insertion Sort.

```c++
void InsertionSort(int *ARRAY, const int &length)
{
    for (int i = 1; i < length; i++)
    {
        int key = ARRAY[i], j = i;
        while (j > 0 && ARRAY[j - 1] > key)
        {
            ARRAY[j] = ARRAY[j - 1];
            j--;
        }
        ARRAY[j] = key;
    }
}
```

> Merge Sort:

It uses the functions below to use the sorting method for Merge Sort.

```c++
void Merge(int *ARRAY, const int lower, const int middle, const int upper)
{
    int i, j, k;
    int left[middle - lower + 1];
    int right[upper - middle];

    for (i = 0; i < middle - lower + 1; i++)
        left[i] = ARRAY[lower + i];
    for (j = 0; j < upper - middle; j++)
        right[j] = ARRAY[middle + 1 + j];

    i = 0;
    j = 0;
    k = lower;

    for (k = lower; i < middle - lower + 1 && j < upper - middle; k++)
    {
        if (left[i] <= right[j])
            ARRAY[k] = left[i++];
        else
            ARRAY[k] = right[j++];
    }

    while (i < middle - lower + 1)
        ARRAY[k++] = left[i++];
    while (j < upper - middle)
        ARRAY[k++] = right[j++];
}

void MergeSort(int *ARRAY, const int lower, const int upper)
{
    if (lower >= upper)
        return;
    MergeSort(ARRAY, lower, (lower + upper) / 2);
    MergeSort(ARRAY, ((lower + upper) / 2) + 1, upper);
    Merge(ARRAY, lower, (lower + upper) / 2, upper);
}
```

> Both Quick and Heap sort uses this function for swapping.

```c++
void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
```

> Quick Sort:
> It uses the functions below to use the sorting method for Quick Sort.

```c++
int Partition(int *ARRAY, const int low, const int high)
{
    int index = low, pivot = high;
    for (int i = low; i < high; i++)
    {
        if (ARRAY[i] < ARRAY[pivot])
        {
            Swap(&ARRAY[i], &ARRAY[index]);
            index++;
        }
    }
    Swap(&ARRAY[pivot], &ARRAY[index]);
    return index;
}

int RandomPivotPartition(int *ARRAY, const int low, const int high)
{
    int pvt = low + rand() % (high - low + 1);
    Swap(&ARRAY[high], &ARRAY[pvt]);
    return Partition(ARRAY, low, high);
}

void QuickSort(int *ARRAY, const int low, const int high)
{
    if (low < high)
    {
        int pivotIndex = RandomPivotPartition(ARRAY, low, high);
        QuickSort(ARRAY, low, pivotIndex - 1);
        QuickSort(ARRAY, pivotIndex + 1, high);
    }
}
```

> Heap Sort:

It uses the functions below to use the sorting method for Heap Sort.

```c++
void Heapify(int *ARRAY, const int length, const int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < length && ARRAY[left] > ARRAY[largest])
        largest = left;
    if (right < length && ARRAY[right] > ARRAY[largest])
        largest = right;
    if (largest != index)
    {
        Swap(&ARRAY[index], &ARRAY[largest]);
        Heapify(ARRAY, length, largest);
    }
}

void HeapSort(int *ARRAY, int length)
{
    int i;
    for (i = length / 2 - 1; i >= 0; i--)
        Heapify(ARRAY, length, i);
    for (i = length - 1; i >= 0; i--)
    {
        Swap(&ARRAY[0], &ARRAY[i]);
        Heapify(ARRAY, i, 0);
    }
}
```

<br>

---

<br>

## Analysis

When array is Sorted:

|      N | Insertion sort | Mergesort | Quicksort | Heapsort |
| -----: | :------------- | :-------- | :-------- | :------- |
|     10 | 0              | 0         | 0         | 0        |
|    100 | 0              | 0         | 0         | 0        |
|   1000 | 0              | 0         | 0         | 0.0004   |
|  10000 | 0              | 0.0008    | 0.0008    | 0.0012   |
| 100000 | 0              | 0.0134    | 0.0266    | 0.0374   |

When array is Random:

|      N | Insertion sort | Mergesort | Quicksort | Heapsort |
| -----: | :------------- | :-------- | :-------- | :------- |
|     10 | 0              | 0         | 0         | 0        |
|    100 | 0              | 0         | 0         | 0        |
|   1000 | 0.0026         | 0         | 0         | 0        |
|  10000 | 0.036          | 0.0012    | 0.001     | 0.0012   |
| 100000 | 3.5818         | 0.014     | 0.0114    | 0.0172   |

The tables above are the average processor time for each sorting algorithm for a set value of N.

<br>

---

<br>

## References

<br>
Dynamic Memory Allocation in C++

- https://techvidvan.com/tutorials/cpp-dynamic-memory-allocation/

Generating Random Numbers

- https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

Insertion Sort

- https://www.tutorialspoint.com/design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_insertion_sort.htm

Time for C/C++

- http://www.gnu.org/software/libc/manual/html_node/CPU-Time.html

-https://www.tutorialspoint.com/how-to-use-clock-function-in-cplusplus

Standard Library

- https://www.programiz.com/cpp-programming/library-function/cstdlib

File Handling

- https://www.guru99.com/cpp-file-read-write-open.html

Quick Sort Problem

- https://stackoverflow.com/questions/63686324/quicksort-to-already-sorted-array

String Stream

- https://www.tutorialspoint.com/stringstream-in-cplusplus

- https://sonnevision.wordpress.com/2012/01/11/how-to-clear-a-stringstream/

<br>

---

<br>

Group note:

The program is challenging and at the same time `fun`. It is a group effort and we are happy to present what we have learned and what are the stugles that we encounter by doing the project.
Even we have a lot of problems enountered, but the group is there to understand each other's concern and make a new schedule for a meeting incase we have something to clarify about the project.
We used different strategies mainly data structures in the problems to experement but failed. But that failure help us to understand what are small mistakes that we made and make things better. We hope that everyone is understandable.

<br>

---

<br>

# `Thank You For Reading This File`
