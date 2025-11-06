#include <stdio.h>
 
int binary_search(int arr[], int k, int sz)//形参
{
  int left = 0; //左下标
  int right = sz - 1; //右下标
 
  //使用while循环
  while (left <= right)
  {
    //生成中间值下标 mid ：
    int mid = left + (right - left) / 2;
 
    //二分查找:
    if (arr[mid] < k)//中间值 小于 要找的值
    {
      left = mid + 1;
      //舍弃中间值和中间值左边的所有数，
      //调整 左下标left ：left = mid + 1。
    }
    else if (arr[mid] > k)//中间值 大于 要找的值
    {
      right = mid - 1;
      //舍弃中间值和中间值右边的所有数，
      //调整 右下标right ：right = mid - 1。
    }
    else if (arr[mid] == k)//中间值 等于 要找的值
    {
      return mid;
      //返回中间值下标mid。
    }
  } 
  if (left > right)
  {
    return -1; //找不到则返回-1
  }
}
 
int main()
{
  int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; //定义有序数组
  int k = 7; //设置要查找的值
  int sz = sizeof(arr) / sizeof(arr[0]); //求出数组元素个数
  // 整个数组大小 / 单个数组元素大小 = 数组元素个数
 
  //调用自定义函数：
  int ret = binary_search(arr, k, sz); //ret接收返回的下标
 
  //判断自定义函数的返回值，打印相应的情况：
  if (ret == -1) //未找到，返回-1
  {
    printf("找不到\n");
  }
  else
  {
    printf("找到了，下标是：%d\n", ret);
  }
 
  return 0;
}
