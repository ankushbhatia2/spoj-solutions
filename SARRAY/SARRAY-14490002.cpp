#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix
{
    int index;
    char *suff;
};

int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int *buildSuffixArray(char *txt, int n)
{
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
    sort(suffixes, suffixes+n, cmp);
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
    return  suffixArr;
}
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}


int main()
{
    char txt[100000];
    scanf("%s", &txt);
    int n=strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    printArr(suffixArr, n);
    return 0;
}
