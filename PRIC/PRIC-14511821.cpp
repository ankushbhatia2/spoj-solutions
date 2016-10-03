#include<cstdio>
#include<cmath>
#define ll long long
bool isprime (ll num)
{
    if (num <=1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);

        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}
int main()
{
    ll a=1;
    for(int i=0; i<9000; i++){
        isprime(a)?printf("1"):printf("0");
        a = (a + 1234567890)%(2147483648);
    }
    return 0;
}
