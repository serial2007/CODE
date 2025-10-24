#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/*
	指针 i 不回溯，由 j 退回到某一个位置 k 上，
	使得 st 中的前 k-1 个字符与 i 指针的 k-1 个字符相等
*/


static void get_next(const string pat, int next[])
{
	/*
		next[j] = -1  						if j=0
			= max(最后的字符串=开始字符串长度) 	else
	*/


	int j = 0, k = -1;
	next[0] = -1;
	while(j < (int)pat.size()-1)
	{
		if(k==-1 || pat[j] == pat[k])
		{
			j++; k++;
			next[j] = k;
		}
		else{
			k = next[k]; // 使用已经得出的 k 的数据进行回溯
		}
	}
	for(int i=0; i<pat.size(); i++)
		std::cout << next[i] << ' ';
	std::cout << std::endl;
}


int kmp_find(const string st, const string pat)
{
	int *next = new int[pat.size()];
	get_next(pat, next);
	
	int i = 0, j = -1;
	while(i<(int)st.size() && j<(int)pat.size())
	{
		if(j==-1 || st[i] == pat[j]) {
			i++; j++;
		}
		else{
			j = next[j];
		}
	}

	delete[] next;
	if(j == (int)pat.size())
	{
		return i-j;
	}
	else return -1;
}

int main()
{
	string st, pat;
	while(getline(cin, st) && getline(cin, pat))
	{
		cout << kmp_find(st, pat) << endl;
	}
}