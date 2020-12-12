////����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ��������
////���а취��O(n)ʱ���������
//class Solution {
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        int idx = 0;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            //ͬһ�����������Ϊ0
//            idx ^= i;
//            //i��1��nums.size��nums��0��nums.size������ȱһ��������Ҫ�����һ��nums.size
//            idx ^= nums[i - 1];
//        }
//        return idx;
//    }
//};



//һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
//Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int i = 0;
        int ret = 0;
        int num1 = 0;
        int num2 = 0;
        for (i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        for (i = 0; i < 32; i++)
        {
            if ((ret << i) & 1 == 1)
                break;
        }
        int pos = i;
        for (i = 0; i < nums.size(); i++)
        {
            if ((nums[i] << pos) & 1 == 1)
            {
                num1 ^= nums[i];
            }
        }
        num2 = num1 ^ ret;
        return nums[2] = { num1,num2 };

    }
};



public int[] singleNumbers(int[] nums) {
    //xor��������nums������
    intxor = 0;

    // �������� ���浽xor
    // e.g. [2,4,2,3,3,6] ���ͣ�(2^2)^(3^3)^(4^6)=2=010
    for (int num : nums) xor ^= num;

    //����maskΪ1���������Ϊ0001
    // mask��һ������������������ֻ��һλ��1������λȫ��0������000010��
    // ��ʾ�����õ����ڶ�λ��Ϊ�����׼�������ڶ�λ��0�����ֵַ�һ�飬�����ڶ�λ��1�ķֵ���һ��
    int mask = 1;

    // & operatorֻ��1&1ʱ����1 �������0
    // �������e.g. 4��6�Ķ������ǲ�ͬ�� ���Ǵ��ҵ����ҵ���һ����ͬ��λ�Ϳ��Է��� 4=0100 6=0110
    // ����e.g. 010 & 001 = 000 = 0�� mask=010
    // 010 & 010 != 0 ����mask=010
    // ֮��Ϳ�����mask����������������������ֿ�
    while ((xor &mask) == 0) {
        mask <<= 1;
    }

    //����ֻ����һ�ε�����
    int a = 0, b = 0;

    for (int num : nums) {
        //����&�Ƿ�Ϊ0���ֽ��������ַ��������ֱ�������
        if ((num & mask) == 0) a ^= num;
        else {
            b ^= num;
        }
    }
    return new int[] {a, b};
}