#include "test.h"
#include <iostream>
#include <fstream>


int main()
{
    std::ofstream file;
    file.open("temp/test.txt");

    if (!file.is_open())
    {
        return -1;
    }

    file << "mep ._.";

    file.close();

    return 0;
}
