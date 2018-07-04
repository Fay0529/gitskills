// 链接：https://www.nowcoder.com/questionTerminal/17a30153e092493e8b4d13f321343927?pos=111&orderByHotValue=1
// 来源：牛客网

//    Among grandfather's papers a bill was found.     72 turkeys $_679_     The first and the last digits of the number that obviously represented the total price of those turkeys are replaced here by blanks (denoted _), for they are faded and are illegible. What are the two faded digits and what was the price of one turkey?     We want to write a program that solves a general version of the above problem.     N turkeys $_XYZ_     The total number of turkeys, N, is between 1 and 99, including both. The total price originally consisted of five digits, but we can see only the three digits in the middle. We assume that the first digit is nonzero, that the price of one turkeys is an integer number of dollars, and that all the turkeys cost the same price.     Given N, X, Y, and Z, write a program that guesses the two faded digits and the original price. In case that there is more than one candidate for the original price, the output should be the most expensive one. That is, the program is to report the two faded digits and the maximum price per turkey for the turkeys. 
// 输入描述:
//     The first line of the input file contains an integer N (0<N<100), which represents the number of turkeys. In the following line, there are the three decimal digits X, Y, and Z., separated by a space, of the original price $_XYZ_.


// 输出描述:
//     For each case, output the two faded digits and the maximum price per turkey for the turkeys.
// 示例1
// 输入
// 72
// 6 7 9
// 5
// 2 3 7
// 78
// 0 0 5
// 输出
// 3 2 511
// 9 5 18475
// 0

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int digits[5];
int  getNum() {
	int ret = 0;
	int c = 1;
	for (int i = 4; i >= 0; i--) {
		ret += digits[i]*c;
		c *= 10;
	}
	return ret;
}
int main()
{	
	
	while (cin >> n) {
		
		cin >> digits[1] >> digits[2] >> digits[3];
		int flag = true;
		for (int i = 9; i > 0&&flag; i--) {
			for (int j = 9; j >= 0&&flag; j--) {
				digits[0] = i;
				digits[4] = j;
				int num = getNum();
				if (num%n == 0)
				{
					cout << i << " " << j << " " << num / n<<endl;
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			cout << 0 << endl;
		}
	}
    return 0;
}
