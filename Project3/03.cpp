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
#include <string>
#include <map>
#include <functional>
using namespace std;

vector<string> split(const string& str, const string& delim)
{
	vector<string> vts;
	string::size_type pos1 = 0;
	string::size_type pos2 = str.find(delim, pos1);//��pos1��ʼ����delim
	while (string::npos != pos2) {//����Խ�����������ĩ��delim����������� 1,2,3,
		if (pos1 != pos2) {//�ų��ַ���ǰ����ֵ�delim,���� ,1,2,3,
			if (str.substr(pos1, pos2 - pos1) != delim) {//�ų��������ֵ�,,
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
	//����
	string s1, s2;
	getline(cin, s1);
	cin >> s2;

	map<string, string,greater<string>> m;

	//��һ���ַ����ָ��';'
	vector<string> sp = split(s1, ";");
	//�ڶ����ַ����ָ��' '
	for (auto a : sp) {
		a.append(" ");
		vector<string> tmp = split(a, " ");
		m[tmp.at(2)] = tmp.at(1);

	}
	
	//�滻
	string s = s2;
	while (findFun(s2, m)) {
		for (auto a : m) {
			if (s2.find(a.first) != string::npos) {
				s2.replace(s2.find(a.first), a.first.size(), a.second);
				break;
			}
		}
	}


	//���
	if (s == s2) {
		cout << "none" << endl;
	}
	else {
		//��'*'��' '
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
