#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll dp[20];  //  前x位中1出现次数（0~9均是如此）
void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++) {
        dp[i] = dp[i - 1] * 10 + pow(10, i - 1);    //  前x-1位出现1次数*10 + 第x位为1的情况数
    }
}
ll count(ll x)
{
    ll result = 0;
    ll len = 0;
    ll digit = 0;
    ll radix = 1;
    ll tail = 0;
    while (x != 0)
    {
        digit = x % 10;
        x = x / 10;
        ++len;
        if (digit > 1)	{                            //  radix就代表10的多少多少次方
            result += radix + digit * dp[len - 1];  //  ex:241 result(200~241) += radix(百位为1）+ digit
        }                                           //  * dp[len - 1](0~199除去百位为1)
        else if (digit == 1) {                      //  +1是代表取的那个整数
            result += tail + 1 + dp[len - 1];       //  ex:141 result(100~141除去百位的1) += tail(101~141百位
        }                                           //  为1) + 1(100的百位为1) + dp[len - 1](0~99)
        tail = tail + digit * radix;                //  头为1个数
        radix *= 10;                                //  倍率
	}
	return result;
}
int main() {
	ll n;
	init();
	scanf("%lld", &n);
	printf("%lld\n", count(n));
	return 0;
}
