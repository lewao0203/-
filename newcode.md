###### 1、计算字符串最后一个单词的长度

计算字符串最后一个单词的长度，单词以空格隔开。

注:由于是由空格隔开的，所以不能直接cin>>s(cin遇到空格、回车等自动结束输入)

```c++
	string s;
	cin >> s;
	cout << s << endl;

	string s1;
	getline(cin, s1,' ');  // 自定义结束符，默认为回车
	cout << s1;
	/*
		cin.get()当输入的字符串超长时，不会引起cin函数的错误，后面的cin操作会继续执行，只是直接从缓冲区中取数据。
		但是getline()当输入超长时，会引起cin函数的错误，后面的cin操作将不再执行。
	*/
	string s2;
	s2 = cin.get();
	cout << s2;
```



```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int len = s.length();
	int end = len - 1;
	int start = len - 1;

	while (end >= 0 && s[end] == ' '  )
		end--;
	start = end;
	while ( start >= 0 && s[start] != ' ')
		start--;
	cout << end - start << endl;

	return 0;
}
```

###### 2、计算字符个数

写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

```
map排序是按照键值排序的，
erase（key|iterator）
```

```c++
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char s_c;
    cin >> s_c;
    
    int len = s.length();
    unordered_map<char, int> hm;
    for(int i=0;i<len;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            char c = s[i] - 32;
            hm[c] ++;
        }
        else
            hm[s[i]]++;
    }
    if( s_c>= 'a' && s_c <= 'z')
        cout<<hm[s_c-32];
    else
        cout<<hm[s_c];
    return 0;
}
```

###### 3、随机数

明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。

![image-20200901160211807](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200901160211807.png)

注：本题关键在于输入时，组数未知。。故while(cin >> n)，若不再输入，则退出循环

```c++
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        set<int> se;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            se.insert(tmp);
        }
        for(set<int>::iterator it = se.begin();it != se.end();it++)
        {
            cout<<(*it)<<endl;
        }
    }
}

set还有一种赋值
	while (cin >> n)
	{
		vector<int> vec(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}
		set<int> se(&vec[0],&vec[0]+n);

		for (set<int>::iterator it = se.begin(); it != se.end(); it++)
		{
			cout << (*it) << endl;
		}
	}
```

###### 4、字符串分割

•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

```c++
// 注意：字符串添加时
// 1、string s    s+"aaa"/s+'a'都可
// 2、append函数可加字符   s.append(n,'a'),向后添加n个a
// 3、insert插入   
// 3.1 插入字符时，需s.insert(1,2,'a')  在下标为1的位置插入两个a（2不可省略）
// 3.2 若要省略个数，则需s.insert(itera,'a');  在迭代器itera位置插入a，返回插入位置的迭代器
// 3.3 插入字符串时，可省略 s.insert(0,"aa")   在0位置插入字符串（注意与插入字符的区别）

// 因为有两组数据，故直接将两组数据分别输入
// 先计算长度，整除8，多余的补0
#include <iostream>
#include <string>
using namespace std;

void helper(string &s)
{
    int len = s.length();
    int cnt = len/8;
    for(int i=0;i<cnt;i++)
    {
        string sub = s.substr(i*8,8);
        cout<<sub<<endl;
    }
    if(cnt*8 == len) return ;
    int res_num = len-cnt*8;
    string sub = s.substr(cnt*8,res_num);
    sub.append(8-res_num,'0');
    cout<<sub<<endl;
}
int main()
{
    string s;
    cin >> s;
    helper(s);
    
    string s2;
    cin>>s2;
    helper(s2);
    return 0;
}
```

###### 5、汽水瓶

有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

```
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。
```

```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		int res;
		int d;
        int tmp = n;
		while (1)
		{
			res = n % 3;
			d = n / 3;
			cnt += d;
			if (res + d == 1 || res + d == 0) break;
			if (res + d == 2)
			{
				cnt++;
				break;
			}
			n = res + d;
		}
		cout << cnt;
	}
}

# 超时，故需考虑其他方法
```

###### 6、质数因子

功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）

最后一个数后面也要有空格

```c++
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	long num;
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			cout << i << " ";
			num = num / i;
			i = i-1;
		}
	}
	return 0;
}
```

7、取近似值

写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

```c++
#include <iostream>

using namespace std;

int main()
{
    float num;
    cin >> num;
    
    float res = num - (int)num;
    if(res >= 0.5)
        cout<<(int)num+1<<endl;
    else
        cout<<int(num)<<endl;
}
```

