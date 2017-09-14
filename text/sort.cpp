#include <iostream>
using namespace std;

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


//�������򻮷ֻ�׼����
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

//��������
// ���ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ ��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)       
// �ȶ��� ---------- ���ȶ�
void quicksort(int a[], int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot_index = partition(a, left, right);
	quicksort(a, left, pivot_index - 1);
	quicksort(a, pivot_index + 1, right);
}

//�鲢����ݹ�ʵ��
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(n)
// �ȶ��� ------------ �ȶ�
void merge(int a[], int left, int mid, int right){
	int len = right - left + 1;
	int *temp = new int[len];   //�����ռ�
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
		printf("������������");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", A[i]);
		}
		printf("\n");

		return 0;
}