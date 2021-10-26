#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

void bubSort(int* array, int size){
	for (int i=0; i<size-1; i++){
		for (int j=size-1; j>i; j--){
			if(array[i]>array[j]){
				int temp=array[j];
				array[j]=array[i];
				array[i]=temp;
			} 
		}
	}
}//冒泡排序 

void qsort(int* array, int leftSide, int rightSide){
    if(leftSide>=rightSide){
        return ;
    }
    int pivot=array[(leftSide+rightSide)/2];
    int start=leftSide;
    int end=rightSide;
    while(end>start){
        while(end>=start&&array[end]>pivot){
            end--;
        }
        while(end>=start&&array[start]<pivot){
            start++;
        }
        if(end>=start){
            int temp=array[start];
            array[start]=array[end];
            array[end]=temp;
            end--;
            start++;
        }
    }
    qsort(array, leftSide, end);
    qsort(array, start, rightSide);
}//快速排序 

int array_100[105];
int array_1000[1005];
int array_10000[10005];
int array_100000[100005];
int array_1000000[1000005];

ofstream outfile("report.txt", ios::out);
int main(){
    //***********************************************
    ifstream infile_100_bub("data_100.txt", ios::in);
    for (int i=0; i<100; i++){
        infile_100_bub >> array_100[i];
    }
    infile_100_bub.close();
    LARGE_INTEGER LIB_100_bub;
    LARGE_INTEGER LIE_100_bub;
    LARGE_INTEGER FREQ_100_bub;
    QueryPerformanceFrequency(&FREQ_100_bub);
    QueryPerformanceCounter(&LIB_100_bub);
    bubSort(array_100, 100);
    QueryPerformanceCounter(&LIE_100_bub);
    double time_100_bub=(double)(LIE_100_bub.QuadPart-LIB_100_bub.QuadPart)/((double)FREQ_100_bub.QuadPart);
    outfile << "数据规模为100的冒泡排序结果: " << endl;
    for(int i=0; i<100; i++){
        outfile << array_100[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为100的冒泡排序所需时间: ";
    cout  << fixed << setprecision(8) << time_100_bub << endl;
    //***********************************************
    ifstream infile_100_qsort("data_100.txt", ios::in);
    for (int i=0; i<100; i++){
        infile_100_qsort >> array_100[i];
    }
    infile_100_qsort.close();
    LARGE_INTEGER LIB_100_qsort;
    LARGE_INTEGER LIE_100_qsort;
    LARGE_INTEGER FREQ_100_qsort;
    QueryPerformanceFrequency(&FREQ_100_qsort);
    QueryPerformanceCounter(&LIB_100_qsort);
    qsort(array_100, 0, 99);
    QueryPerformanceCounter(&LIE_100_qsort);
    double time_100_qsort=(double)(LIE_100_qsort.QuadPart-LIB_100_qsort.QuadPart)/((double)FREQ_100_qsort.QuadPart);
    outfile << "数据规模为100的快速排序结果: " << endl;
    for(int i=0; i<100; i++){
        outfile << array_100[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为100的快速排序所需时间: ";
    cout << fixed << setprecision(8) << time_100_qsort << endl;
    infile_100_qsort.close();
    cout << endl;
    //---------------------------------------------------------------------
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_1000_bub("data_1k.txt", ios::in);
    for (int i=0; i<1000; i++){
        infile_1000_bub >> array_1000[i];
    }
    infile_1000_bub.close();
    LARGE_INTEGER LIB_1000_bub;
    LARGE_INTEGER LIE_1000_bub;
    LARGE_INTEGER FREQ_1000_bub;
    QueryPerformanceFrequency(&FREQ_1000_bub);
    QueryPerformanceCounter(&LIB_1000_bub);
    bubSort(array_1000, 1000);
    QueryPerformanceCounter(&LIE_1000_bub);
    double time_1000_bub=(double)(LIE_1000_bub.QuadPart-LIB_1000_bub.QuadPart)/((double)FREQ_1000_bub.QuadPart);
    outfile << "数据规模为1000的冒泡排序结果: " << endl;
    for(int i=0; i<1000; i++){
        outfile << array_1000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为1000的冒泡排序所需时间: ";
    cout << fixed << setprecision(8) << time_1000_bub << endl;
    //***********************************************
    ifstream infile_1000_qsort("data_1k.txt", ios::in);
    for (int i=0; i<1000; i++){
        infile_1000_qsort >> array_1000[i];
    }
    infile_1000_qsort.close();
    LARGE_INTEGER LIB_1000_qsort;
    LARGE_INTEGER LIE_1000_qsort;
    LARGE_INTEGER FREQ_1000_qsort;
    QueryPerformanceFrequency(&FREQ_1000_qsort);
    QueryPerformanceCounter(&LIB_1000_qsort);
    qsort(array_1000, 0, 999);
    QueryPerformanceCounter(&LIE_1000_qsort);
    double time_1000_qsort=(double)(LIE_1000_qsort.QuadPart-LIB_1000_qsort.QuadPart)/((double)FREQ_1000_qsort.QuadPart);
    outfile << "数据规模为1000的快速排序结果: " << endl;
    for(int i=0; i<1000; i++){
        outfile << array_1000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为1000的快速排序所需时间: ";
    cout << fixed << setprecision(8) << time_1000_qsort << endl;
    infile_1000_qsort.close();
    cout << endl;
    //---------------------------------------------------------------------
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_10000_bub("data_10k.txt", ios::in);
    for (int i=0; i<10000; i++){
        infile_10000_bub >> array_10000[i];
    }
    infile_10000_bub.close();
    LARGE_INTEGER LIB_10000_bub;
    LARGE_INTEGER LIE_10000_bub;
    LARGE_INTEGER FREQ_10000_bub;
    QueryPerformanceFrequency(&FREQ_10000_bub);
    QueryPerformanceCounter(&LIB_10000_bub);
    bubSort(array_10000, 10000);
    QueryPerformanceCounter(&LIE_10000_bub);
    double time_10000_bub=(double)(LIE_10000_bub.QuadPart-LIB_10000_bub.QuadPart)/((double)FREQ_10000_bub.QuadPart);
    outfile << "数据规模为10000的冒泡排序结果: " << endl;
    for(int i=0; i<10000; i++){
        outfile << array_10000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为10000的冒泡排序所需时间: ";
    cout << fixed << setprecision(8) << time_10000_bub << endl;
    //***********************************************
    ifstream infile_10000_qsort("data_10k.txt", ios::in);
    for (int i=0; i<10000; i++){
        infile_10000_qsort >> array_10000[i];
    }
    infile_10000_qsort.close();
    LARGE_INTEGER LIB_10000_qsort;
    LARGE_INTEGER LIE_10000_qsort;
    LARGE_INTEGER FREQ_10000_qsort;
    QueryPerformanceFrequency(&FREQ_10000_qsort);
    QueryPerformanceCounter(&LIB_10000_qsort);
    qsort(array_10000, 0, 9999);
    QueryPerformanceCounter(&LIE_10000_qsort);
    double time_10000_qsort=(double)(LIE_10000_qsort.QuadPart-LIB_10000_qsort.QuadPart)/((double)FREQ_10000_qsort.QuadPart);
    outfile << "数据规模为10000的快速排序结果: " << endl;
    for(int i=0; i<10000; i++){
        outfile << array_10000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为10000的快速排序所需时间: ";
    cout << fixed << setprecision(8) << time_10000_qsort << endl;
    infile_10000_qsort.close();
    cout << endl;
    //---------------------------------------------------------------------
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_100000_bub("data_100k.txt", ios::in);
    for (int i=0; i<100000; i++){
        infile_100000_bub >> array_100000[i];
    }
    infile_100000_bub.close();
    LARGE_INTEGER LIB_100000_bub;
    LARGE_INTEGER LIE_100000_bub;
    LARGE_INTEGER FREQ_100000_bub;
    QueryPerformanceFrequency(&FREQ_100000_bub);
    QueryPerformanceCounter(&LIB_100000_bub);
    bubSort(array_100000, 100000);
    QueryPerformanceCounter(&LIE_100000_bub);
    double time_100000_bub=(double)(LIE_100000_bub.QuadPart-LIB_100000_bub.QuadPart)/((double)FREQ_100000_bub.QuadPart);
    outfile << "数据规模为100000的冒泡排序结果: " << endl;
    for(int i=0; i<100000; i++){
        outfile << array_100000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为100000的冒泡排序所需时间: ";
    cout << fixed << setprecision(8) << time_100000_bub << endl;
    //***********************************************
    ifstream infile_100000_qsort("data_100k.txt", ios::in);
    for (int i=0; i<100000; i++){
        infile_100000_qsort >> array_100000[i];
    }
    infile_100000_qsort.close();
    LARGE_INTEGER LIB_100000_qsort;
    LARGE_INTEGER LIE_100000_qsort;
    LARGE_INTEGER FREQ_100000_qsort;
    QueryPerformanceFrequency(&FREQ_100000_qsort);
    QueryPerformanceCounter(&LIB_100000_qsort);
    qsort(array_100000, 0, 99999);
    QueryPerformanceCounter(&LIE_100000_qsort);
    double time_100000_qsort=(double)(LIE_100000_qsort.QuadPart-LIB_100000_qsort.QuadPart)/((double)FREQ_100000_qsort.QuadPart);
    outfile << "数据规模为100000的快速排序结果: " << endl;
    for(int i=0; i<100000; i++){
        outfile << array_100000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为100000的快速排序所需时间: ";
    cout << fixed << setprecision(8) << time_100000_qsort << endl;
    infile_100000_qsort.close();
    cout << endl;
    //---------------------------------------------------------------------
    outfile << endl;
    outfile << endl;
    outfile << endl;
    ifstream infile_1000000_bub("data_1M.txt", ios::in);
    for (int i=0; i<1000000; i++){
        infile_1000000_bub >> array_1000000[i];
    }
    infile_1000000_bub.close();
    LARGE_INTEGER LIB_1000000_bub;
    LARGE_INTEGER LIE_1000000_bub;
    LARGE_INTEGER FREQ_1000000_bub;
    QueryPerformanceFrequency(&FREQ_1000000_bub);
    QueryPerformanceCounter(&LIB_1000000_bub);
    bubSort(array_1000000, 1000000);
    QueryPerformanceCounter(&LIE_1000000_bub);
    double time_1000000_bub=(double)(LIE_1000000_bub.QuadPart-LIB_1000000_bub.QuadPart)/((double)FREQ_1000000_bub.QuadPart);
    outfile << "数据规模为1000000的冒泡排序结果: " << endl;
    for(int i=0; i<1000000; i++){
        outfile << array_1000000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为1000000的冒泡排序所需时间: ";
    cout << fixed << setprecision(8) << time_1000000_bub << endl;
    //***********************************************
    ifstream infile_1000000_qsort("data_1M.txt", ios::in);
    for (int i=0; i<1000000; i++){
        infile_1000000_qsort >> array_1000000[i];
    }
    infile_1000000_qsort.close();
    LARGE_INTEGER LIB_1000000_qsort;
    LARGE_INTEGER LIE_1000000_qsort;
    LARGE_INTEGER FREQ_1000000_qsort;
    QueryPerformanceFrequency(&FREQ_1000000_qsort);
    QueryPerformanceCounter(&LIB_1000000_qsort);
    qsort(array_1000000, 0, 999999);
    QueryPerformanceCounter(&LIE_1000000_qsort);
    double time_1000000_qsort=(double)(LIE_1000000_qsort.QuadPart-LIB_1000000_qsort.QuadPart)/((double)FREQ_1000000_qsort.QuadPart);
    outfile << "数据规模为1000000的快速排序结果: " << endl;
    for(int i=0; i<1000000; i++){
        outfile << array_1000000[i] << ' ';
    }
    outfile << endl;
    cout << "数据规模为1000000的快速排序所需时间: ";
    cout << fixed << setprecision(8) << time_1000000_qsort << endl;
    infile_1000000_qsort.close();
    cout << endl;
    //---------------------------------------------------------------------
    system("pause");
    return 0;
}