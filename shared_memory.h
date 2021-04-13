#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define TEXT_SZ 2048

struct common_mem{
    int flag; //lets the reading process know if there is a new value set
    char some_text[TEXT_SZ]; //the value to read/write to
};

#endif
