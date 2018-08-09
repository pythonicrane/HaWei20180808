/*
[编程|300分] 获取typedef的最终类型
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
C++中的typedef好处很多，可以让标准化自己DIY的类型，为便于理解typedef能干啥，本题考察各种typedef后，某个自定义类型的最终形态是啥。
输入为两部分，共两行：
第一行是一堆typedef定义，标准C++语句，以分号结束，这里不用考虑struct/union这类，只需要考虑基本类型和指针。
第二行是制定某个自定义type
输出为该自定义type的最终形态
如输入：
typedef int INT; typedef INT** INTP;
INTP
则输出：int * *
注意，如果有指针类型，则指针表达的*和前面的类型中间间隔一个空格，和编译器的输出保持一致；另外，如果第一行输入的语句是编译不过的，或者第二行选择的type在第一行中没有定义，则输出none
输入描述:
typedef的一堆自定义类型，并制定最终需要看的类型名
输出描述:
该类型名的完整名字，和编译器输出保持一致
示例1
输入
复制
typedef int INT; typedef INT** INTP;
INTP
输出
复制
int * *
备注:
如果有指针类型，则指针表达的*和前面的类型中间间隔一个空格，如果有多个*，之间都要用空格隔开。
*/

#include <iostream>
#include <vector>
using namespace std;


int dpBagFun(const vector<int>& vtWeight, const vector<int>& vtValue, int num, int vulum)
{
	vector<vector<int>> dpBag(num, vector<int>(vulum + 1));
	for (int i = 0; i < num; ++i) {
		dpBag[i][0] = 0;
	}
	for (int i = 0; i < vulum + 1; ++i) {
		if (vtWeight.at(0)>i) {
			dpBag[0][i] = 0;
		}
		else {
			dpBag[0][i] = vtValue.at(0);
		}
	}

	for (int i = 1; i < num; ++i) {
		for (int j = 1; j <= vulum; ++j) {
			if (j < vtWeight.at(i)) {
				dpBag[i][j] = dpBag[i - 1][j];
			}
			else {
				int A = dpBag[i - 1][j - vtWeight.at(i)] + vtValue.at(i);
				int B = dpBag[i - 1][j];
				dpBag[i][j] = (A > B) ? A : B;
			}
		}
	}
	return dpBag[num-1][vulum];
}


int main()
{
	int num = 0;
	int vulum = 0;
	cin >> num >> vulum;

	vector<int> vtWeight;
	vector<int> vtValue;
	int tmpi;
	for (int i = 0; i < num; ++i) {
		cin >> tmpi;
		vtWeight.push_back(tmpi);
	}
	for (int i = 0; i < num; ++i) {
		cin >> tmpi;
		vtValue.push_back(tmpi);
	}

	cout << dpBagFun(vtWeight, vtValue, num, vulum) << endl;

	system("pause");
	getchar();
}

/*
5 20
2 3 4 5 9
3 4 5 8 10
*/