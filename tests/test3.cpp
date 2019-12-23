//Copyright 2018 Your name <your_email>
#include <gtest/gtest.h>
#include <json.hpp>

using json = nlohmann::json;

TEST(Json_for_modern, parse_){
nlohmann::json outputJson;
    auto j3 = json::parse("[\n"
                          "    [\"Si-9.15\", \"RTS-9.15\", \"GAZP-9.15\"],\n"
                          "    [100024, 100027, 100050],\n"
                          "    [\"Futures contract for USD/RUB\", "
                          "\"Futures contract for index RTS\", "
                          "\"Futures contract for Gazprom shares\"]\n"
                          "]");
    uint64_t tmp;

    for (uint64_t i = 0; i < j3[0].size(); ++i) {
        tmp = 0;
        while (tmp < j3.size()) {
            outputJson.push_back(
                    nlohmann::json
                            {
                                    {"ticker",      j3[tmp++][i]},
                                    {"id",          j3[tmp++][i]},
                                    {"description", j3[tmp++][i]},
                            });
        }
    }
    std::cout << outputJson;
}
