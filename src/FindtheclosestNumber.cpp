#include <iostream>
#include <vector>
#include <cstdlib>

int CloseValue(int find,std::vector<int> x)
{
    int best;
    int counter = 0;
    int TestMinimal = find - x[0];

    for(auto& value : x)
    {
        
        if(abs(find - value) == 0)
        {
            best = counter;
        }      
        else
        {
            if(abs(find - value)<TestMinimal)
            {
                TestMinimal = abs(find - value);
                best = counter;
            }
        }
        
        counter +=1;
    }
    return x[best];
}


int main(int argc, char const *argv[])
{
    std::vector<int> v = {0,12,14,24,34,39,44,54,64,84,94,105};
    int find = 871;
    
    std::cout << CloseValue(find,v) << std::endl;
    
    return 0;
}
