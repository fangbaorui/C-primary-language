//����һ������nums��һ��ֵval������Ҫԭ���Ƴ�������ֵ����val��Ԫ��
//�������Ƴ�����³���
//����һ��ʹ��һ�����������NewArr��Ȼ�������nums���治����val��ֵ������NewArr�����У�
//��NewArr������nums�У��ͷ�NewArr
int removeElement(int* nums, int numsSize, int val)
{
	//����һ������NewArr
	int* NewArr = (int*)malloc(sizeof(int) * numsSize);
	//idx�±�����¼nums�����в�����val��ֵ
	int idx = 0;
	for (int i = 0; i < numsSize; i++)
	{
		//����ȣ��Ͱ�nums���������ֵ��NewArr��
		if (nums[i] != val)
		{
			NewArr[idx++] =nums[i];
		}
	}
	//����
	memcpy(nums, NewArr, sizeof(int) * idx);
	//�ͷ�
	free(NewArr);
	return idx;
}

//��������Ԫ�ظ��ǣ�����ͬ��Ԫ�ظ��ǵ�
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



//ɾ�����������ظ���������򣩣�����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�
//ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
int removeDuplicates(int* nums, int numsSize)
{
	//���ֻ��0������1��Ԫ�أ�ֱ�ӷ���
	if (numsSize <= 1)
		return numsSize;
	int i = 0, j = 1, idx = 0;
	while (j < numsSize)
	{
		nums[idx] = nums[i];
		//�ж�Ԫ���Ƿ��ظ�
		if (nums[i] == nums[j])
		{
			//�ҵ��ظ�Ԫ�ؽ�����λ��
			while (j < numsSize && nums[i] == nums[j])
			{
				j++;
			}
			i = j;
			j++;
		}
		//������ظ�
		else
		{
			++i;
			++j;
		}
	}
	//��j=numsSizeʱ��������һ������ֻ����һ�Σ��������һ������
	if (i < numsSize)
	{
		nums[idx] = nums[i];
	}
	return idx;
}



//�ϲ������������飺��������������������nums1��nums2�����㽫nums2�ϲ���nums1�У�
//��nums1��Ϊһ����������
//����һ������һ���µĿռ�nums3��ÿ��nums3�д��һ����֮ǰ����nums1��nums2�����ֵ��ȣ�
//��Сֵ���Ž���������++��
//��nums1��nums2��ĳ���������󣬽���һ����������ʣ�����������nums3�У�
//��nums3������nums1�У��ͷ�nums3
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	//�����¿ռ�nums3
	int* nums3 = (int*)malloc(sizeof(int) * (m + n));
	int i = 0, j = 0, idx = 0;

	//ͬʱ��������Сֵ����nums3
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

	//ֱ�ӿ���ʣ��Ԫ��
	if (i < m)
	{
		memcpy(nums3 + idx, nums1 + i, sizeof(int) * (nums1Size - i));
	}
	if (j < n)
	{
		memcpy(nums3 + idx, nums2 + j, sizeof(int) * (nums2Size - j));
	}

	//��nums3������nums1�У��ͷ�nums3
	memcpy(nums1, nums3, sizeof(int) * (m + n));
	free(nums3);
}

//����������nums1��Чλ�õ����һ��ֵ��nums2�����һ��ֵ�Ƚϣ����ϴ�ֵ����nums1��������һ��λ��
//nums--��nums2--�������Ƚϵ����ڶ���ֵ�Ĵ�С�����ϴ�ֵ����nums1���鵹���ڶ���λ�ã�
//���nums2�����������ˣ��ͽ����ˣ�
//���nums1�������ˣ���nums2��ʣ��Ԫ�ؿ�����nums1��
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m-1, j = n-1, idx = m+n-1;
	//�Ӻ���ǰ����
	//ͬʱ�������ϴ�ֵ����nums1���λ��
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
	//���nums2�л���Ԫ��û�д��룬ֱ�ӿ�����nums1��
	if (j >= 0)
	{
		memcpy(nums1, nums2, sizeof(int) * (j + 1));
	}
}


//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k�ǷǸ���
//[1,2,3,4,5,6,7]��k=3
//[5,6,7,1,2,3,4]
//����һ��������ת

//1. 0��n-k-1   [1,2,3,4,5,6,7]
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

//��������ÿ�ν����һ��ֵ��tmp���棬Ȼ������Ԫ����������ƶ�
//��tmp���뵽��һ��Ԫ�ص�λ��
//ѭ��k��
void rotate(int* nums, int numsSize, int k)
{
	//��ģ������ת�����������鳤�ȣ���ģ
	k %= numsSize;

	//�ظ�k��ͷ��
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