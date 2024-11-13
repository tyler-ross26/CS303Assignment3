#pragma once
#include <vector>

// Function to perform linear search and return the last occurrence of the target element
int linear_search(const std::vector<int>& items, int target, std::size_t pos_first = 0) {
    if (pos_first == items.size()) {
        return -1;  // Return -1 if the target is not found
    }

    int result = linear_search(items, target, pos_first + 1);  // Recurse to the next element

    if (result != -1) {
        return result;  // Return result if target is found in the recursion
    }

    if (items[pos_first] == target) {
        return pos_first;  // Return the position if target is found at this index
    }

    return -1;  // Return -1 if the target is not found
}
