#pragma once

#include <boost/unordered/unordered_flat_map.hpp>

namespace A
{
    template<class T>
    struct X
    {
        boost::unordered::unordered_flat_map< int, T > extensions;
    };
}
