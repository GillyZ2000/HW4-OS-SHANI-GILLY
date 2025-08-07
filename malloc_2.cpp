
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
        curr = curr->next;
    }
    return count;
 }

size_t _num_free_bytes(){
    size_t count = 0;
    MallocMetadata* curr = front;
    while(curr){
        if(curr->is_free)
        {
            count+= curr->size;
        }
        curr = curr->next;
    }
    return count;
}

size_t _num_allocated_blocks(){
    size_t count = 0;
    MallocMetadata* curr = front;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}

size_t _num_allocated_bytes(){
    size_t count = 0;
    MallocMetadata* curr = front;
    while(curr){
        count+= curr->size;
        curr = curr->next;
    }
    return count;
}

size_t _num_meta_data_bytes(){
    return _num_allocated_blocks()*sizeof(MallocMetadata);
}

size_t _size_meta_data(){
    return sizeof(MallocMetadata);
}


