#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <iomanip>

using namespace std; 

ofstream report("report.txt", ios::out); //实验报告文档

int vec_100_seqs[105];
int vec_1000_seqs[1005];
int vec_10000_seqs[10005];
int vec_100000_seqs[100005];
int vec_1000000_seqs[1000005];
int SeqSearch(int* vec, int size, int key){
    for (int i=0; i<size; i++){
        if(key==vec[i]){
            return i;
        }
    }
    return -1;
}//顺序查找

int bsTime=0;
int BinSearch1(int* vec, int key, int ledge, int redge){
    if(key==vec[(ledge+redge)/2]){
		 bsTime++;
        return key;
    }
	if(redge-ledge==1){
		bsTime++;
		if(vec[redge]==key){
			bsTime++;
			return key;
		}
		bsTime++;
		if(vec[ledge]==key){
			bsTime++;
			return key;
		}
		bsTime++;
		return -1;
	}
    if(key>vec[(ledge+redge)/2]){
		 bsTime++;
        return BinSearch1(vec, key, (ledge+redge)/2, redge);
    }
    if(key<vec[(ledge+redge)/2]){
		 bsTime++;
        return BinSearch1(vec, key, ledge, (ledge+redge)/2);
    }
	bsTime++;
    return -1;
}//获取比较次数

int BinSearch2(int* vec, int key, int ledge, int redge){
    if(key==vec[(ledge+redge)/2]){
        return key;
    }
	if(redge-ledge==1){
		if(vec[redge]==key){
			return key;
		}
		if(vec[ledge]==key){
			return key;
		}
		return -1;
	}
    if(key>vec[(ledge+redge)/2]){
        return BinSearch2(vec, key, (ledge+redge)/2, redge);
    }
    if(key<vec[(ledge+redge)/2]){
        return BinSearch2(vec, key, ledge, (ledge+redge)/2);
    }
    return -1;
}//获取算法时间

