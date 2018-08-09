/*
[编程|200分] 小偷偷东西问题
时间限制：C/C++ 4秒，其他语言 8秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小偷来到了一个神秘的王宫，突然眼前一亮，发现5个宝贝，每个宝贝的价值都不一样，且重量也不一样，但是小偷的背包携带重量
有限，所以他不得不在宝贝中做出选择，才能使偷到的财富最大，请你帮助小偷计算一下。
输入描述:
宝贝价值：6,3,5,4,6
宝贝重量：2,2,6,5,4
小偷背包容量：10
输出描述:
偷到宝贝的总价值：15
示例1
输入
6,3,5,4,6
2,2,6,5,4
10
输出
15
*/


#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<string> split(const string& str, const string& delim)
{
	vector<string> vts;
	string::size_type pos1 = 0;
	string::size_type pos2 = str.find(delim, pos1);//从pos1开始搜索delim
	while (string::npos != pos2) {//搜索越界则结束，行末没有delim的情况，例如 1,2,3
		vts.push_back(str.substr(pos1, pos2 - pos1));
		pos1 = pos2 + delim.size();
		pos2 = str.find(delim, pos1);
	}
	vts.push_back(str.substr(pos1, pos2 - pos1));
	return vts;
}

/*01背包*/
int dpBagFun(const vector<int>& vtWeight, const vector<int>& vtValue, int num, int volum)
{
	vector<vector<int>> dpBag(num, vector<int>(volum + 1));
	for (int i = 0; i < num; ++i) {
		dpBag[i][0] = 0;
	}
	for (int i = 0; i < volum + 1; ++i) {
		if (vtWeight.at(0)>i) {
			dpBag[0][i] = 0;
		}
		else {
			dpBag[0][i] = vtValue.at(0);
		}
	}

	for (int i = 1; i < num; ++i) {
		for (int j = 1; j <= volum; ++j) {
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
	return dpBag[num - 1][volum];
}

/*完全背包*/
int dpBagFun2(const vector<int>& vtWeight, const vector<int>& vtValue, int num, int volum)
{
	vector<vector<int>> dpBag(num, vector<int>(volum + 1));
	
	for (int i = 0; i < volum + 1; ++i) {
		if (vtWeight.at(0)>i) {
			dpBag[0][i] = 0;
		}
		else {
			dpBag[0][i] = i/vtWeight.at(0)*vtValue.at(0);
		}
	}
	for (int i = 0; i < num; ++i) {
		dpBag[i][0] = 0;
	}

	for (int i = 1; i < num; ++i) {
		for (int j = 1; j <= volum; ++j) {
			if (j < vtWeight.at(i)) {
				dpBag[i][j] = dpBag[i - 1][j];
			}
			else {
				int A = dpBag[i][j - vtWeight.at(i)] + vtValue.at(i);
				int B = dpBag[i - 1][j];
				dpBag[i][j] = (A > B) ? A : B;
			}
		}
	}
	return dpBag[num - 1][volum];
}


int main() {
	string tmp;
	vector<string> data;
	vector<int> vtv, vtw;

	getline(cin, tmp);
	data = split(tmp, ",");
	transform(data.begin(), data.end(), back_inserter(vtv), [](const string& s) {return stoi(s); });

	getline(cin, tmp);
	data.clear();
	data = split(tmp, ",");
	transform(data.begin(), data.end(), back_inserter(vtw), [](const string& s) {return stoi(s); });

	int countW = 0;
	cin >> countW;

	cout << dpBagFun2(vtw, vtv, vtw.size(), countW) << endl;


	//cout << "------------" << endl;
	//copy(vtv.begin(), vtv.end(), ostream_iterator<int>(cout, ",")); cout << endl;
	//copy(vtw.begin(), vtw.end(), ostream_iterator<int>(cout, ",")); cout << endl;
	//cout << countW << endl;
	
	



	system("pause");
}
