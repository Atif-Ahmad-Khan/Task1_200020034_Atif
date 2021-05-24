#include<fstream.h>
struct Groundwork {
	int stime, dur, ftime;
};
struct Available_Groundworks {
	int n;
	Groundwork g[100];
};
Available_Groundworks* initialize(int start_time[], int duration[], int n) {
	Available_Groundworks *h=new Available_Groundworks;
	for (int i = 0; i < n; i++)
	{
		h->g[i].stime = start_time[i];
		h->g[i].dur = duration[i];
	}
	return h;
}
int CalculateMaxGroundworks(Available_Groundworks* ptr) {
	sort(ptr->g[0].stime, ptr->g[n - 1].stime);
	int k = 1;
	int r1 = ptr->g[0].stime + ptr->g[0].dur;

	for (int i = 1; i < n; i++) {
		int l1 = ptr->g[i].stime;
		int r2 = ptr->g[i].stime + ptr->g[i].dur;
		if (l1 > r1) {
			k++;
			r1 = r2;
		}
	}
	return k;
}
void main{
	int s[100], d[100], i = j = 0;
ifstream IN;
IN.open("Schedule.txt", ios::in);
if (!IN) {
	cout << "No such file";
}
else {
	int ch;
	int sd = 1;
	while (1) {
		IN >> ch;
		if (IN.eof())
			break;
		if (sd % 3 == 1) {
			s[i] = ch; i++;
		}
		if (sd % 3 == 2) {
			d[i] = ch; j++;
		}
	}


IN.close();
cout << CalculateMaxGroundworks(initialize(s, d, i));


}
}