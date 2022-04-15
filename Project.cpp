#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <fstream>
#include <ctime>
#define MAXRANGE 1000000

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

void Input(int *num, const char var_initial)
{
    int num_in = 0;                             // number for test inputs
    while (!(num_in > 0 && num_in <= MAXRANGE)) // repeat if number-input less than 1 and number-input is larger than MAXRANGE
    {
        printf("Input value for %c: ", var_initial);                            // prompting message
        std::cin >> num_in;                                                     // number input
        if (num_in < 1 || num_in > MAXRANGE)                                    // check if valid
            printf("Invalid value for %c. Please Try Again.\n\n", var_initial); // if true, print a message
    }
    *num = num_in; // assign the num_in final value to num
}

void RandomizeInitialization(int *ARRAY, const int &N)
{
    srand(time(NULL));                  // each execusion of the program, will result to a randomize number
    for (int i = 0; i < N; i++)         // loop to n
        ARRAY[i] = (rand() % MAXRANGE); // assign each randomize value to the array
}

void SortedInitialization(int *ARRAY, const int &N, const int &X)
{
    for (int i = 0; i < N; i++)       // loop to n
        ARRAY[i] = N + ((i + 1) * X); // assign each sorted customized values to the array
}

void Copy(int *ORIGINAL_COPY, int *HOLDER, const int &N, const int &option)
{
    if (option != 1) // check if the option selected by user is not equal to 1
        return;
    for (int i = 0; i < N; i++)       // if false, then loop to n
        HOLDER[i] = ORIGINAL_COPY[i]; // each values of the original array will be assigned to the holder
}

void InsertionSort(int *ARRAY, const int &length)
{
    for (int i = 1; i < length; i++) // loop from 1 to n
    {
        int key = ARRAY[i], j = i;          // set key to i and set j to match i
        while (j > 0 && ARRAY[j - 1] > key) // while j greater than 0 and array is greater than key - repeat
        {
            ARRAY[j] = ARRAY[j - 1]; // while true, change value of array[j] to array[j-1]
            j--;                     // decrement j, until it reached 0, for condition to be false
        }
        ARRAY[j] = key; // assign key to array[j]
    }
}

void Merge(int *ARRAY, const int lower, const int middle, const int upper)
{
    int i, j, k;                  // initialize variables to be used
    int left[middle - lower + 1]; // create temp array for left side
    int right[upper - middle];    // create temp array for right side

    for (i = 0; i < middle - lower + 1; i++) // loop from 0 to the middle size of the array
        left[i] = ARRAY[lower + i];          // assign the values from the left to middle
    for (j = 0; j < upper - middle; j++)     // loop from 0 to the middle size of the array
        right[j] = ARRAY[middle + 1 + j];    // assign the values from the right to end

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

void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

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

int main()
{
    clock_t start, end;

    std::ofstream outputFile;
    outputFile.open("record.txt");

    if (!outputFile.is_open())
    {
        std::cout << "Error Opening output file" << std::endl;
        return -1;
    }

    // initialize variables, pointer array initialised with NULL
    int input = 0, N = 0, X = 0, *array = NULL, *temp = NULL;

    std::cout << "Welcome to our Project\n\n";
    while (input != 1 && input != 2)
    {
        std::cout << " Choose 1 [To Use Random Initialized Array]" << std::endl;
        std::cout << " Choose 2 [To Use Sorted Initialized Array]\n Input: ";
        std::cin >> input;
        std::cout << std::endl;
    }
    Input(&N, 'N');     // get N (size)
    array = new int[N]; // request memory

    if (input == 1)
    {
        temp = new int[N]; // request memory for temp as N
        RandomizeInitialization(array, N);
        Copy(array, temp, N, input);
        outputFile << "Randomize Initialization\n\t";
    }
    if (input == 2)
    {
        temp = new int[0]; // set memory for temp as 0 [unsed and unallocated]
        Input(&X, 'X');
        SortedInitialization(array, N, X);
        outputFile << "Sorted Initialization\n\t";
    }
    outputFile << "Original Array :" + GetArray(array, N) << std::endl;

    // Insertion Sort
    start = clock();
    InsertionSort(array, N);
    end = clock();
    outputFile << "\n\tSorted Array   :" << GetArray(array, N) << "\n\n\nAnalysis\n";
    outputFile << "\tInsertion Sort T(N) = " << ((double)(end - start)) / CLOCKS_PER_SEC << std::endl;

    // Merge Sort
    Copy(temp, array, N, input);
    start = clock();
    MergeSort(array, 0, N - 1);
    end = clock();
    outputFile << "\tMerge Sort T(N) = " << ((double)(end - start)) / CLOCKS_PER_SEC << std::endl;

    // Quick Sort
    Copy(temp, array, N, input);
    start = clock();
    QuickSort(array, 0, (N - 1));
    end = clock();
    outputFile << "\tQuick Sort T(N) = " << ((double)(end - start)) / CLOCKS_PER_SEC << std::endl;

    // Heap Sort
    Copy(temp, array, N, input);
    start = clock();
    HeapSort(array, N);
    end = clock();
    outputFile << "\tHeap Sort T(N) = " << ((double)(end - start)) / CLOCKS_PER_SEC << std::endl;

    delete[] array; // Releases memory pointed to by array
    delete[] temp;  // Releases memory pointed to by array
    return 0;
}
