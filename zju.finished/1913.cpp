/*
题目大意：两个人游戏，规则：给出两个正整数，第一个人可以用小的数字的倍数减大数字，第二个人对这时的两个数字用小的数字的倍数减大数字，直到0某人减后得到0，他就胜利了。
 
每次都是Stan先减，然后Ollie减。编程对给定的数字，判断谁可以获绳。两个人都不会犯错。
 
比如, 游戏开始与(25,7):
 
25 7
11 7
4 7
4 3
1 3
1 0
 
Stan胜利.
 
0 0 结束。
 
Sample Input
 
34 12
 
15 24
 
0 0
 
Sample Output
 
Stan wins
 
Ollie wins
 
题目分析：
 
为什么这样呢？
观察后发现：假定后面的减法已经可以控制（已经确定），如果当前a，b(a>=b)两个数字，且a-b>=b ,
 
不妨设a=n*b+c,那么当前的玩家就有胜负决定权，他可以决定减n*b使得a=c 或(n-1)*b使得a=b+c。
 
还有如果a-b<b 那么当前玩家是被动的，他只能选择a-1*b;(1是不可以选的)
 
既然当前步可以控制，所以以后的所有步都可以控制。
 
有了以上结论，得出只要谁得到两个数字a，b(a>=b) 那么他就获胜了。也有可能直到结束，都没有谁得到主动权，那就按照规则，谁可以减到0，谁获胜。
 
参考代码：
*/

#include <stdio.h>

int main()
{
    int a,b,c;
    int t;//根据t得奇呕偶，可以判断轮到谁减了
    while (scanf("%d %d",&a,&b)&&(a!=0||b!=0))
    {//以上输入
        if (a<b) {
            c=a;
            a=b;
            b=c;
        }//保证a>=b
        t=0;
        while (1)
        {
            if (a/b>=2) {
                break;
            }//出现大于等于2倍情况，得出结论，终止循环
            c=a%b;                                             //其实是减
            a=b;
            b=c;
            t++;                                                  //轮换标记
            if (b==0) {
                t++;
                break;
            }          //正常结束和双倍情况胜利的是相反的，所以t++
        }

        if (t%2==0)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
