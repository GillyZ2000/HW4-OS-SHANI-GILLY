
#include <unistd.h>

struct MallocMetadata {
    size_t size;
    bool is_free;      MallocMetadata* next;
    MallocMetadata* prev;
};

MallocMetadata* front = nullptr;
MallocMetadata* back = nullptr;

size_t _num_free_blocks(){
    size_t count = 0;
    MallocMetadata* curr = front;
    while(curr){
        if(curr->is_free)
        {
            count++;
        }
    }
    return count;
 }

size_t _num_free_bytes();


