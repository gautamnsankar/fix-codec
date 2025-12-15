#include "codec.hpp"

int main() {
    // sample string taken from https://ref.onixs.biz/fix-message.html
    FixDecoder d("8=FIX.4.2\0019=118\00135=D\00149=ONIXS\00156=CME\00134=2\00152=20240528-09:20:52.111\00111=983532-3\00121=1\00138=100\00155=NVDA\00140=1\00154=1\00160=20240528-09:20:52.004\00110=017\001");
    std::unordered_map<u_int8_t, std::string> result = d.decode();

    std::cout << result.at(5) << '\n';
    return 0;
}
