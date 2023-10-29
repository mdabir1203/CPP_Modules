#include "BitcoinExchange.hpp"
#include <fstream>


// -> Input file -> Each line is new data point added to bcX -> Add to queue
 // -> Queue helps process the data points in order they were read from input file -> maintain integrity
int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << error_msg[NOT_OPEN_FILE]  << std::endl;
        return 0;
    }
    std::queue<BitcoinExchange> a;
    std::ifstream f(av[1]);
    if (!f.is_open())
    {
        std::cout << error_msg[FILE_NOT_FOUND] << std::endl;
        return 0;
    }
    std::string line;
    while(getline(f, line))
    {
        if (line.size() == 0 || line[0] == 'd')
            continue;
        BitcoinExchange b(line);
        a.push(b);
    }
    while(!a.empty())
    {
        
        a.pop();
    }
}