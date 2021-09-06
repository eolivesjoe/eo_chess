#ifndef UTILITY_H
#define UTILITY_H

static bool assertIntegers(int a, int b) 
{
    bool outcome = true;
    if (!(a == b)) 
    {
        outcome = false;
        std::cerr << "-- Error in assert " << a << " and " << b << std::endl;
    }
    return outcome;
}

#endif // UTILITY_H