#include <iostream>
using namespace std;

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


//快速排序划分基准函数
int partition(int a[], int left, int right) {
	int piovt = a[right];
	int tail = left - 1;
	for (int i = left; i < right; i++) {
		if (a[i] < piovt) {
			Swap(a, i, ++tail);
		}
	}
	Swap(a, tail + 1, right);
	return tail + 1;
}

//快速排序
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定
void quicksort(int a[], int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot_index = partition(a, left, right);
	quicksort(a, left, pivot_index - 1);
	quicksort(a, pivot_index + 1, right);
}

//归并排序递归实现
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定
void merge(int a[], int left, int mid, int right){
	int len = right - left + 1;
	int *temp = new int[len];   //辅助空间
	int index = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid&&j <= right) {
		temp[index++] = a[i] <= a[j] ? a[i++] : a[j++];
	}
	while (i <= mid) {
		temp[index++] = a[i++];
	}
	while (j <= right) {
		temp[index++] = a[j++];
	}
	for (int k = 0; k < len; k++) {
		a[left++] = temp[k];
	}
}

void mergeSort(int a[], int left, int right) {
	if (left == right)
		return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid, right);
}

int main() {
		int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 }; 
		int n = sizeof(A) / sizeof(int);
		mergeSort(A, 0, n - 1);
		printf("快速排序结果：");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", A[i]);
		}
		printf("\n");

		return 0;
}