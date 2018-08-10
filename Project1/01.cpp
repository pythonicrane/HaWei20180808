/*
[编程|100分] 大小写字母转化
时间限制：C/C++ 5秒，其他语言 10秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
输入任意个字符串，将其中的小写字母变为大写，大写字母变为小写，其他字符不用处理；
输入描述:
任意字符串：abcd12#%XYZ
输出描述:
输出字符串：ABCD12#%xyz
示例1
输入
复制
abcd12#%XYZ
输出
复制
ABCD12#%xyz
*/

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


int main() {
	
	
	char ch;
	while ((ch = getchar())!= EOF) {
		if ((ch >= 'a') && (ch <= 'z')) {
			putchar(ch - ('a' - 'A'));
		}
		else if ((ch >= 'A') && (ch <= 'Z')) {
			putchar(ch + ('a' - 'A'));
		}
		else {
			putchar(ch);
		}
	}
	return 0;
}