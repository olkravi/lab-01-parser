// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include "header.hpp"
#include <iostream>
#include <string>
#include <any>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

TEST(Parse, Text){
Json object("{\n"
                   "    \"lastname\" : \"Ivanov\",\n"
                   "    \"firstname\" : \"Ivan\",\n"
                   "    \"age\" : 25,\n"
                   "    \"islegal\" : false,\n"
                   "    \"marks\" : [\n"
                   "    \t4,5,5,5,2,3\n"
                   "    ],\n"
                   "    \"address\" : {\n"
                   "    \t\"city\" : \"Moscow\",\n"
                   "        \"street\" : \"Vozdvijenka\"\n"
                   "    }\n"
                   "}");
//Json object = Json::parse(json);
EXPECT_EQ(std::any_cast<std::string>(object["lastname"]),
"Ivanov");
EXPECT_EQ(std::any_cast<bool>(object["islegal"]),
false);
EXPECT_EQ(std::any_cast<int>(object["age"]),
25);

auto marks = std::any_cast<Json>(object["marks"]);
EXPECT_EQ(std::any_cast<int>(marks[0]),
4);
EXPECT_EQ(std::any_cast<int>(marks[1]),
5);

auto address = std::any_cast<Json>(object["address"]);
EXPECT_EQ(std::any_cast<std::string>(address["city"]),
"Moscow");
EXPECT_EQ(std::any_cast<std::string>(address["street"]),
"Vozdvijenka");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