int temp=0;//用来接收每个函数的返回值
int main(){
    int a;
    report << "100次查找数据规模为100且成功查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    ifstream infile_100("data_100.txt", ios::in); //数据文件
    for (int i=0; i<100; i++){
        infile_100 >> vec_100_seqs[i];
    }//放入数据
    for (int i=0; i<100; i++){ 
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_100_seqs, 100, i+1);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
		report << "    " << i+1 << "        " << temp;
	    report << "          " <<  fixed << setprecision(8) << time << endl;
	}//获得时间
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//************************************ 
	report << "100次查找数据规模为100且失败查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_100_seqs, 100, i+1);
	    QueryPerformanceCounter(&LIE);
		report << "    " << i+1 << "        " << 99;
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//*************************************
	sort(vec_100_seqs, vec_100_seqs+100);
	report << "100次查找数据规模为100且成功查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=0; i<100; i++){
		bsTime=0;
		temp=BinSearch1(vec_100_seqs, i+1, 0, 99);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_100_seqs, i+1, 0, 99);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//*************************************
	report << "100次查找数据规模为100且失败查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
		bsTime=0;
		temp=BinSearch1(vec_100_seqs, i+1, 0, 99);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_100_seqs, i+1, 0, 99);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**************************************
	
	//-------------------------------------
	infile_100.close();
	//-------------------------------------

	//**************************************
	report << "100次查找数据规模为1000且成功查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    ifstream infile_1000("data_1k.txt", ios::in);
    for (int i=0; i<1000; i++){
        infile_1000 >> vec_1000_seqs[i];
    }
    for (int i=0; i<100; i++){ 
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_1000_seqs, 1000, i+1);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
		report << "    " << i+1 << "        " << temp;
	    report << "          " <<  fixed << setprecision(8) << time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//****************************************
	report << "100次查找数据规模为1000且失败查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_1000_seqs, 1000, i+1);
	    QueryPerformanceCounter(&LIE);
		report << "    " << i+1 << "        " << 999;
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//***************************************
	sort(vec_1000_seqs, vec_1000_seqs+1000);
	report << "100次查找数据规模为1000且成功查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=0; i<100; i++){
		bsTime=0;
		temp=BinSearch1(vec_1000_seqs, i+1, 0, 999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_1000_seqs, i+1, 0, 999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**********************************
	report << "100次查找数据规模为1000且失败查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
		bsTime=0;
		temp=BinSearch1(vec_1000_seqs, i+1, 0, 999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_1000_seqs, i+1, 0, 999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**************************************
	
	//-------------------------------------
	infile_1000.close();
	//-------------------------------------

	//**************************************
	report << "100次查找数据规模为10000且成功查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    ifstream infile_10000("data_10k.txt", ios::in);
    for (int i=0; i<10000; i++){
        infile_10000 >> vec_10000_seqs[i];
    }
    for (int i=0; i<100; i++){ 
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_10000_seqs, 10000, i+1);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
		report << "    " << i+1 << "        " << temp;
	    report << "          " <<  fixed << setprecision(8) << time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//************************************
	report << "100次查找数据规模为10000且失败查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_10000_seqs, 10000, i+1);
	    QueryPerformanceCounter(&LIE);
		report << "    " << i+1 << "        " << 9999;
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//*************************************
	sort(vec_10000_seqs, vec_10000_seqs+10000);
	report << "100次查找数据规模为10000且成功查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=0; i<100; i++){
		bsTime=0;
		temp=BinSearch1(vec_10000_seqs, i+1, 0, 9999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_10000_seqs, i+1, 0, 9999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//************************************
	report << "100次查找数据规模为10000且失败查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
		bsTime=0;
		temp=BinSearch1(vec_10000_seqs, i+1, 0, 9999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_10000_seqs, i+1, 0, 9999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**************************************
	
	//-------------------------------------
	infile_10000.close();
	//-------------------------------------

	//**************************************
	report << "100次查找数据规模为100000且成功查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    ifstream infile_100000("data_100k.txt", ios::in);
    for (int i=0; i<100000; i++){
        infile_100000 >> vec_100000_seqs[i];
    }
    for (int i=0; i<100; i++){ 
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_100000_seqs, 100000, i+1);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
		report << "    " << i+1 << "        " << temp;
	    report << "          " <<  fixed << setprecision(8) << time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//*************************************
	report << "100次查找数据规模为100000且失败查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_100000_seqs, 100000, i+1);
	    QueryPerformanceCounter(&LIE);
		report << "    " << i+1 << "        " << 99999;
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//***********************************
	sort(vec_100000_seqs, vec_100000_seqs+100000);
	report << "100次查找数据规模为100000且成功查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=0; i<100; i++){
		bsTime=0;
		temp=BinSearch1(vec_100000_seqs, i+1, 0, 99999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_100000_seqs, i+1, 0, 99999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//********************************************
	report << "100次查找数据规模为100000且失败查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
		bsTime=0;
		temp=BinSearch1(vec_100000_seqs, i+1, 0, 99999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_100000_seqs, i+1, 0, 99999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**************************************
	
	//-------------------------------------
	infile_100000.close();
	//-------------------------------------

	//**************************************
	report << "100次查找数据规模为1000000且成功查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    ifstream infile_1000000("data_1m.txt", ios::in);
    for (int i=0; i<1000000; i++){
        infile_1000000 >> vec_1000000_seqs[i];
    }
    for (int i=0; i<100; i++){ 
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_1000000_seqs, 1000000, i+1);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
		report << "    " << i+1 << "        " << temp;
	    report << "          " <<  fixed << setprecision(8) << time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//*************************************
	report << "100次查找数据规模为1000000且失败查找的顺序查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		int temp=SeqSearch(vec_1000000_seqs, 1000000, i+1);
	    QueryPerformanceCounter(&LIE);
		report << "    " << i+1 << "        " << 999999;
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//***********************************
	sort(vec_1000000_seqs, vec_1000000_seqs+1000000);
	report << "100次查找数据规模为1000000且成功查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=0; i<100; i++){
		bsTime=0;
		temp=BinSearch1(vec_1000000_seqs, i+1, 0, 999999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_1000000_seqs, i+1, 0, 999999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//********************************************
	report << "100次查找数据规模为1000000且失败查找的二分查找算法耗时为：" << endl;
    report << "查找元素" << "    " <<  "比较次数" << "    " << "算法耗时" << endl;
    for (int i=-1; i>=-100; i--){
		bsTime=0;
		temp=BinSearch1(vec_1000000_seqs, i+1, 0, 999999);
		report << "    " << i+1 << "        " << bsTime;
	    LARGE_INTEGER LIB;
	    LARGE_INTEGER LIE;
	    LARGE_INTEGER FREQ;
	    QueryPerformanceFrequency(&FREQ);
	    QueryPerformanceCounter(&LIB);
		temp=BinSearch2(vec_1000000_seqs, i+1, 0, 999999);
	    QueryPerformanceCounter(&LIE);
	    double time=(double)(LIE.QuadPart-LIB.QuadPart)/((double)FREQ.QuadPart);
	    report << "          " <<  time << endl;
	}
	bsTime=0;
	report << endl;
	report << endl;
	report << "———————————————————" << endl; 
	report << endl;
	report << endl;
	//**************************************
	
	//-------------------------------------
	infile_1000000.close();
	//-------------------------------------

	//**************************************
    system("pause");
    return 0;
}