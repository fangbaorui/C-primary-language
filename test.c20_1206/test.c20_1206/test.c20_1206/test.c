//给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素
//并返回移除后的新长度
//方法一：使用一个额外的数组NewArr，然后把数组nums里面不等于val的值拷贝到NewArr数组中，
//将NewArr拷贝到nums中，释放NewArr
int removeElement(int* nums, int numsSize, int val)
{
	//开辟一个数组NewArr
	int* NewArr = (int*)malloc(sizeof(int) * numsSize);
	//idx下标来记录nums数组中不等于val的值
	int idx = 0;
	for (int i = 0; i < numsSize; i++)
	{
		//不相等，就把nums里面的数赋值给NewArr中
		if (nums[i] != val)
		{
			NewArr[idx++] =nums[i];
		}
	}
	//拷贝
	memcpy(nums, NewArr, sizeof(int) * idx);
	//释放
	free(NewArr);
	return idx;
}

//方法二：元素覆盖，把相同的元素覆盖掉
int removeElement(int* nums, int numsSize, int val)
{
	int idx = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[idx++] = nums[i];
		}
	}
	return idx;
}



//删除排序数组重复项（数组有序），你需要在原地删除重复出现的元素，
//使得每个元素只出现一次，返回移除后数组的新长度。
int removeDuplicates(int* nums, int numsSize)
{
	//如果只有0个或者1个元素，直接返回
	if (numsSize <= 1)
		return numsSize;
	int i = 0, j = 1, idx = 0;
	while (j < numsSize)
	{
		nums[idx] = nums[i];
		//判断元素是否重复
		if (nums[i] == nums[j])
		{
			//找到重复元素结束的位置
			while (j < numsSize && nums[i] == nums[j])
			{
				j++;
			}
			i = j;
			j++;
		}
		//如果不重复
		else
		{
			++i;
			++j;
		}
	}
	//当j=numsSize时，如果最后一个数据只出现一次，保存最后一个数据
	if (i < numsSize)
	{
		nums[idx] = nums[i];
	}
	return idx;
}



//合并两个有序数组：给你两个有序整数数组nums1和nums2，请你将nums2合并到nums1中，
//是nums1成为一个有序数组
//方法一：开辟一个新的空间nums3，每在nums3中存放一个数之前，将nums1和nums2里面的值相比，
//较小值则存放进来，数组++。
//当nums1和nums2中某个数组存完后，将另一个数组里面剩余的数拷贝到nums3中，
//将nums3拷贝到nums1中，释放nums3
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	//开辟新空间nums3
	int* nums3 = (int*)malloc(sizeof(int) * (m + n));
	int i = 0, j = 0, idx = 0;

	//同时遍历，较小值存入nums3
	while (i < m && j < n)
	{
		if (nums1[i] <= nums2[j])
		{
			nums3[idx++] = nums1[i++];
		}
		else
		{
			nums3[idx++] = nums2[j++];
		}
	}

	//直接拷贝剩余元素
	if (i < m)
	{
		memcpy(nums3 + idx, nums1 + i, sizeof(int) * (nums1Size - i));
	}
	if (j < n)
	{
		memcpy(nums3 + idx, nums2 + j, sizeof(int) * (nums2Size - j));
	}

	//将nums3拷贝到nums1中，释放nums3
	memcpy(nums1, nums3, sizeof(int) * (m + n));
	free(nums3);
}

//方法二：将nums1有效位置的最后一个值和nums2中最后一个值比较，将较大值放在nums1数组的最后一个位置
//nums--，nums2--，继续比较倒数第二个值的大小，将较大值放在nums1数组倒数第二个位置，
//如果nums2数组先用完了，就结束了，
//如果nums1先用完了，将nums2中剩余元素拷贝到nums1中
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m-1, j = n-1, idx = m+n-1;
	//从后向前插入
	//同时遍历，较大值存入nums1最后位置
	while (i >= 0 && j >= 0  )
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


//给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数
//[1,2,3,4,5,6,7]和k=3
//[5,6,7,1,2,3,4]
//方法一：三次逆转

//1. 0，n-k-1   [1,2,3,4,5,6,7]
//2. n-k,n-1    [4,3,2,1,5,6,7]
//3. 0,n-1      [4,3,2,1,7,6,5]

void reverse(int* nums, int start, int end)
{
	while (start < end)
	{
		nums[start] = nums[start] ^ nums[end];
		nums[end] = nums[start] ^ nums[end];
		nums[start] = nums[start] ^ nums[end];
		++start;
		--end;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k,numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}

//方法二：每次将最后一个值用tmp保存，然后数组元素依次向后移动
//将tmp插入到第一个元素的位置
//循环k次
void rotate(int* nums, int numsSize, int k)
{
	//求模，当旋转次数大于数组长度，求模
	k %= numsSize;

	//重复k次头插
	while (k > 0)
	{
		int i = numsSize - 1;
		int tmp = 0;
		tmp = nums[i];
		for (; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tmp;
		k--;
	}	
}