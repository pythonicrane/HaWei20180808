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
#include <string>
#include <map>
#include <functional>
using namespace std;

vector<string> split(const string& str, const string& delim)
{
	vector<string> vts;
	string::size_type pos1 = 0;
	string::size_type pos2 = str.find(delim, pos1);//从pos1开始搜索delim
	while (string::npos != pos2) {//搜索越界则结束，行末有delim的情况，例如 1,2,3,
		if (pos1 != pos2) {//排除字符串前面出现的delim,例如 ,1,2,3,
			if (str.substr(pos1, pos2 - pos1) != delim) {//排除连续出现的,,
				vts.push_back(str.substr(pos1, pos2 - pos1));
			}
		}
		pos1 = pos2 + delim.size();
		pos2 = str.find(delim, pos1);
	}
	return vts;
}

bool findFun(const string& s2, const map<string, string, greater<string>>& m)
{
	for (auto a : m) {
		if (s2.find(a.first) != string::npos) {
			return true;
		}
	}
	return false;
}

int main()
{
	//输入
	string s1, s2;
	getline(cin, s1);
	cin >> s2;

	map<string, string,greater<string>> m;

	//第一次字符串分割，按';'
	vector<string> sp = split(s1, ";");
	//第二次字符串分割，按' '
	for (auto a : sp) {
		a.append(" ");
		vector<string> tmp = split(a, " ");
		m[tmp.at(2)] = tmp.at(1);

	}
	
	//替换
	string s = s2;
	while (findFun(s2, m)) {
		for (auto a : m) {
			if (s2.find(a.first) != string::npos) {
				s2.replace(s2.find(a.first), a.first.size(), a.second);
				break;
			}
		}
	}


	//输出
	if (s == s2) {
		cout << "none" << endl;
	}
	else {
		//给'*'加' '
		string s3;
		s3.push_back(s2.at(0));
		for (int i = 1; i < s2.size(); ++i) {
			if (s2[i] == '*' && s2[i - 1] != ' ') {
				s3.append(" *");
			}
			else {
				s3.push_back(s2[i]);
			}
		}
		cout << s3 << endl;
	}
	
	system("pause");
}
