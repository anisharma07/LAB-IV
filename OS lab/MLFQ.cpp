#include <iostream>

using namespace std;

struct Process
{
    int id;
    int priority;
    int burstTime;
};

void multilevelQueueScheduling(Process highPriorityQueue[], int highQueueSize, Process lowPriorityQueue[], int lowQueueSize)
{
    for (int i = 0; i < highQueueSize; ++i)
    {
        Process p = highPriorityQueue[i];
        cout << "Running Process ID: " << p.id << ", Priority: " << p.priority << ", Burst Time: " << p.burstTime << endl;
        p.burstTime--;
        if (p.burstTime == 0)
        {
            cout << "Process ID: " << p.id << " completed." << endl;
        }
        else
        {
            if (p.priority == 1)
            {
                highPriorityQueue[i] = p;
            }
            else
            {
                lowPriorityQueue[i] = p;
            }
        }
    }

    for (int i = 0; i < lowQueueSize; ++i)
    {
        Process p = lowPriorityQueue[i];
        cout << "Running Process ID: " << p.id << ", Priority: " << p.priority << ", Burst Time: " << p.burstTime << endl;
        p.burstTime--;
        if (p.burstTime == 0)
        {
            cout << "Process ID: " << p.id << " completed." << endl;
        }
        else
        {
            if (p.priority == 1)
            {
                highPriorityQueue[i] = p;
            }
            else
            {
                lowPriorityQueue[i] = p;
            }
        }
    }
}

int main()
{
    const int highQueueSize = 2;
    const int lowQueueSize = 2;
    Process highPriorityQueue[highQueueSize] = {{1, 1, 3}, {2, 1, 2}};
    Process lowPriorityQueue[lowQueueSize] = {{3, 2, 4}, {4, 2, 5}};

    multilevelQueueScheduling(highPriorityQueue, highQueueSize, lowPriorityQueue, lowQueueSize);

    return 0;
}