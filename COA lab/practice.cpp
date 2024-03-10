#include <iostream>
#include <bitset>

// Function to perform n-bit parallel subtraction
std::bitset<32> nBitParallelSubtract(const std::bitset<32> &a, const std::bitset<32> &b)
{
    // Ensure a and b are of the same size
    if (a.size() != b.size())
    {
        throw std::invalid_argument("Input bitsets must have the same size");
    }

    std::bitset<32> result;
    bool borrow = false;

    // Perform subtraction bit by bit
    for (int i = 0; i < a.size(); ++i)
    {
        // XOR the bits and the borrow
        result[i] = a[i] ^ b[i] ^ borrow;

        // Update the borrow for the next iteration
        borrow = (a[i] & borrow) | (b[i] & borrow) | (a[i] & b[i]);
    }

    return result;
}

int main()
{
    // Example usage
    std::bitset<32> num1("110110");
    std::bitset<32> num2("101001");

    std::bitset<32> result = nBitParallelSubtract(num1, num2);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
