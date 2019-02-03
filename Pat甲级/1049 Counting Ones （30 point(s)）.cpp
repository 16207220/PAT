#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll dp[20];  //  ǰxλ��1���ִ�����0~9������ˣ�
void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++) {
        dp[i] = dp[i - 1] * 10 + pow(10, i - 1);    //  ǰx-1λ����1����*10 + ��xλΪ1�������
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
        if (digit > 1)	{                            //  radix�ʹ���10�Ķ��ٶ��ٴη�
            result += radix + digit * dp[len - 1];  //  ex:241 result(200~241) += radix(��λΪ1��+ digit
        }                                           //  * dp[len - 1](0~199��ȥ��λΪ1)
        else if (digit == 1) {                      //  +1�Ǵ���ȡ���Ǹ�����
            result += tail + 1 + dp[len - 1];       //  ex:141 result(100~141��ȥ��λ��1) += tail(101~141��λ
        }                                           //  Ϊ1) + 1(100�İ�λΪ1) + dp[len - 1](0~99)
        tail = tail + digit * radix;                //  ͷΪ1����
        radix *= 10;                                //  ����
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
