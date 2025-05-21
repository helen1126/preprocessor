#ifndef REGEX_ENGINE_H
#define REGEX_ENGINE_H

#include <vector>
#include <string>

// Define the struct to hold attribute-weight pairs
struct AttributeWeight {
    std::string attribute;  // Attribute name (e.g., "Çé¸Ð")
    double weight;          // Weight value (e.g., 0.75)
};

class RegexEngine {
public:
    std::vector<AttributeWeight> parse(const std::string& input);
};

#endif // REGEX_ENGINE_H