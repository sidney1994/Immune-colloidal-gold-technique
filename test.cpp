#include<iostream>
#include<fstream>
using namespace std;
double data[1024];//数组长度
int count;

void readdata(const char  *file)
{
	char buf[128];
	int i = 0;
	FILE *fp;
	fp = fopen(file, "r");

	while (fgets(buf, sizeof(buf), fp)) {
		sscanf(buf, "%lf ", &data[i]);
		i ++;
	}
	count = i;
	fclose(fp);
}
int main()
{

readdata("F:\\C++程序\\test\\uniform\\uniform\\file.txt");
int i;
//for(i=0;i<60;i++)
//cout<<data[i]<<endl;
//定义基线
double baseline1;
double baseline2;
double baseline3;
//定义t线1、t线2、c线开始和结束扫描的时间
int t1begin,t2begin;
int cbegin,t1end;
int t2end,cend;
//截取t线1，t线2，c线的光谱强度
t1begin=2;
t1end=10;
t2begin=13;
t2end=15;
double t1area=0;
double t2area=0;
double t3area=0;
int j;
double time=1;//假设时间间隔是1
for (j=t1begin;j<t1end;j++){
	cout<<data[j]<<endl;
	//area1=data[j]*1+area1;//矩形公式
    t1area=0.5*(data[j]+data[j+1])*time+t1area;//梯形公式
    cout<<t1area<<endl;}
for (j=t2begin;j<t2end;j++){
	cout<<data[j]<<endl;
	//area1=data[j]*1+area1;//矩形公式
	t2area=0.5*(data[j]+data[j+1])*time+t2area;//梯形公式
	cout<<t2area<<endl;}

return 0;
}
