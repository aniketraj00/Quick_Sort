#include <iostream>
#include <ctime>

void quickSort(int* arr, int leftIdx, int rightIdx);
int getPivot(int* arr, int start, int end);
void swap(int* arr, int idx1, int idx2);
void printArr(int* arr, int length);
int randInt(int upperBound);
void shuffleArr(int* arr, int length);

static int temp = 0;

int main() {
	int size = 100;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = (i+1);
	}
	shuffleArr(arr, size);

	printArr(arr, size);
	quickSort(arr, 0, size - 1);
	printArr(arr, size);
	
	delete[] arr;
	return 0;
}

void quickSort(int* arr, int leftIdx, int rightIdx) {
	if (leftIdx < rightIdx) {
		int pivot = getPivot(arr, leftIdx, rightIdx);
		quickSort(arr, leftIdx, pivot - 1);
		quickSort(arr, pivot + 1, rightIdx);
	}
}

int getPivot(int* arr, int start, int end) {
	int pivotIdx{ start };
	int curIdx{ start };
	for (int i = start + 1; i <= end; i++) {
		std::cout << "\nCount = " << ++temp;
		if (arr[curIdx] > arr[i]) {
			swap(arr, i, ++pivotIdx);
		}
	}
	swap(arr, curIdx, pivotIdx);
	return pivotIdx;
}

void swap(int* arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void printArr(int* arr, int length) {
	std::cout << "\n[";
	for (int i = 0; i < length; i++) {
		i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
	}
	std::cout << "]\n";
}

int randInt(int upperBound) {
	int random = std::rand() % upperBound + 1;
	return random;
}

void shuffleArr(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		swap(arr, i, randInt(length - 1));
	}
}
