

#include <iostream>
#include <cmath>
using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int factorial(int n) {
    if (n == 1)
        return 1;
    else if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int sumOfDigits(int x) {
    if (x == 0)
        return 0;
    else
        return x + sumOfDigits(x - 1);
}

int findMin(int a[], int size) {
    int min = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int DecToBin(int dec) {
    if (dec == 0)
        return 0;
    else
        return dec % 2 + 10 * DecToBin(dec / 2);
}

double seriesSum(int n) {
    if (n == 0)
        return 1;
    else
        return 1.0 / pow(2, n) + seriesSum(n - 1);
}

int main() {

    cout << "Fibonacci: " << fib(10) << endl;
    cout << "Factorial: " << factorial(6) << endl;
    cout << "sum of the digits: " << sumOfDigits(10) << endl;

    int a[10] = {10, 20, 30, 40, 5, 6, 7, 8, 90, 10};
    cout << "Minimum number: " << findMin(a, 10) << endl;
    cout << "Binary is: " << DecToBin(15) << endl;
    cout << "Sum of the series: " << seriesSum(2) << endl;

    return 0;
}
