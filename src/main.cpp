#include <iostream>
#include <fstream>
#include <exception>
#include <filesystem>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


int main()
{
    std::cout << "- Curret path set to: " << std::filesystem::current_path() << '\n';

// normal db check
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

// check the database strucure and inegrity
// {
    std::ifstream file(".Manager/database.json");

    if (!file.is_open())
    {
        std::cerr << "= Failed to open database\n";
        return -1;
    }

    try
    {
        json db = json::parse(file);
        std::cout << "- Valid JSON database\n";
    }
    catch (const json::parse_error& e)
    {
        std::cout << "= Invalid JSON: \n\t" << e.what() << '\n';
        return -1;
    }

    file.close();
// }

// do a filechek ( if the db files are in the path and if new files )
// {
    // count db files
    // count sysrem files

    // index
    // update new files
// }

// {
    // save the changes
// }

    return 0;
}
