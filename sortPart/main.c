#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
//#include <winsock2.h>
//#include <winsock2.h>
/*计数排序：https://www.cnblogs.com/xiaochuan94/p/11198610.html*/
typedef int ElemType;
#define MAX (ElemType)(pow(2,31)-1)
#define MIN (ElemType)(-pow(2,31))
/*声明部分*/
ElemType max(ElemType a, ElemType b){
    return a>b ? a : b;
}
ElemType min(ElemType a, ElemType b){
    return a<=b ? a : b;
}
void CountSort(ElemType *array,ElemType *result, ElemType cnt);//计数 排序

/*定义部分*/
void CountSort(ElemType *array, ElemType *result, ElemType cnt){//在函数中使用sizeof(数组名)计算的是指针的大小！！
    ElemType maxnum =MIN;
    ElemType minnum = MAX;
    for (size_t i=0;i<cnt;i++){
        maxnum = max(maxnum,array[i]);
        minnum = min(minnum,array[i]);
    }
    const ElemType nums = (maxnum - minnum + 1);//计算Count数组长度为：最大值-最小值+1
    ElemType Count[nums];//
    for (size_t i=0;i<nums;i++)Count[i]=0;
    for(size_t i=0;i<cnt;i++){//对Count数组进行赋值操作,并使得Count[0]=0恒成立
        Count[array[i]-minnum]++;
    }
    for (size_t i=0;i<nums-1;i++){//Count数组变形:当前元素+上一元素
        Count[i+1] += Count[i];
    }
    //ElemType result[cnt];//与array数组大小相同的结果数组
    for (size_t i=0;i<cnt;i++){//确认结果数组中的元素
        result[Count[array[i]-minnum]-1] = array[i];
        Count[array[i]-minnum]--;
    }
}


int main()
{
    ElemType nums[] = {5,0,3,4,5,6,-2,0,-1000,1,1111};
    const size_t cnt = sizeof(nums)/sizeof(ElemType);//array数组中的元素个数
    ElemType result[cnt];
    CountSort(nums,result,cnt);
    for (size_t i=0;i<cnt;i++){
        printf("%d  ",result[i]);
    }
    return 0;
}
