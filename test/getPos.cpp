#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
//二分法查找数据
using namespace std;
int getPos(vector<int> A, int n, int val) {
	// write code here
	vector<int> v_index;
	int findex = 0;
	int bindex = n - 1;
	if (findex == bindex)
		return findex;
	int minindex = 0;
	while (findex<bindex) {
		minindex = (findex + bindex) / 2;
		if (A[minindex] == val)
		{
			v_index.push_back(minindex);
			break;
		}
		if (A[minindex]>val)
			bindex = minindex-1;
		else
			findex = minindex+1;
	
	}
	if (v_index.empty())
		return -1;
	else {
		while (minindex>0 && A[minindex] == A[minindex - 1]) {
			minindex--;
		}
		return minindex;
	}
}
void test(int val)
{
	vector<int> a = { 11,27,28,33,33 };
	int n = a.size();
	cout << getPos(a, n, val) << endl;;
}
char findFirstRepeat(string A, int n) {
	// write code here
	vector<int> v(1000, 0);

	char c ;
	int int_c = 0;
	for (auto a = A.begin(); a != A.end(); a++)
	{
		
		c = *a;
		int_c = c;
		if (v[int_c] == 1)
		{
			break;
		}
		v[int_c] = 1;
	}
	return c;
}

bool compare(pair<string,int> a,pair<string,int>b)
{
	return a.second > b.second;
}

vector<string> findCoder(vector<string> A, int n) {
	// write code here
	string str1 = "code";
	vector<pair<string, int>> vInclude;
	vector<string> AA=A;
	int i = 0;
	for (auto a : AA)
	{
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		auto temp_a = a;
		auto pos = temp_a.find(str1);	
		int times = 0;
		if (pos != string::npos)
		{
			while (pos != string::npos)
			{
				times++;
				temp_a.erase(pos, 5);
				pos = temp_a.find(str1);
			}
			vInclude.push_back(make_pair(A[i], times));
		}
		i++;
	}
	stable_sort(vInclude.begin(), vInclude.end(), 
		[](pair<string, int> p1, pair<string, int> p2) {return p1.second > p2.second; });
	vector<string> result;
	for (auto a : vInclude)
		result.push_back(a.first);
	return result;
}
void test2()
{
	vector<string> a = { "coder is a","a sjd ad codeR coder!" }, b;
	b = findCoder(a, 2);
	for (auto c : b)
		cout << c << endl;
}

int getDis(vector<int> A, int n) {
	// write code here
	int a = 0, b = 1;
	if (n < 2)
		return 0;
	int maxDis = 0;
	for (a = 0; a < n;a++)
	{
		for (b = a+1; b < n&&b > a; b++)
		{
			if (maxDis < A[b] - A[a])
				maxDis = A[b] - A[a];
		}

	}
	return maxDis;
}
void test3()
{
	vector<int> A = { 5386,5384,11054,6345,5816,11757 };
	cout << getDis(A, 6) << endl;
}
int main()
{
	vector<int> a;
	//test(33);
	//test2();
	test3();
	return 0;
}