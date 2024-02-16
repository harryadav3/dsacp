#include <iostream>
#include <cmath>

// Function to convert decimal to binary
long long decimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1;
    while (n != 0) {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

// Function to reverse a number
long long reverseNumber(long long n) {
    long long reversedNumber = 0;
    while (n != 0) {
        reversedNumber = reversedNumber * 10 + n % 10;
        n /= 10;
    }
    return reversedNumber;
}

// Function to convert binary to decimal
int binaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

int main() {
    int decimalInput;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalInput;

    // Convert decimal to binary
    long long binary = decimalToBinary(decimalInput);

    // Reverse the binary number
    long long reversedBinary = reverseNumber(binary);

    // Convert reversed binary to decimal
    int decimalOutput = binaryToDecimal(reversedBinary);

    std::cout << "Decimal number after flipping its binary representation: " << decimalOutput << std::endl;

    return 0;
}
