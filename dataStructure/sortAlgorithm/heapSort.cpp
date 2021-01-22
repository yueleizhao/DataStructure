/*
 *堆排序是指利用堆这种数据结构所设计的一种选择排序算法。
 * 堆是一种近似完全二叉树的结构（通常堆是通过一维数组来实现的），
 * 并满足性质：以最大堆（也叫大根堆、大顶堆）为例，其中父结点的值总是大于它的孩子节点。

我们可以很容易的定义堆排序的过程：

由输入的无序数组构造一个最大堆，作为初始的无序区
把堆顶元素（最大值）和堆尾元素互换
把堆（无序区）的尺寸缩小1，并调用heapify(A, 0)从新的堆顶元素开始进行堆调整
重复步骤2，直到堆的尺寸为1
 */

 /*
  * 构造初始大(小)根堆，自下而上，从右到左调整为初始堆
  * 输出:输出堆顶，用最后一个结点代替堆顶，然后自上而下再调整。
  */

#include <iostream>

 // 分类 -------------- 内部比较排序
 // 数据结构 ---------- 数组
 // 最差时间复杂度 ---- O(nlogn)
 // 最优时间复杂度 ---- O(nlogn)
 // 平均时间复杂度 ---- O(nlogn)
 // 所需辅助空间 ------ O(1)
 // 稳定性 ------------ 不稳定


void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
	int left_child = 2 * i + 1;         // 左孩子索引
	int right_child = 2 * i + 2;        // 右孩子索引
	int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
		Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
	}
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);    // 建立一个最大堆
	while (heap_size > 1)  //堆（无序区）元素个数大于1，未完成排序
	{
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		Swap(A, 0, --heap_size);
		Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
	}
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大堆排序
	int n = sizeof(A) / sizeof(int);
	HeapSort(A, n);
	printf("堆排序结果：\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}


/*
 *
 * 堆排序是不稳定的排序算法，不稳定发生在堆顶元素与A[i]交换的时刻。

比如序列：{ 9, 5, 7, 5 }，堆顶元素是9，堆排序下一步将9和第二个5进行交换，
得到序列 { 5, 5, 7, 9 }，再进行堆调整得到{ 7, 5, 5, 9 }，
重复之前的操作最后得到{ 5, 5, 7, 9 }从而改变了两个5的相对次序。
*/

