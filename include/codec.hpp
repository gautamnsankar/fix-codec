#include <unordered_map>
#include <iostream>
#include <cstring>
#include <vector>

class FixDecoder {
    private:
    std::vector<std::string> split(std::string target, char delimiter) {
        std::string accumulated_string = "";
        std::vector<std::string> result;

        for (int i = 0; i < target.size() + 1; ++i) {
            if (target[i] == delimiter || i == target.size()) {
                result.push_back(accumulated_string);
                accumulated_string = "";
                continue;
            }

            accumulated_string += target[i];
        }

        return result;
    }

    const char* message;

    public:
    FixDecoder(const char* _message) {
        this->message = _message;
    }

    std::unordered_map<u_int8_t, std::string> decode() {
        std::unordered_map<u_int8_t, std::string> result;
        std::string accumulated_string = "";

        for (size_t i = 0; i < strlen(message); ++i) {
            char current_character = message[i];

            if (current_character == '\x01') {
                std::vector<std::string> split_string = split(accumulated_string, '=');
                std::string key_string = split_string[0];
                std::string value_string = split_string[1];

                result.insert(std::pair<u_int8_t, std::string>((u_int8_t) std::stoi(key_string), value_string));

                accumulated_string = "";
                continue;
            }

            accumulated_string += current_character;
        }

        return result;
    }
};
