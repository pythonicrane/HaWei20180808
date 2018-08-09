/*
[���|300��] ��ȡtypedef����������
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
C++�е�typedef�ô��ܶ࣬�����ñ�׼���Լ�DIY�����ͣ�Ϊ�������typedef�ܸ�ɶ�����⿼�����typedef��ĳ���Զ������͵�������̬��ɶ��
����Ϊ�����֣������У�
��һ����һ��typedef���壬��׼C++��䣬�ԷֺŽ��������ﲻ�ÿ���struct/union���ֻ࣬��Ҫ���ǻ������ͺ�ָ�롣
�ڶ������ƶ�ĳ���Զ���type
���Ϊ���Զ���type��������̬
�����룺
typedef int INT; typedef INT** INTP;
INTP
�������int * *
ע�⣬�����ָ�����ͣ���ָ�����*��ǰ��������м���һ���ո񣬺ͱ��������������һ�£����⣬�����һ�����������Ǳ��벻���ģ����ߵڶ���ѡ���type�ڵ�һ����û�ж��壬�����none
��������:
typedef��һ���Զ������ͣ����ƶ�������Ҫ����������
�������:
�����������������֣��ͱ������������һ��
ʾ��1
����
����
typedef int INT; typedef INT** INTP;
INTP
���
����
int * *
��ע:
�����ָ�����ͣ���ָ�����*��ǰ��������м���һ���ո�����ж��*��֮�䶼Ҫ�ÿո������
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