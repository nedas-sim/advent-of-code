#include <iostream>
#include <string>

using namespace std;

int getNextCommaIndex(string input, int prevCommaIndex);
int getNumberAtIndex(string input, int index);
int getIntDigit(char c);

int main()
{
    string input = "forward 5,down 5,forward 8,up 3,down 8,forward 2";
    
    int position = 0;
    int depth = 0;
    
    int nextCommaIndex = -1;
    bool endOfString = false;
    while (false == endOfString)
    {
        int currentIndex = nextCommaIndex;
        nextCommaIndex = getNextCommaIndex(input, currentIndex);
        if (nextCommaIndex < -1)
        {
            nextCommaIndex = input.length();
            endOfString = true;
        }
        
        char command = input[currentIndex + 1];
        int value = getNumberAtIndex(input, nextCommaIndex);
        
        if (command == 'f')
        {
            position += value;
        }
        else if (command == 'd')
        {
            depth += value;
        }
        else if (command == 'u')
        {
            depth -= value;
        }
    }
    
    cout << position * depth << endl;
    
    return 0;
}

int getNumberAtIndex(string input, int index)
{
    char val1 = input[index - 2];
    char val2 = input[index - 1];
    
    bool foundNonDigit = false;
    int indexFromComma = 1;
    int accumulated = 0;
    int multiplier = 1;
    while (true)
    {
        char c = input[index - indexFromComma];
        int digit = getIntDigit(c);
        if (digit < 0)
        {
            break;
        }
        
        accumulated += (digit * multiplier);
        multiplier *= 10;
        indexFromComma++;
    }
    
    return accumulated;
}

int getIntDigit(char c)
{
    if (c >= 48 && c <= 57)
    {
        return c - 48;
    }
    
    return -1;
}

int getNextCommaIndex(string input, int prevCommaIndex)
{
    for (int index = prevCommaIndex + 1; index < input.length(); index++)
    {
        if (input[index] == ',')
        {
            return index;
        }
    }
    
    return -100;
}