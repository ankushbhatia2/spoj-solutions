#include<bits/stdc++.h>
#define Get getchar()
#define ll unsigned long long
#define pc(x) putchar(x)
using namespace std;
int binary_gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return binary_gcd(b, a % b);
}
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

inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
inline int getInt()
{
    int a=0,s=1;
    char c=Get;
    while(c<33)
        c=Get;
    if(c=='-')
    {
        s=-1;
        c=Get;
    }
    while(c>33)
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=Get;
    }
    return a*s;
}


/* Returns length of LCS for X[0..m
ll fact(int a){
    if(a == 0)
        return 1;
    else{
        ll b=1;
        for(int i=1; i<=a; i++)
            b*=i;
        return b;
    }
}*/
inline unsigned int tnum(unsigned long long int n) {
    unsigned long long int a = 0, b = 1;
    unsigned int c = 1, d = 0, sum = 0;
    while (n) {
        if (n % 2) {
            sum += (a + 1)*c + d*(b / 2);
            a += b;
        }
        d += c;
        b *= 2;
        c *= 3;
        n /= 2;
    }
    return sum;
}
#define X 1001
bool isBipartite(int G[][X], int src, int V)
{
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1;
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
    vector  <int> primes;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));

        //Following property is maintained in the below for loop
          // arr[i] == 0 means i + 1 is prime
          // arr[i] == 1 means i + 1 is not prime
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                primes.push_back(i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}
int minDistance(int dist[], bool sptSet[], int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
int g[1000][1001];
int main()
{
    int t=getInt();
    for(int i=1; i<=t; i++){
        int N=getInt(), R=getInt();
		bool spying = true;
		set<int> S, C;
		for(int j=0; j<R; j++)
		{
			int R1=getInt(), R2=getInt();
			C.insert( R1 );
			S.insert( R2 );
		}
		for(int j=0; j<N; j++ )
		{
			if( C.count( j ) > 0 && S.count( j ) > 0 )
			{
				spying = false;
				break;
			}
		}
        if(spying==true){
            printf("Scenario #%d: spying\n", i);
        }
        else{
            printf("Scenario #%d: spied\n", i);
        }
    }
    return 0;
}
