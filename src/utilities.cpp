#include "methods.h"

std::vector<Item> readItemsFromFile(const std::string& filename) 
{
    std::vector<Item> items;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the fileeee" << std::endl;
        exit(-1);
    }


    std::string line;

    getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string age, type, origin, rarityScore;
        getline(ss, age, ',');
        getline(ss, type, ',');
        getline(ss, origin, ',');
        getline(ss, rarityScore, ',');
        Item item;
        item.age = std::stoll(age);
        item.type = std::stoi(type);
        item.origin = std::stoi(origin);
        item.rarityScore = std::stod(rarityScore);
        items.push_back(item);

    }

    file.close();
    return items;



}

void writeItemsToFile(const std::string& filename, const std::vector<Item>& items) 
{
    std::ofstream results(filename);

    if (!results.is_open()) {
        std::cerr << "Error opening the fileö" << std::endl;
        exit(-1);
    }

results << "age,type,origin,rarity\n";

    for (const auto &item: items) {
        results << item.age << ',';
        results << item.type << ',';
        results << item.origin << ',';
        results << item.rarityScore << '\n';
    }

   results.close();

}
