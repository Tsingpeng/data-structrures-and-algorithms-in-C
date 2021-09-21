#include <stdbool.h>
#include "utils.h"

static bool isPrime(size_t X){//判断该数是否为质数
    for (size_t i=3;i<X;i+=2){
        size_t q = X/i;
        if (q*i == X) return false;
        if (q>i) return true;
    }
    return true;
}

size_t nextPrime(size_t X){//X的下一个质数
    if (X<=2) return 2;//质数2是个例外
    if (!(X&1)) X++;//质数必为奇数
    while (!(isPrime(X))){//如果不为质数，则判断下个质数
        X += 2;
    }
    return X;
}