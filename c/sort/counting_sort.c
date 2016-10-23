#include <stdio.h>
#include <string.h>

void csort(unsigned max, unsigned size, const unsigned src[size], unsigned dst[size])
{
    unsigned count[max];
    memset(count, 0, sizeof(unsigned) * max);
    for (size_t i = 0; i < size; ++i)
        ++count[src[i]];
    for (size_t i = 0, v = 0; v <= max;)
        count[v]-- ? dst[i++] = v : ++v;
}


int main(void)
{
    unsigned src[] = {2, 0, 7, 3, 9, 7, 4, 5, 5, 8, 2, 6, 1, 5, 2};
    unsigned dst[sizeof(src) / sizeof(unsigned)];
    
    csort(10, sizeof(src) / sizeof(unsigned), src, dst);
    
    for (size_t i = 0; i < sizeof(src) / sizeof(unsigned); ++i) {
        printf("%lu: %u\n", i, dst[i]);
    }
    
    return 0;
}