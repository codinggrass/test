#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
	// write code here
	int x = 0, y = 0;
	for (auto a : f) {
		int x = a[0] - 1;
		int y = a[1] - 1;
		if (x - 1 >= 1) {
			A[x - 1][y] = ~A[x - 1][y];
		}
		if (x + 1 <= 4) {
			A[x + 1][y] = ~A[x + 1][y];
		}
		if (y - 1 >= 1) {
			A[x][y - 1] = ~A[x][y - 1];
		}
		if (y + 1 <= 4) {
			A[x][y + 1] = ~A[x][y + 1];
		}
	}
	return A;
}
void AverageAge()
{
	// 总人数为W，平均年龄为Y岁
	// 每年离职率为x，x>0&&x<1
	double W, Y, x, N;

	cin >> W >> Y >> x >> N;
	
		while (N--)
		{
			Y = 21 * x + (1 - x) * (Y + 1);
		}

		cout << ceil(Y) << endl;
	
}

void getNumbers()
{
	int n, t, c;
	while (cin >> n >> t >> c)
	{
		vector<int> a(n);
		for (auto i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int result = 0;
		int sum = 0;
		for (auto i = 0; i < c; i++)
		{
			sum += a[i];
		}
		if (sum <= t)
			result++;
		for (auto i = c; i < n; i++)
		{
			sum -= a[i - c];
			sum += a[i];
			if (sum <= t)
				result++;
		}
		cout << result << endl;
	}
	return;
}

void MinArea()
{
	int nPoint;
	while (cin >> nPoint)
	{
		int tempx = 0, tempy = 0;;
		vector<int>x ;
		vector<int> y;
		for (auto a = 0; a < nPoint;a++)
		{
			cin >> tempx >> tempy;
			x.push_back(tempx);
			y.push_back(tempy);
		}
		int dx = *max_element(x.begin(),x.end())- *min_element(x.begin(), x.end());
		int dy = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
		int result = dx > dy ? dx  : dy ;
		cout << result*result << endl;

	}
}


void flish()
{
	int n = 0, m = 0, x = 0, y = 0, t = 0;
	float  prob[1001][1001] = { 0 };
	while (cin >> n >> m >> x >> y >> t)
	{
		float sumP = 0;
		for (auto b = 0; b < n; b++)
		{
			for (auto a = 0; a < m; a++)
			{
				cin >> prob[b][a];
				sumP += prob[b][a];
			}
		}
		float ssP = 0, ccP = 0;
		ccP = 1 - pow((1 - prob[x - 1][y - 1]), t);
		sumP = sumP / (n*m);
		ssP = 1 - pow(1 - sumP, t);
		if (ccP > ssP)
		{
			cout << "cc" << endl;
			cout << fixed << setprecision(2) << ccP << endl;
		}
		else if (ccP < ssP)
		{
			cout << "ss" << endl;
			cout << fixed << setprecision(2) << ssP << endl;
		}
		else
		{
			cout << "equal" << endl;
			cout << fixed << setprecision(2) << ssP << endl;
		}
	}
}

//蛇形矩阵
void snake(int n)
{
	const int number = n;
	int array[1000][1000];
	int i=0, j=0;
	array[i][j] = 1;
	int flag = 1;
	int temp = 2;

	int max1 = n - 1;
	int max2 = n - 1;
	int min3 = 0;
	int min4 = 0;
	
	while (temp<=n*n)
	{
		int increaseflag = 1;
		while (increaseflag)
		{
			if (flag == 1)
			{
				if (j < max1) { j++; increaseflag = 0; }
				else if (j == max1) { flag = 2; min4++; }
			}
			if (flag == 2)
			{
				if (i < max2) {
					i++; increaseflag = 0;
			}
				else if (i == max2) { flag = 3; max1--; }
			}
			if (flag == 3)
			{
				if (j > min3) { j--; increaseflag = 0; }
				else if (j == min3) { flag = 4; max2--; }
			}
			if (flag == 4)
			{
				if (i > min4) {i--; increaseflag = 0;}
				else if (i == min4) { flag = 1; min3++; }
			}
		}
		array[i][j] = temp;
		temp++;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << array[i][j] << ' ';
		}
}

void mushroom()
{
	int n, m,k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> mp(n + 1, vector<int>(m+1, 0));
		vector<vector<float>> p(n + 1, vector<float>(m + 1, 0));
		int x, y;
		while (k)
		{
			cin >> x >> y;
			mp[x][y] = 1;
			k--;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == 1 && j == 1)
				{
					p[i][j] = 1.0;
					continue;
				}
				if (mp[i][j] == 1)
				{
					p[i][j] = 0;
				}
				else
				{
					p[i][j] = p[i][j - 1] * (i == n ? 1.0 : 0.5) + 
						p[i - 1][j] * ( j == m ? 1.0 : 0.5);
				}
			}
		cout.setf(ios::fixed);
		cout << setprecision(2) <<p[n][m]<< endl;
	}
}


void MoveCircle()
{
	int r, x, y, x1, y1;
	while (cin >> r >> x >> y >> x1 >> y1)
	{
		float dis = sqrt((float)pow((x - x1), 2) + (float)pow((y - y1), 2));
		cout << dis / 2 / r  << endl;
		cout << (int)ceil(dis / 2 / r) << endl;
	}
}

void MaxInterval()
{
	int n;
	while (cin >> n)
	{
		vector<int> array(n, 0);
		for (auto a = 0; a < n;a++)
		{
			cin >> array[a];

		}
		int max=0, min=1000;
		for (int j = 1; j < n-1; j++)
		{
			if (array[j] - array[j - 1]>max)
				max = array[j] - array[j - 1];
			if (array[j + 1] - array[j - 1] < min)
				min = array[j + 1] - array[j - 1];
		}
		max = (array[n - 1] - array[n - 2] > max) ? array[n - 1] - array[n - 2] : max;
		max = max > min ? max : min;
		cout << max << endl;
	}
}

int main()
{
	MaxInterval();
	return 0;
}