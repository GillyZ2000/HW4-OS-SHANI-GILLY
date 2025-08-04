


#include <unistd.h>
#define MAX_SIZE 100000000

void* smalloc(size_t size) {
    if(size==0 || size > MAX_SIZE){
        return NULL;
    }
    void* val = sbrk(size);
    if(val == (void*)(-1)){
        return NULL;
    }
    return val;
}