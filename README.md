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
6. [What do we use?](#the-program)
7. [Actual Implementation](#implementation)
8. [Sorting Algorithms](#sorting-algorithms)
9. [Analysis](#analysis)
10. [References Used](#references)

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

7. Note: `#include <time.h>` for C, is same as `#include <ctime>` in C++.

   🤍 ~ `Extra` ~ 🤍

8. User has the choice if he/she want to use randomly generated values or the sorted increasing order at the start of the program - So there is no need for the user to modify the code to alter the results.

9. Input checker `if (num <= 0)`, preventing errors and check if it exceeds the MAXIMUM VALUE.

10. Uses only the standard functions to work on multiple platforms.

> Programming Language used: `C++`.

<br>

---

<br>

## Test Run

https://user-images.githubusercontent.com/80235976/163752931-ad70ead9-d20c-4cee-9f40-03089bde1c99.mp4

<br>

---

<br>

## The Output

Using the default text editor for Windows is a pain since it generates a lot of unnecessary characters - mainly Chinese keywords instead of numbers. As a group, we have to solve this. At first, we use the tipical `.txt` as output. But that does not change the old output for other Copmuters. We have test `.out` and it works fine but still generated Chinese keywords for other Computers.

`[Sorted Generated Values]` For Joemar, it was fine (both runtime and seeing the results) but for Paolo and Adrian after using the program (is ok) - but after cheking the result to a notepad viewer they see a lot of generated Chinese Characters instaed of the array value.

`[Random Generated Values]` is good since it does not generated a single problem for us.

In conclusion: it is highly suggested to use other text viewer to view result incase the generated arrays are unreadable or in Chinese Characters.

<br>

---

<br>

## Problems Encountered

1. Too many T(n) values yielded zeroes for set values of N when using the clock() when getting processor times.
2. Group member availability.
3. During the implementation of random sorted initializations, the program would often skip the prompt for asking the x values after getting N.
4. Sorted initializations, specifically with N values of 10000 would produce outputs that displayed Chinese characters when opened in Notepad. This behavior is only present with Notepad, other text viewers properly show the intended output of the program.
5. For sorted values generated, If X is 0 to 40.....[@Adrian]

## Solving Problems

<br>

---

<br>

## The Program

<br>

---

<br>

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
    return stored_value;
}
```

<br><br>

> It uses both `sstream` and `cstring`.

```c++
#include <sstream>
#include <cstring>
```

<br>

---

<br>

## Sorting Algorithms

> Insertion Sort:

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

> Both Quick and Heap sort uses this function for swapping:

```c++
void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
```

> Quick Sort:

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

- [x] Check 1
- [ ] Uncheck 2

<br>

---

<br>

Group note: The program is challenging and at the same time `fun`. It is a group effort and we are happy to present what we have learned and what are the stugles that we encounter by doing the project.
Even we have a lot of problems enountered, but the group is there to understand each other's concern and make a new schedule for a meeting incase we have something to clarify about the project.
We used different strategies mainly data structures in the problems to experement but failed. But that failure help us to understand what are small mistakes that we made and make things better. We hope that everyone is understandable.

<br>

---

<br>

# Thank You For Reading This File
