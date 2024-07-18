#pragma once

// Macro to check for null pointer and use the given pointer name for the thrown exception.
#define CHECK_NULLPTR(ptr) \
    if ((ptr) == nullptr) \
    { \
        throw std::invalid_argument(#ptr " cannot be a null pointer."); \
    }

// Function to get the current time as a string.
inline std::string CurrentTime() 
{
    // Has a needed buffe size of [26].
    time_t now = time(nullptr);

    // Increase buffer size to [27] for formatting reasons.
    char buf[27];
    ctime_s(buf, sizeof(buf), &now);

    // Custom formatting.
    buf[24] = ':'; // Normally '\n'.
    buf[25] = ' '; // Normally '\0'.
    buf[26] = '\0'; // Supplement null terminator.

    return std::string(buf);
}
