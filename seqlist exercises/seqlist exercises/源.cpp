////数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。
////你有办法在O(n)时间内完成吗？
//class Solution {
//public:
//    int missingNumber(vector<int>& nums)
//    {
//        int idx = 0;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            //同一个数异或两次为0
//            idx ^= i;
//            //i从1到nums.size，nums从0到nums.size，其中缺一个数，需要在异或一下nums.size
//            idx ^= nums[i - 1];
//        }
//        return idx;
//    }
//};



//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
//要求时间复杂度是O(n)，空间复杂度是O(1)。
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
    //xor用来计算nums的异或和
    intxor = 0;

    // 计算异或和 并存到xor
    // e.g. [2,4,2,3,3,6] 异或和：(2^2)^(3^3)^(4^6)=2=010
    for (int num : nums) xor ^= num;

    //设置mask为1，则二进制为0001
    // mask是一个二进制数，且其中只有一位是1，其他位全是0，比如000010，
    // 表示我们用倒数第二位作为分组标准，倒数第二位是0的数字分到一组，倒数第二位是1的分到另一组
    int mask = 1;

    // & operator只有1&1时等于1 其余等于0
    // 用上面的e.g. 4和6的二进制是不同的 我们从右到左找到第一个不同的位就可以分组 4=0100 6=0110
    // 根据e.g. 010 & 001 = 000 = 0则 mask=010
    // 010 & 010 != 0 所以mask=010
    // 之后就可以用mask来将数组里的两个数分区分开
    while ((xor &mask) == 0) {
        mask <<= 1;
    }

    //两个只出现一次的数字
    int a = 0, b = 0;

    for (int num : nums) {
        //根据&是否为0区分将两个数字分区，并分别求异或和
        if ((num & mask) == 0) a ^= num;
        else {
            b ^= num;
        }
    }
    return new int[] {a, b};
}