#ifndef REPRO_CASE
# define REPRO_CASE 0
#endif

#if REPRO_CASE == 0
    import A;

#elif REPRO_CASE == 1
#   include <notmodule.hpp>

#elif REPRO_CASE == 2
    import A;
    import std;

#elif REPRO_CASE == 3
#   include <notmodule.hpp>
    import std;

#elif REPRO_CASE == 4
    import std;
    import A;

#endif


int main()
{
    A::X<int> x;
}
