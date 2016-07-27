#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randomArray(int a[], int numOfElements);
void bigArray(int a[], int& numOfElements);
void print(int a[], const int& numOfElements);

void mergeSort(int data[ ], int n, int& comparisons);
// Running time: O(n log n) => this includes the call to function merge
// Uses function merge

void merge(int data[ ], int n1, int n2, int& comparisons);
// Running time: O(n)

const int CAPACITY = 10;		

int main()
{
	int a1[CAPACITY];		// sorted in ascending order
	int a2[CAPACITY];		// sorted in descending order

	for (int i = 0; i < CAPACITY; ++i)
	{
		a1[i] = i + 1;
		a2[i] = CAPACITY - i;
	}

	int a3[CAPACITY];		// random

	int numOfElem = CAPACITY;

	randomArray(a3,numOfElem);  

	//TEST ARRAY 1
	cout << "Array 1 is:\n";
	print(a1,numOfElem);
	int comparisonsA1 = 0;
    mergeSort(a1,numOfElem,comparisonsA1);
	cout << "\n\nArray 1 sorted:\n";
	print(a1,numOfElem);
	cout << "\n\nMERGE SORT NUMBER OF COMPARISONS: "
		<< comparisonsA1;
	
	cout << "\n-------------------------------------------------------------------\n\n";

	//TEST ARRAY 2
	cout << "Array 2 is:\n";
	print(a2,numOfElem);
	int comparisonsA2 = 0;
    mergeSort(a2,numOfElem,comparisonsA2);
	cout << "\n\Array 2 sorted:\n";
	print(a2,numOfElem);
	cout << "\n\nMERGE SORT NUMBER OF COMPARISONS: "
		<< comparisonsA2;
	cout << endl;

	cout << "\n-------------------------------------------------------------------\n\n";
	
	//TEST ARRAY 3
	cout << "Array 3 is:\n";
	print(a3,numOfElem);
	int comparisonsA3 = 0;
    mergeSort(a3,numOfElem,comparisonsA3);
	cout << "\n\nArray 3 sorted:\n";
	print(a3,numOfElem);
	cout << "\n\nMERGE SORT NUMBER OF COMPARISONS: "
		<< comparisonsA3;
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}

void randomArray(int a[], int numOfElements)
{
	srand(static_cast<unsigned int>(time(0)));  
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);
}

void print(int a[], const int& numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}

void mergeSort(int data[ ], int n, int& comparisons)
{
	// Running time: O(n log n)

    int n1; // Size of the first subarray
    int n2; // Size of the second subarray

    if (n > 1)
    {
        // Compute sizes of the subarrays.
        n1 = n / 2;
        n2 = n - n1;

        mergeSort(data, n1, comparisons);         // Sort from data[0] through data[n1-1]
        mergeSort((data + n1), n2, comparisons);  // Sort from data[n1] to the end

        // Merge the two sorted halves.
        merge(data, n1, n2, comparisons);
    }
}

void merge(int data[ ], int n1, int n2, int& comparisons)
{
    int *temp;			// Points to dynamic array to hold the sorted elements
    int copied  = 0;	// Number of elements copied from data to temp
    int copied1 = 0;	// Number copied from the first half of data
    int copied2 = 0;	// Number copied from the second half of data

    // Allocate memory for the temporary dynamic array.
    temp = new int[n1 + n2];

    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2))
    {
		++comparisons;
        if (data[copied1] < (data + n1)[copied2])
            temp[copied++] = data[copied1++];        // Copy from first half
        else
            temp[copied++] = (data + n1)[copied2++]; // Copy from second half
    }

    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
        temp[copied++] = data[copied1++];
    while (copied2 < n2)
        temp[copied++] = (data+n1)[copied2++];

    // Copy from temp back to the data array, and release temp's memory.
    for (int i = 0; i < n1+n2; ++i)
        data[i] = temp[i];
    delete [ ] temp; 
	temp = NULL;
}
