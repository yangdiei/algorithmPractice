#include <iostream>

int binSearch(int a[], int left, int right, int n) {

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == n)
			return mid;
		else if (n < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return 0;
}


//int main() {
//	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
//	int n = sizeof(A) / sizeof(int);
//
//	printf("%d", binSearch(A, 0, n - 1, 3));
//	return 0;
//}