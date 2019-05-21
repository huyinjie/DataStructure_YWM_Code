// P10 1.19
/*
试编写算法，计算i!×2^i的值并存入数组   
a[0..ARRSIZE-1]的第i-1个分量中 (i=1,2,…,n)。   
假设计算机中允许的整数最大值为MAXINT，则当n>   
ARRSIZE或对某个k(1≤k≤n)使k!×2^k>MAXINT时，应   
按出错处理。注意选择你认为较好的出错处理方法。
*/

#include <iostream>
#include <math.h>

#define MAXINT 65535
#define arrsize 40

using namespace std;

int myFactorial(int i) {
    int result = 1;
    if(i == 0) {
        return 1;
    }
    do {
        result *= i;
        i--;
    } while (i > 1);
    return result;
}

int exp(int i) {
    return myFactorial(i)*pow(2,i);
}

int main() {
    int n,i,j;
    int a[arrsize];
    int temp = 1;
    bool flag = true;

    cout << "Please input n:\n";
    cin >> n;

    if(n > arrsize) {
        flag = false;
    }

    for(i = 0; i < n && flag; i++) {
        temp = exp(i);
        if (temp > MAXINT) {
            flag = false;
            break;
        }
        else {
            a[i] = exp(i);
            cout << a[i] << " ";
        }
    }
    cout << endl;

    if(!flag)
	{
		cout << "Input wrong!" << endl;
	}

    return 0;
}