#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    std::cout << "Initial capacity: " << v.capacity() << std::endl;

    for (int i = 0; i < 10000; ++i)
    {
        v.push_back(i);

        if (v.capacity() != v.size())
        {
            std::cout << "Capacity increased to: " << v.capacity() << std::endl;
        }
    }

    v.reserve(20000);

    std::cout << "Capacity after reserve: " << v.capacity() << std::endl;

    try
    {
        v.reserve(1000000000);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

/*
Output:

Initial capacity: 0
Capacity increased to: 1
Capacity increased to: 2
Capacity increased to: 4
Capacity increased to: 8
Capacity increased to: 16
Capacity increased to: 32
Capacity increased to: 64
Capacity increased to: 128
Capacity increased to: 256
Capacity increased to: 512
Capacity increased to: 1024
Capacity increased to: 2048
Capacity increased to: 4096
Capacity increased to: 8192
Capacity increased to: 16384
Capacity increased to: 32768
Capacity increased to: 65536
Capacity increased to: 131072
Capacity increased to: 262144
Capacity increased to: 524288
Capacity increased to: 1048576
Capacity increased to: 2097152
Capacity increased to: 4194304
Capacity increased to: 8388608
Capacity increased to: 16777216
Capacity increased to: 33554432
Capacity increased to: 67108864
Capacity increased to: 134217728
Capacity after reserve: 20000
Exception caught: std::bad_alloc
Наблюдения:
При нехватке памяти емкость вектора увеличивается в два раза
Если емкость устанавливается вручную, то она увеличивается на разность устновленной и текущей
Если емкость вектора больше, чем та, которую мы установили, то емкость вектора не будет уменьшаться до установленного значения
Если запрашивается очень большой объем памяти, то выдается исключение (std::bad_alloc)
