#include<stdio.h>
#include<stdlib.h>
//每一趟排序
int sort(int* arr, int left, int right) {
	int i = left;
	int j = right;
	int temp = arr[left];
	while (i != j) {
		while (temp <= arr[j] && i < j)//j左移
			j--;
		while (temp >= arr[i] && i < j)//i向右移
			i++;
		if (i < j) {//i与j都停止移动的时候，交换数字
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	//此时i与j相遇，进行数字交换
	arr[left] = arr[i];
	arr[i] = temp;
	
	return i;//返回这个交汇点
}

// 包括left right
void quick_sort(int* arr, int left, int right) {
	int* stack = (int*)malloc(sizeof(int) * right);//创建一个数组栈
	for (int i = 0; i < right; i++)
		stack[i] = -1;//初始化为-1
	int count = 0;//当前栈数据的个数
	if (left < right) {//入栈
		stack[count++] = left;
		stack[count++] = right;
	}
	while (count) {//当栈为非空的时候
		//出栈操作
		int r_pop = stack[count-1];
		int l_pop = stack[count-2];
		stack[count - 1] = stack[count - 2] = -1;//出栈后，清空已出栈数据，设置为-1
		count -= 2;
		int i = sort(arr, l_pop, r_pop);
		//如果这个交汇点前面数据的下标比当前最左边的数据下标要大的话，就入栈
		if (l_pop < i - 1) {
			stack[count++] = l_pop;
			stack[count++] = i - 1;
		}
		//如果这个交汇点后面一个数据的下标比当前最右边数据的下标要小的话，入栈
		if (r_pop > i + 1) {
			stack[count++] = i + 1;
			stack[count++] = r_pop;
		}
	}
	//释放空间
	free(stack);
	stack = NULL;
}
 
 
int main() {
	int array[8] = { 25,24,6,65,11,43,22,51 };
	printf("排序前:");
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf("%d ", array[i]);
	}
	printf("\n排序后：");
	quick_sort(array, 0, sizeof(array) / sizeof(int) - 1);
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf("%d ", array[i]);
	}
}