
#include <bits/stdc++.h>
using namespace std;


void findWaitingTime(int burst[],int arrival[], int n,
								int wt[])
{
	int rt[n];

	for (int i = 0; i < n; i++)
		rt[i] = burst[i];

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	while (complete != n) {

		for (int j = 0; j < n; j++) {
			if ((arrival[j] <= t) &&
			(rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		
		rt[shortest]--;

	 
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

	
		if (rt[shortest] == 0) {

		
			complete++;
			check = false;

			finish_time = t + 1;

		
			wt[shortest] = finish_time -
						burst[shortest] -
						arrival[shortest];

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		
		t++;
	}
}


void findTurnAroundTime(int burst[],int arrival[], int n,
						int wt[], int tat[])
{
	
	for (int i = 0; i < n; i++)
		tat[i] = burst[i] + wt[i];
}

void findavgTime(int burst[], int arrival[], int n)
{
	int wt[n], tat[n], total_wt = 0,
					total_tat = 0;

	findWaitingTime(burst,arrival, n, wt);

	findTurnAroundTime(burst,arrival, n, wt, tat);

	cout << "Processes "
		<< " Burst time "
		<< " Arrival time "
		<< " Waiting time "
		<< " Turn around time\n";

	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t"
			<< burst[i] << "  \t " << arrival[i] << "\t\t "<< wt[i]
			<< "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

int main()
{
	int burst[]={6,8,7,3};
	int arrival[]={1,1,2,3};
	int n = sizeof(burst) / sizeof(burst[0]);

	findavgTime(burst,arrival, n);
	return 0;
}

