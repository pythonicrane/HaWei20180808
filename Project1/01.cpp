/*
[���|100��] ��Сд��ĸת��
ʱ�����ƣ�C/C++ 5�룬�������� 10��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
����������ַ����������е�Сд��ĸ��Ϊ��д����д��ĸ��ΪСд�������ַ����ô���
��������:
�����ַ�����abcd12#%XYZ
�������:
����ַ�����ABCD12#%xyz
ʾ��1
����
����
abcd12#%XYZ
���
����
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