#pragma once
#include <array>

namespace Heapsort{

    template <typename T, size_t SIZE>
    void downheap(std::array<T,SIZE> &a , size_t n , size_t v)
    {
        size_t w = (2*v)+1;
        while ( w < n )
        {
            if( w+1 < n )
                if( a[w+1] > a[w] )
                    w++;

            if( a[v] >= a[w] )
                return;

            std::swap(a[v],a[w]);
            v = w;
            w = (2*v)+1;
        }
    }

    template <typename T, size_t SIZE>
    void normal(std::array<T,SIZE> &a){
        size_t n = SIZE;

        // v >= 0 -> v < n because of size_t overflow
        for( size_t v = (n/2)-1; v < n ; v-- ){
            downheap(a,n,v);
        }

        while( n > 1 )
        {
            n--;
            std::swap(a[0],a[n]);
            downheap(a,n,0);
        }
    }
}
