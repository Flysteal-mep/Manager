#include <iostream>
#include <fstream>
#include <exception>
#include <filesystem>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


int main()
{
    std::cout << "- Current path set to: " << std::filesystem::current_path() << '\n';

// {
    if (!std::filesystem::exists(".Manager"))
    {
        std::cerr << "= Failed to find database folder\n";
        return -1;
    }

    if (!std::filesystem::exists(".Manager/database.json"))
    {
        std::cerr << "= Failed to find database file\n";
        return -1;
    }

    std::cout << "- Found database\n";
// }

    json db;

// {
    std::ifstream file(".Manager/database.json");

    if (!file.is_open())
    {
        std::cerr << "= Failed to open database\n";
        return -1;
    }

    try
    {
        db = json::parse(file);
        std::cout << "- Valid JSON database\n";
    }
    catch (const json::parse_error& e)
    {
        std::cout << "= Invalid JSON: \n\t" << e.what() << '\n';
        return -1;
    }

    file.close();
// }

// {

    db["info"] =
    {
        {"date", 101010}
    };
    db["files"] = json::array();

    // count system files & index
    for (const auto& entry : std::filesystem::directory_iterator("."))
    {
        if (entry.is_regular_file())
        {
            db["files"].push_back(
            {
                {
                    "name", entry.path().stem().string()
                },
                {
                    "path", entry.path()
                },
                {
                    "size", entry.file_size()
                },
                {
                    "tags",
                    {
                        entry.path().extension(),
                        
                    }
                }
            });
        }
    }

    // compare db files
    // update new files
// }

// {
    // save the changes
    std::ofstream out_file(".Manager/database.json");

    if (!out_file.is_open())
    {
        std::cerr << "= Failed to save database\n";
        return -1;
    }

    out_file << db.dump(4);
// }

    return 0;
}
