#include <unordered_map>
#include <iostream>
#include <cassert>
#include <vector>

// I just defined it manually rather than importing a whole library for it
typedef unsigned char uint8_t;

std::vector<std::string> split_string_(std::string target, char delimiter) {
    std::string accumulated_string = "";
    std::vector<std::string> result;

    for (int i = 0; i < target.size() + 1; ++i) {
        char current_character = target[i];

        if (current_character == delimiter || i == target.size()) {
            result.push_back(accumulated_string);
            accumulated_string.clear();
            continue;
        }

        accumulated_string += current_character;
    }

    return result;
}

std::unordered_map<uint8_t, std::string> decode_fix(const char* message) {
    assert(message != nullptr);

    std::vector<std::string> split_fix_message = split_string_(message, '\001');
    std::unordered_map<uint8_t, std::string> result;

    for (int i = 0; i < split_fix_message.size(); ++i) {
        std::vector<std::string> split_kv_pair = split_string_(split_fix_message[i], '=');

        if (split_kv_pair[0] == "") {
            continue; // theres probably a better way to do this
        }

        result.insert(std::pair<uint8_t, std::string>((uint8_t) std::stoi(split_kv_pair[0]), split_kv_pair[1]));
    }

    return result;
}