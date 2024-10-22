#include "sort.h"

#include <ctype.h>
#include <stddef.h>

bool is_sorted(void* array, size_t array_size, size_t size,
    bool (*compare)(const void*, const void*))
{
    lassert(array, "");

    for (int i = 0; i < array_size - 1; ++i) {
        if (!compare(array + i * size, array + (i + 1) * size)) {
            return false;
        }
    }

    return true;
}

void swap(void* ptr1, void* ptr2, size_t size)
{
    lassert(ptr1, "");
    lassert(ptr1, "");

    int idx = 0;
    void* ptr_tmp = malloc(size);
    void* ptr_start = ptr_tmp;
    for (; idx < size / 8; ++idx) {
        memcpy(ptr_tmp, ptr1, 8);
        memcpy(ptr2, ptr1, 8);
        memcpy(ptr1, ptr_tmp, 8);
        ptr1 += 8;
        ptr2 += 8;
        ptr_tmp += 8;
    }
    size %= 8;
    for (; idx < size / 4; ++idx) {
        memcpy(ptr_tmp, ptr1, 8);
        memcpy(ptr2, ptr1, 8);
        memcpy(ptr1, ptr_tmp, 8);
        ptr1 += 4;
        ptr2 += 4;
        ptr_tmp += 4;
    }
    size %= 4;
    for (; idx < size / 2; ++idx) {
        memcpy(ptr_tmp, ptr1, 8);
        memcpy(ptr2, ptr1, 8);
        memcpy(ptr1, ptr_tmp, 8);
        ptr1 += 2;
        ptr2 += 2;
        ptr_tmp += 2;
    }
    size %= 2;
    for (; idx < size; ++idx) {
        memcpy(ptr_tmp, ptr1, 8);
        memcpy(ptr2, ptr1, 8);
        memcpy(ptr1, ptr_tmp, 8);
        ptr1 += 1;
        ptr2 += 1;
        ptr_tmp += 1;
    }

    return;
}

sorted_state Text_sort(Text* text)
{
    lassert(text, "");

    for (int i = 0; i < text->text_size; ++i) {
        for (int j = i + 1; j < text->text_size; ++j) {
            if (!Text_strcmp(text->text[i], text->text[j])) {
                swap(text->text[i], text->text[j], 30);
            }
        }
    }
}