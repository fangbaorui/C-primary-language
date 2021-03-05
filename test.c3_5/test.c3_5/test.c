#define _CRT_SECURE_NO_WARNINGS

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
//返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。
int searchInsert(int* nums, int numsSize, int target) {
    /* 使用二分查找来搜索target */
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target > nums[mid]) {
            left = mid + 1;
        }
        else if (target < nums[mid]) {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }
    return left;
}



//给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。
//如果不存在最后一个单词，请返回 0 。
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int cnt = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (s[i] != ' ')
            cnt++;
        if (s[i] == ' ' && 0 != cnt)
            break;
    }

    return cnt;
}




//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，
//这样它就有足够的空间保存来自 nums2 的元素。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1, j = n - 1, idx = m + n - 1;
    //从后向前插入
    //同时遍历，较大值存入nums1最后位置
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[idx--] = nums1[i--];
        }
        else
        {
            nums1[idx--] = nums2[j--];
        }
    }
    //如果nums2中还有元素没有存入，直接拷贝到nums1中
    if (j >= 0)
    {
        memcpy(nums1, nums2, sizeof(int) * (j + 1));
    }
}



//给定一个整数数组，判断是否存在重复元素。
//如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize) {
    /* 特判 */
    if (nums == NULL || numsSize <= 0) {
        return false;
    }

    /* 排序 */
    qsort(nums, numsSize, sizeof(int), cmp);
    /* 遍历整个数组，查找相邻元素是否相等 */
    for (int i = 0; i < numsSize - 1; ++i) {
        /* 如果不相等，i 递增，继续查找，直到遍历整个数组 */
        if (nums[i] != nums[i + 1]) {
            continue;
        }
        return true;
    }
    return false;
}



//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，
//而字符可能被输入 1 次或多次。你将会检查键盘输入的字符 typed。
//如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
bool isLongPressedName(char* name, char* typed) {
    int n = strlen(name), m = strlen(typed);
    int i = 0, j = 0;
    while (j < m) {
        if (i < n && name[i] == typed[j]) {
            i++;
            j++;
        }
        else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        }
        else {
            return false;
        }
    }
    return i == n;
}