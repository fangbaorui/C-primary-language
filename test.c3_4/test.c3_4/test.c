#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int i, j, a[2][3];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			a[j][i] = j * 3 + i + 1;
//			printf("%d\n", a[j][i]);
//		}
//	}
//	return 0;                                    
//}

//#include<stdio.h>
//int main()
//{
//	int i, j, a[2][3];
//	for (i = 1; i <= 6; i++)
//	{
//		a[i][i] = i;
//		printf("%d\n", a[i][i]);
//	}
//	return 0;
//}


//实现函数 ToLowerCase() ，该函数接收一个字符串参数 str 
//并将该字符串中的大写字母转换成小写字母，之后返回新的字符串
//char* toLowerCase(char* str) {
//    char* start = str;
//    while (*str != 0)
//    {
//        if (*str >= 'A' && *str <= 'Z')
//            *str += 32;
//        str++;
//    }
//    return start;
//}



//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//void reverse(int* nums, int start, int end)
//{
//    while (start < end)
//    {
//        nums[start] = nums[start] ^ nums[end];
//        nums[end] = nums[start] ^ nums[end];
//        nums[start] = nums[start] ^ nums[end];
//        ++start;
//        --end;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//}


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//int removeElement(int* nums, int numsSize, int val) {
//	int idx = 0;
//	int i = 0;
//	for (; i < numsSize; ++i)
//	{
//		//将不相等的元素全部从前往后放入数组中，并且用idx记录数组长度
//		if (nums[i] != val)
//		{
//			nums[idx++] = nums[i];
//		}
//	}
//	return idx;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0, a = 0;
//	while (i < 20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0) break;
//			else i--;
//		} 
//		i+= 11; a += i;
//	}
//	printf("%d\n", a);
//	return 0;
//}




//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由
//第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//bool canConstruct(char* ransomNote, char* magazine) {
//    int count[26] = { 0 };//初始化为全零
//    int i;
//    char ch;
//    for (i = 0; (ch = magazine[i]) != '\0'; i++)
//        count[ch - 'a']++;
//    for (i = 0; (ch = ransomNote[i]) != '\0'; i++) {
//        if (count[ch - 'a'] == 0)
//            return false;
//        else count[ch - 'a']--;
//    }
//    return true;
//}



//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
//bool isPalindrome(int x) {
//    if (x < 0)
//        return false;
//    int temp = x;
//    long n = 0;
//    while (temp)
//    {
//        n = n * 10 + temp % 10;
//        temp /= 10;
//    }
//    return n == x ? true : false;
//}



#include<stdio.h>

int main()
{
	int n = 2;
	int a = 0;
	n += n-= n * n;

	printf("%d\n", n);
	return 0;
}
