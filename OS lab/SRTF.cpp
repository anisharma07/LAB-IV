
// EXP2: Shortest Job First or Shortest Remaining Time First (SRTF)

#include <bits/stdc++.h>
using namespace std;

void findWaitingTime(int table[][3], int n,
                     int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = table[i][2];
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((table[j][1] <= t) &&
                (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time -
                           table[shortest][2] -
                           table[shortest][1];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(int table[][3], int n,
                        int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = table[i][2] + wt[i];
}

void findavgTime(int table[][3], int n)
{
    int wt[n], tat[n], total_wt = 0,
                       total_tat = 0;
    findWaitingTime(table, n, wt);
    findTurnAroundTime(table, n, wt, tat);
    cout << "Processes\t\t"
         << "AT\t\t"
         << "BT\t\t"
         << "WT\t\t"
         << "TAT\t\t\n";
    // total time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "P[" << table[i][0] << "]: "
             << "\t\t"
             << table[i][1] << "\t\t" << table[i][2] << "\t\t " << wt[i]
             << "\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
void printInputs(int Table[][3], int n)
{
    cout << "\nYour Inputs: ";
    cout << "\nProcesses \t"
         << "AT"
         << "\t\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: "
             << "\t\t" << Table[i][1] << "\t\t" << Table[i][2] << endl;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the Number of processes: ";
    cin >> n;
    int Table[n][3];
    cout << "Enter the Arrival time: " << endl;
    for (int i = 0; i < n; i++)
    {
        Table[i][0] = i + 1;
        cout << "P" << Table[i][0] << ": ";
        cin >> Table[i][1];
    }
    cout << "Enter the Burst time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> Table[i][2];
    }

    printInputs(Table, n);
    cout << "After Processing: " << endl;
    findavgTime(Table, n);
    return 0;
}
