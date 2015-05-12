#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

#include <unordered_map>
#include <unordered_set>

#define N 100010

using namespace std;

int signal;
int s[N];	//每个模块的触发信号
int k[N];	//每个模块输出个数 
int e[N][3];//模块N的输出，最多有3个
int cnt[N];	//每个模块被触发的次数

int main()
{
    int t;					//测试次数
	int n;					//模块个数
	int m;					//初始信号个数

    scanf("%d", &t);		//获取测试次数
    while(t --)				
    {
        scanf("%d %d", &n, &m);	//获取模块个数，初始信号数

        queue<int> q;

        for(int i = 0; i < m; ++ i)
        {
            scanf("%d", &signal);	//获取m个初始信号，并放入q
            q.push(signal);
        }

        unordered_map<int, unordered_set<int>> signal_module;

        for(int i = 0; i < n; ++ i)
        {
            scanf("%d %d", &s[i], &k[i]);	//获取每个模块的触发信号，输出个数
            signal_module[s[i]].insert(i);	//signal_module保存每个信号可以触发的模块号
            for(int j = 0; j < k[i]; ++ j)	//保存每个模块的输出到e[模块号][0-2]
                scanf("%d", &e[i][j]);
        }

        memset(cnt, 0, sizeof(cnt));		//每个模块运行次数清0

        while(!q.empty())			//信号队列中还有信号
        {
            signal = q.front();		//获取先进入的信号
            q.pop();

            unordered_set<int> module = signal_module[signal];
            for(auto it = module.begin(); it != module.end(); ++ it)	//获取该信号可以触发的模块,it是pointer
            {
                cnt[*it] = (cnt[*it] + 1) % 142857;						//模块运行次数+1

                for(int i = 0; i < k[*it]; ++ i)						//产生输出信号，并放入队列
                    q.push(e[*it][i]);
            }
        }

        for(int i = 0; i < n; ++ i)
            cout << cnt[i] << (i < n - 1 ? " " : "\n");
    }
    return 0;
}
