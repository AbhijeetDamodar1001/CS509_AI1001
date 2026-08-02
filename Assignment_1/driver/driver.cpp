#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>

#include "../src/simple.h"
#include "../src/blocking.h"

using namespace std;
using namespace chrono;

int main()
{
    ifstream fin("tests/test_02.txt");

    if(fin.fail())
    {
        cout<<"Input file not found!";
        return 0;
    }

    int m,k,n;
    fin>>m>>k>>n;

    vector<vector<int>> A(m,vector<int>(k));
    vector<vector<int>> B(k,vector<int>(n));
    vector<vector<int>> C(m,vector<int>(n));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            fin>>A[i][j];
        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            fin>>B[i][j];
        }
    }

    cout<<"Simple GEMM"<<endl;

    auto start = high_resolution_clock::now();

    gemmSimple(A,B,C,m,k,n);

    auto end = high_resolution_clock::now();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Time : "
        <<duration_cast<microseconds>(end-start).count()
        <<" us"<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }

    cout<<"\nBlocking GEMM"<<endl;

    start = high_resolution_clock::now();

    gemmBlocking(A,B,C,m,k,n,2);

    end = high_resolution_clock::now();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Time : "
        <<duration_cast<microseconds>(end-start).count()
        <<" us"<<endl;

    fin.close();

    return 0;
}
