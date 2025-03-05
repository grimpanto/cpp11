
#include <iostream>

using T = std::string;

#include "record.h"

T get_id(Record* ptr) {
    return ptr->id;
}
