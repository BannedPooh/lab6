#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

int MAX_SIZE = 1000;

double mean(double arr[], int size);
double median(double arr[], int size);
double sd(double arr[], int size);
// double sort(double arr[], int size);

int main()
{
    ifstream in_stream;
    string filename;
    double array[MAX_SIZE];

    cout<<"Enter filename: ";
    cin>>filename;
    in_stream.open(filename);
    if (in_stream.fail())
    {
        cerr<<"Error opening file\n";
        exit(-1);
    }

    int size = 0;
    double next = 0;
    while (in_stream>>next)
    {
        array[size] = next;
        ++size;
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout<<"Mean = "<<mean(array, size)<<endl;
    cout<<"Median = "<<median(array, size)<<endl;
    cout<<"Stddev = "<<sd(array, size)<<endl;
    return 0;
}

double mean(double arr[], int size)
{
    double result = 0;

    for (int i = 0; i!=size; ++i)
    {
        result += arr[i]/size;
    }
    return result;
}

double median(double arr[], int size)
{
    for (int i = size-1; i>=0; --i){
        for (int j = 1; j<=i; j++)
        {
            if (arr[j]<=arr[j-1])
            {
                double tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }

    // for (int i = 0; i!=size; ++i)
    // {
    //     cout<<i<<": "<<arr[i]<<endl;
    // }
    

    double result;
    if (size == 1)
    {
        return arr[0];
    }

    if (size%2 == 1)
    {
        result = arr[(size-1)/2];
    }
    else
    {
        result = (arr[size/2-1]+arr[size/2])/2;
    }
    return result;
}
double sd(double arr[], int size)
{
    double m = mean(arr, size);
    double variance;
    for (int i = 0; i!= size; ++i)
    {
        variance += (arr[i]-m)*(arr[i]-m);
    }

    return sqrt(variance/(size-1));
}

// double sort(double arr[], int size)
// {
//     for (int i = size-1; i>=0; --i){
//         for (int j = 1; j<=i; j++)
//         {
//             if (arr[j]<=arr[j-1])
//             {
//                 double tmp = arr[j];
//                 arr[j] = arr[j-1];
//                 arr[j-1] = tmp;
//             }
//         }
//     }
// }