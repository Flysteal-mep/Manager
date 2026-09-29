#include "test.hpp"

int main()
{
    std::string dbDir = ".Manager";
    std::string dbName = "data.json";

    if (!FoundDatabase(dbDir, dbName))
    {
        std::cout << "- No database found.\n";

        if (CreateDatabase(dbDir, dbName) == 0)
        {
            std::cout << "- Created database.\n";
        }
        else
        {
            std::cout << "- Failed to create database.\n";
            return 1;
        }
    }

    json db = LoadDatabase(dbDir + "/" + dbName);
    std::cout << "- Loaded: " << dbName << '\n';


    for (const auto& entry : std::filesystem::directory_iterator("."))
    {
        if (entry.path().extension() == ".png")
        {
            std::cout << entry.path() << '\n';
        }
    }
    /*
    find all files .png
    "files":
    [
        "exemple.png":{
            "date": 111120,
            "tags": "car"
        },
        "exemple2.png": {
            "date": 111220,
            "tags": "cat"
        }
    ]
    */

    return 0;
}
