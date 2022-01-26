// CS218
// Sean Derba
// Sorting Practice

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int Itemtype;

void SelectionSort(Itemtype[], int);

void InsertionSort(Itemtype[], int);

void BubbleSort(Itemtype[], int);

void EnhancedBubbleSort(Itemtype[], int);

void MergeSort(Itemtype[], int, int);

void Merge(Itemtype[], int, int, int);

void QuickSort(Itemtype[], int, int);

int Partition(Itemtype[], int, int, int);

void displayData(Itemtype[], int);

int getRandomNum();

void SwapValues(Itemtype&, Itemtype&);

int FindSmallest(Itemtype[], int, int);

void GetRandomData(Itemtype[], int);

bool VerifyInput(string, string, string);

void GetUserData(Itemtype[], int);

void CopyArray(Itemtype[], Itemtype[], int);

int main()
{
	srand(218);

	const int MaxSize = 1000;
	Itemtype unsortedData[MaxSize];
	Itemtype sortedData[MaxSize];


	int num;

	cout << "Enter number of elements: ";
	cin >> num;
	cout << endl;

	string input;

	cout << "Would you like to use randomly generated numbers? (Y/N) :";
	cin >> input;

	bool verify = VerifyInput(input, "Y", "N");

	if (verify == true) {
		GetRandomData(unsortedData, num);
	}
	else {
		GetUserData(unsortedData, num);
	}

	/*CopyArray(unsortedData, sortedData, num);



	clock_t begin_time = clock();
	SelectionSort(sortedData, num);
	clock_t end_time = clock();
	
	double elapsed = double(end_time - begin_time);

	cout << "Selection sort: " << elapsed / CLOCKS_PER_SEC << " seconds elapsed for " << num << " elements" << endl;
	
	CopyArray(unsortedData, sortedData, num);

	begin_time = clock();
	InsertionSort(sortedData, num);
	end_time = clock();

	elapsed = double(end_time - begin_time);

	cout << "Insertion sort: " << elapsed / CLOCKS_PER_SEC << " seconds elapsed for " << num << " elements" << endl;

	
	CopyArray(unsortedData, sortedData, num);

	begin_time = clock();
	BubbleSort(sortedData, num);
	end_time = clock();

	elapsed = double(end_time - begin_time);

	cout << "Bubble sort: " << elapsed / CLOCKS_PER_SEC << " seconds elapsed for " << num << " elements" << endl;


	CopyArray(unsortedData, sortedData, num);

	begin_time = clock();
	EnhancedBubbleSort(sortedData, num);
	end_time = clock();

	elapsed = double(end_time - begin_time);

	cout << "Enhanced Bubble sort: " << elapsed / CLOCKS_PER_SEC << " seconds elapsed for " << num << " elements" << endl;
	*/

	displayData(unsortedData, num);
	QuickSort(unsortedData, 0, num - 1);
	displayData(unsortedData, num);

	return 0;
}

void SelectionSort(Itemtype data[], int n)
{
	Itemtype min;
	Itemtype temp;
	int position;
	for (int i = 0; i < n - 1; i++) {

		position = FindSmallest(data, n, i);

		SwapValues(data[i], data[position]);
	}
	

}

void InsertionSort(Itemtype data[], int n) {
	Itemtype temp;
	int index;
	for (int i = 1; i < n; i++) {
		temp = data[i];
		index = i;
		for (int j = i - 1; j >= 0; j--) {
			if (temp >= data[j]) {
				break;
			}
			else {
				index = j;
				data[j + 1] = data[j];
			}
		}
		data[index] = temp;
	}
	
}


void BubbleSort(Itemtype data[], int num) {		
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < num - i; j++) {
			if (data[j] > data[j + 1]) {
				SwapValues(data[j], data[j + 1]);
			}
		}
	}
}

void EnhancedBubbleSort(Itemtype data[], int num) {		//Enhanced version has break, regular does not
	bool isSorted;
	for (int i = 1; i < num; i++) {
		isSorted = true;
		for (int j = 0; j < num - i; j++) {
			if (data[j] > data[j + 1]) {
				SwapValues(data[j], data[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted == true) {
			break;
		}
	}
}

void MergeSort(Itemtype data[], int first, int last){
	if (first != last) {
		int middle = (first + last) / 2;
		MergeSort(data, first, middle);
		MergeSort(data, middle + 1, last);
		Merge(data, first, middle, last);
	}
	else {
		return;
	}
}

void Merge(Itemtype data[], int first, int middle, int last) {
	const int size = 1000;
	Itemtype temp [size];
	int index1, index2, index;
	index1 = first;
	index2 = middle + 1;
	index = 0;
	while (index1 <= middle && index2 <= last) {
		if (data[index1] < data[index2]) {
			temp[index] = data[index1];
			index1++;
			index++;
		}
		else {
			temp[index] = data[index2];
			index2++;
			index++;
		}
	}
	while (index2 <= last) {
		temp[index] = data[index2];
		index2++;
		index++;
	}
	while (index1 <= middle) {
		temp[index] = data[index1];
		index1++;
		index++;
	}
	
	//cout << "Index " << index << endl;
	for (int i = 0; i < index; i++) {
		data[i + first] = temp[i];
	}
}


void QuickSort(Itemtype data[], int first, int last){
	if (first == last) {
		return;
	}
	else {
		int index = first;
		index = Partition(data, first, last, index);
		QuickSort(data, first, index - 1);
		QuickSort(data, index + 1, last);
	}
}

int Partition(Itemtype data[], int first, int last, int index) {
	Itemtype pivot = data[index];

	first++;
	while(first < last) {
		while(data[first] <= pivot) {
			first++;
		}
		while (data[last] >= pivot && first < last) {
			last--;
		}
		if (first < last) {
			SwapValues(data[first], data[last]);
		}
	}
	last--;
	SwapValues(data[pivot], data[last]);
	return last;
}


void displayData(Itemtype data[], int num)
{
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << data[i] << ' ';
	}
	cout << endl;
}

int getRandomNum() {		//Returns random number between 1 - 100
	return (rand() % 100 + 1);
}

void SwapValues(Itemtype& first, Itemtype& second) {
	Itemtype temp = first;
	first = second;
	second = temp;
}

int FindSmallest(Itemtype data[], int n, int start) {
	int position = start;
	for (int j = start + 1; j < n; j++) {
		if (data[j] < data[position]) {
			position = j;
		}
	}
	return position;
}

void GetRandomData(Itemtype data[], int n) {
	for (int i = 0; i < n; i++) {
		data[i] = getRandomNum();
	}
}

bool VerifyInput(string input, string case1, string case2) {		//Used to ask if user wants to use random numbers
	while (true) {
		if (input == case1) {
			return true;
		}
		if (input == case2) {
			return false;
		}
		cout << "Invalid Input (" << case1 << "/" << case2 << "): ";
		cin >> input;
	}
}

void GetUserData(Itemtype data[] , int n) {
	int count = 0;
	while (count < n) {
		cout << "Enter data: " << endl;
		cin >> data[count++];
	}
}

void CopyArray(Itemtype data1[], Itemtype data2[], int num) {
	for (int i = 0; i < num; i++) {
		data2[i] = data1[i];
	}
}