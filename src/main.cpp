#include "methods.h"

int main() 
{

   std::vector<Item> items = readItemsFromFile("items_l.csv");
   std::vector<Item> sorted = countingSort(items, "age", true);
   writeItemsToFile("items_l_sorted.csv", sorted);
   calculateRarityScores(sorted, 50);
   writeItemsToFile("items_l_rarity.csv", sorted);
   sorted = heapSortByRarity(sorted, true);
   writeItemsToFile("items_l_rarity_sorted.csv", sorted);

  return 0;
}