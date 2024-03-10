// Simulate memory allocation algorithms (First Fit, Best Fit and worst fit)
#include <iostream>
#include <vector>

using namespace std;

struct MemoryBlock
{
    int start;
    int end;
    int process_id;
};

class MemoryAllocation
{
private:
    int size;
    vector<MemoryBlock> memory_blocks;

public:
    MemoryAllocation(int initial_size) : size(initial_size)
    {
        memory_blocks.push_back({0, size, -1}); // Initialize with a single free block
    }

    void displayMemory()
    {
        cout << "Memory Allocation:" << endl;
        for (const auto &block : memory_blocks)
        {
            cout << "Start: " << block.start << ", End: " << block.end << ", ProcessID: " << block.process_id << endl;
        }
    }

    bool firstFit(int process_id, int process_size)
    {
        for (auto &block : memory_blocks)
        {
            int block_size = block.end - block.start;
            if (block_size >= process_size && block.process_id == -1)
            {
                block.process_id = process_id;
                return true;
            }
        }
        return false;
    }

    bool bestFit(int process_id, int process_size)
    {
        MemoryBlock *best_fit_block = nullptr;

        for (auto &block : memory_blocks)
        {
            int block_size = block.end - block.start;
            if (block_size >= process_size && (best_fit_block == nullptr || block_size < best_fit_block->end - best_fit_block->start))
            {
                best_fit_block = &block;
            }
        }

        if (best_fit_block != nullptr)
        {
            best_fit_block->process_id = process_id;
            return true;
        }

        return false;
    }

    bool worstFit(int process_id, int process_size)
    {
        MemoryBlock *worst_fit_block = nullptr;

        for (auto &block : memory_blocks)
        {
            int block_size = block.end - block.start;
            if (block_size >= process_size && (worst_fit_block == nullptr || block_size > worst_fit_block->end - worst_fit_block->start))
            {
                worst_fit_block = &block;
            }
        }

        if (worst_fit_block != nullptr)
        {
            worst_fit_block->process_id = process_id;
            return true;
        }

        return false;
    }
};

int main()
{
    MemoryAllocation memoryAllocator(100);

    // Processes with their respective memory requirements
    vector<pair<int, int>> processes = {{1, 20}, {2, 30}, {3, 10}, {4, 15}};

    // First Fit
    for (const auto &process : processes)
    {
        if (!memoryAllocator.firstFit(process.first, process.second))
        {
            cout << "Process " << process.first << " could not be allocated in First Fit." << endl;
        }
    }

    memoryAllocator.displayMemory();

    // Reset memory for the next simulations
    memoryAllocator = MemoryAllocation(100);

    // Best Fit
    for (const auto &process : processes)
    {
        if (!memoryAllocator.bestFit(process.first, process.second))
        {
            cout << "Process " << process.first << " could not be allocated in Best Fit." << endl;
        }
    }

    memoryAllocator.displayMemory();

    // Reset memory for the next simulations
    memoryAllocator = MemoryAllocation(100);

    // Worst Fit
    for (const auto &process : processes)
    {
        if (!memoryAllocator.worstFit(process.first, process.second))
        {
            cout << "Process " << process.first << " could not be allocated in Worst Fit." << endl;
        }
    }

    memoryAllocator.displayMemory();

    return 0;
}
