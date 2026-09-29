#pragma once

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <filesystem>

using json = nlohmann::json;


bool FoundDatabase(const std::string& directory, const std::string& name)
{
    return std::filesystem::exists(
        std::filesystem::path(directory) / name
    );
}

int CreateDatabase(const std::string& directory, const std::string& name)
{
    json db;

    db["info"] =
    {
        {"date", 111126},
        {"version", 10102},
        {"last update", 121226}
    };

    std::filesystem::create_directories(directory);

    std::ofstream outFile(
        std::filesystem::path(directory) / name
    );

    if (!outFile)
    {
        return -1;
    }

    outFile << db.dump(4);

    return 0;
}

json LoadDatabase(const std::string& filePath)
{
    try
    {
        std::ifstream file(filePath);

        if (!file)
        {
            std::cout << "- Could not open database!\n";
            return {};
        }

        json db = json::parse(file);

        std::cout << "- Valid JSON!\n";

        return db;
    }
    catch (const json::parse_error& e)
    {
        std::cout << "- Invalid JSON: " << e.what() << '\n';
        return {};
    }
}
