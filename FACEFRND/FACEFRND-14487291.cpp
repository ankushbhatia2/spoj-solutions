#include<bits/stdc++.h>
#define Get getchar()
#define ll unsigned long long
#define pc(x) putchar(x)
using namespace std;
int binary_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return binary_gcd(b, a % b);
}
bool isprime (int num)
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
/*bool isBipartite(int G[][V], int src)
{
    // Create a color array to store colors assigned to all veritces. Vertex
    // number is used as index in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to vertex 'i'.  The value
    // 1 is used to indicate first color is assigned and value 0 indicates
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

         // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with
    // alternate color
    return true;
}*/
vector<int> primes;

void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
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
int main()
{
    SieveOfEratosthenes(50030);
    int n=getInt();
    int a[n];
    vector <int> b;
    for(int i=0; i<n; i++){
        a[i]=getInt();
        int m=getInt();
        for(int j=0; j<m; j++){
            b.push_back(getInt());
        }
    }
    set<int> s(b.begin(), b.end());
    set<int>::iterator iter;
    cout<<endl;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(binary_search(s.begin(), s.end(), a[i])==true)
            cnt+=1;
    }
    printf("%d\n", s.size() - cnt);
    return 0;
}
