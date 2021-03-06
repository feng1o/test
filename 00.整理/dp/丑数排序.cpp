

#include "stdafx.h"

// ====================算法1的代码====================

bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;
 
    return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
    if(index <= 0)
        return 0;
 
    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;
 
        if(IsUgly(number))
        {
            ++uglyFound;
        }
    }
 
    return number;
}

// ====================算法2的代码====================

int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
    if(index <= 0)
        return 0;
 
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
 
    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;
 
    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;
 
        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply5;
 
        ++nextUglyIndex;
    }
 
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}
 
int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
 
    return min;
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test(1, 1);

    Test(2, 2);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}

//面试经典上的一个思路，，，，突击节点
int findKth2(int k) {
	// write code here
	// write code here
	int num = 3;
	while (num && k){
		int temp = num;
		while (temp % 3 == 0)
			temp /= 3;
		while (temp % 5 == 0)
			temp /= 5;
		while (temp % 7 == 0)
			temp /= 7;
		if (1 == temp)
			k--;
		num++;
	}
	return --num;
}