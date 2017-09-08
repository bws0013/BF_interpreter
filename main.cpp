#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

#include "bf.h"

using namespace std;

int main()
{
    vector<int> res;
   
    // Enter the code you want interpreted below in the interprete function. 
    res = interprete("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    
    
    for (auto i : res)
        std::cout << (char)i << " ";
    
    
    return 0;
}