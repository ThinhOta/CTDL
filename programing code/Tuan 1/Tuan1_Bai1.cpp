#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int findGCD(int a, int b)
{
    if (a >= b) 
    {
        if (a % b == 0 ) return b;
        else return findGCD(b, a % b);
    }
    else return findGCD(b,a);
}

int findLCM(int a, int b)
{
    return a * b / findGCD(a,b); 
}

int findMax(int* arr, int length)
{
    if (length == 1) return arr[0];
    int maxHead = findMax(arr, length -1);
    if (maxHead > arr[length -1] ) return maxHead;
    else return arr[length-1];
}

int strLen(char* str)     
{ 
    if (str[0] == '\0') return 0;
    return strLen(str+1) +1;
} 

bool isPalindrome(string str) 
{ 
    if (str.length() == 0 || str.length()== 1)
        return true;
    if (str[0] == str[str.length() -1])
        return isPalindrome(str.substr(1,str.length()-2));
    else return false;
}

void printHailstone(int number)
{
    if (number == 1 || number == 0){
        cout << number ;
        return;
    }
    cout << number << " ";
    if (number % 2 == 0){
            return printHailstone(number/2);
        }
    else {
        return printHailstone(number*3+1);
    }
}

int decimalToBinary(int decimal_number) 
{ 
    if (decimal_number / 2 == 0) {
        return decimal_number % 2 ;
    }
    decimal_number = decimalToBinary(decimal_number/2)*10 + decimal_number %2;
    return decimal_number;
} 

void printArray(int n)
{
    if(n == 0) {
        cout << 0;
        return;
    }
    printArray(n-1);
    cout << ", " << n;
}

int myArrayToInt(char *str, int n) 
{   
    if (n == 1)
        return str[0] - 48;
    n = (str[n-1] - 48) + myArrayToInt(str, n-1) *10;
    return n;
}

void printPattern(int n) 
{ 
    if (n <= 0) {
        cout << n;
        return;
    }
    cout << n << " "; 
    printPattern (n -5);
    cout << " " << n;
}

bool checkPattern(char* text, char* pattern)
{
    if(pattern[0] == '\0')
        return true;
    if(text[0] == pattern [0])
        return checkPattern(text + 1, pattern +1);
    return false;
}

bool containsPattern(char* text, char* pattern)
{
    if (text[0] == '\0')
        return false;
    if (text[0] == pattern[0]){
        if(checkPattern(&text[0], pattern) == true)
            return true;
    }
    return containsPattern(text+1, pattern);
}

int countWay(int x, int n){
    int temp = x - n*n;
    if (temp == 0)
        return 1;
    if (temp < 0)
        return 0;
    return countWay(temp, n+1) + countWay(x, n+1);
}

int countWaySumOfSquare(int x)
{
    return countWay(x, 1);
}

int main()
{
    cout << countWaySumOfSquare(100);
    cout << endl;
    cout << "Done!";
    return 1;
}
