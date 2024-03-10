// MultiLevel Feedback queue...

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process
{
    int id;
    int priority;
    int burst_time;
};

void multilevelQueueScheduling(vector<queue<Process>> &queues, int quantum)
{
    int currentTime = 0;

    for (int i = 0; i < queues.size(); ++i)
    {
        while (!queues[i].empty())
        {
            Process currentProcess = queues[i].front();
            queues[i].pop();

            for (int j = 0; j < quantum && currentProcess.burst_time > 0; ++j)
            {
                cout << "Time " << currentTime << ": Executing Process " << currentProcess.id << " from Queue " << currentProcess.priority << endl;
                currentTime++;
                currentProcess.burst_time--;
            }

            if (currentProcess.burst_time > 0)
            {
                currentProcess.priority = min(currentProcess.priority + 1, static_cast<int>(queues.size()) - 1);
                queues[currentProcess.priority].push(currentProcess);
            }
        }
    }
}

int main()
{
    int numQueues = 3;

    int quantum = 2;

    vector<queue<Process>> queues(numQueues);

    vector<Process> processes = {
        {1, 0, 8},
        {2, 1, 6},
        {3, 2, 10},
        {4, 0, 4},
        {5, 1, 8}};

    for (const Process &process : processes)
    {
        queues[process.priority].push(process);
    }

    multilevelQueueScheduling(queues, quantum);

    return 0;
}
