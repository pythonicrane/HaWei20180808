/*
[���|200��] С͵͵��������
ʱ�����ƣ�C/C++ 4�룬�������� 8��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
С͵������һ�����ص�������ͻȻ��ǰһ��������5��������ÿ�������ļ�ֵ����һ����������Ҳ��һ��������С͵�ı���Я������
���ޣ����������ò��ڱ���������ѡ�񣬲���ʹ͵���ĲƸ�����������С͵����һ�¡�
��������:
������ֵ��6,3,5,4,6
����������2,2,6,5,4
С͵����������10
�������:
͵���������ܼ�ֵ��15
ʾ��1
����
6,3,5,4,6
2,2,6,5,4
10
���
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
	string::size_type pos2 = str.find(delim, pos1);//��pos1��ʼ����delim
	while (string::npos != pos2) {//����Խ�����������ĩû��delim����������� 1,2,3
		vts.push_back(str.substr(pos1, pos2 - pos1));
		pos1 = pos2 + delim.size();
		pos2 = str.find(delim, pos1);
	}
	vts.push_back(str.substr(pos1, pos2 - pos1));
	return vts;
}

/*01����*/
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

/*��ȫ����*/
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
