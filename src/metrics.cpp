#include "methods.h"

int getMax(std::vector<Item> &items, const std::string &attribute) {
    int M=0;
    if (attribute == "age") {
        for (int i = 0; i < items.size(); i++) {
            int currentValue = items[i].age;
            if (currentValue > M) {
                M = currentValue;
            }
        }
    } else if (attribute == "type") {
        for (int i = 0; i < items.size(); i++) {
            int currentValue = items[i].type;
            if (currentValue > M) {
                M = currentValue;
            }
        }
    } else if (attribute == "origin") {
        for (int i = 0; i < items.size(); i++) {
            int currentValue = items[i].origin;
            if (currentValue > M) {
                M = currentValue;
            }
        }
    } else if (attribute == "rarityScore") {
        for (int i = 0; i < items.size(); i++) {
            int currentValue = items[i].rarityScore;
            if (currentValue > M) {
                M = currentValue;
            }
        }
    } else {
        std::cerr << "Invalid attribute" << std::endl;
        exit(-1);
    }
    return M;
}

// min = age - ageWindow
// max = age + ageWindow
// rarityScore = (1 - probability) * (1 + item.age/ageMax)
void calculateRarityScores(std::vector<Item> &items, int ageWindow) {
    double countSimilar = 0.0;
    double countTotal = 0.0;
    double probability;
    double rarityScore;
    int ageMax = getMax(items, "age");
    for (int i = 0; i < items.size();i++) {
        int age = items[i].age;
        int type = items[i].type;
        int origin = items[i].origin;
        double min = age - ageWindow;
        double max = age + ageWindow;

        for (int j = 0; j < items.size(); j++) {
            if (items[j].age >= min && items[j].age <= max) {
                countTotal++;
                if (items[j].type == type && items[j].origin == origin) {
                    countSimilar++;
                }
            }
            if(countTotal>0.0){
                probability = countSimilar/countTotal;

            } else {
                probability = 0.0;
            }

            rarityScore = (1 - probability) * (1 + items[j].age/(double)ageMax);
            items[j].rarityScore = rarityScore;
        }

    }




}
