#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;


int main() {
	vector<int> vt = { 1,2,3,4,19,45,34,100 };
	copy(vt.begin(), vt.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	vector<int> vt2;
	vt2.resize(vt.size());
	transform(vt.begin(), vt.end(),vt2.begin() , [](int i) {return i * 10; });
	copy(vt2.begin(), vt2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	//system("pause");
}

