#ifndef TEMPLATETEST1_H
#define TEMPLATETEST1_H

template<int N>
class SumTestInt
{
public:
    SumTestInt()
    {
        sum = 0;
        SumTestInt<N-1> t;
        sum = t.getSum() + N;
    }

    int num()
    {
        return N;
    }

    int getSum()
    { return sum; }

private:
    int sum;
};

template<>
class SumTestInt<0>
{
public:
    SumTestInt()
    {

    }

    int num()
    {
        return 0;
    }

    int getSum()
    { return 0; }
};

#endif // TEMPLATETEST1_H
