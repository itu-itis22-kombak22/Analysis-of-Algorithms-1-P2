#include "methods.h"

std::vector<Item> countingSort(std::vector<Item> &items, const std::string &attribute, bool ascending) {
    int S = items.size();
    if (S == 0) {
        return items;
    }
    std::vector<Item> output_array(S);
    int M = 0;
    if (attribute == "age") {

        M = getMax(items, "age");


        std::vector<int> count_array(M + 1, 0);
        for (int i = 0; i < S; i++) {
            count_array[items[i].age]++;
        }
        for (int i = 1; i <= M; i++) {
            count_array[i] += count_array[i - 1];
        }

        if (ascending) {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].age;
                output_array[count_array[attrValue] - 1] = items[i];
                count_array[attrValue]--;

            }
        } else {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].age;
                output_array[S - count_array[attrValue]] = items[i];
                count_array[attrValue]--;

            }
        }


    } else if (attribute == "rarityScore") {

        M = getMax(items, "rarityScore");

        std::vector<int> count_array(M + 1, 0);
        for (int i = 0; i < S; i++) {
            count_array[items[i].rarityScore]++;
        }
        for (int i = 1; i <= M; i++) {
            count_array[i] += count_array[i - 1];
        }

        if (ascending) {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].rarityScore;
                output_array[count_array[attrValue] - 1] = items[i];
                count_array[attrValue]--;

            }
        } else {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].rarityScore;
                output_array[S - count_array[attrValue]] = items[i];
                count_array[attrValue]--;

            }
        }


    } else if (attribute == "type") {

       M = getMax(items, "type");

        std::vector<int> count_array(M + 1, 0);
        for (int i = 0; i < S; i++) {
            count_array[items[i].type]++;
        }
        for (int i = 1; i <= M; i++) {
            count_array[i] += count_array[i - 1];
        }

        if (ascending) {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].type;
                output_array[count_array[attrValue] - 1] = items[i];
                count_array[attrValue]--;

            }
        } else {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].type;
                output_array[S - count_array[attrValue]] = items[i];
                count_array[attrValue]--;

            }
        }

    } else if (attribute == "origin") {

        M = getMax(items, "origin");

        std::vector<int> count_array(M + 1, 0);
        for (int i = 0; i < S; i++) {
            count_array[items[i].origin]++;
        }
        for (int i = 1; i <= M; i++) {
            count_array[i] += count_array[i - 1];
        }

        if (ascending) {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].origin;
                output_array[count_array[attrValue] - 1] = items[i];
                count_array[attrValue]--;

            }
        } else {
            for (int i = S - 1; i >= 0; i--) {
                int attrValue = items[i].origin;
                output_array[S - count_array[attrValue]] = items[i];
                count_array[attrValue]--;
            }
        }
    } else {
        std::cout << "Invalid attribute name" << std::endl;
        return items;
    }
    return output_array;
}

// Function to heapify a subtree rooted with node i in the array of items
void heapify(std::vector<Item> &items, int n, int i, bool descending) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && items[l].rarityScore > items[largest].rarityScore) {
        largest = l;
    }

    if (r < n && items[r].rarityScore > items[largest].rarityScore) {
        largest = r;
    }

    if (largest != i) {
        Item temp = items[i];
        items[i] = items[largest];
        items[largest] = temp;

        heapify(items, n, largest, descending);
    }
    if (descending) {
        if (l < n && items[l].rarityScore < items[largest].rarityScore) {
            largest = l;
        }
        if (r < n && items[r].rarityScore < items[largest].rarityScore) {
            largest = r;
        }
    } else {
        if (l < n && items[l].rarityScore > items[largest].rarityScore) {
            largest = l;
        }
        if (r < n && items[r].rarityScore > items[largest].rarityScore) {
            largest = r;
        }
    }


}

// Function to perform heap sort on rarityScore scores of items
std::vector<Item> heapSortByRarity(std::vector<Item> &items, bool descending) {
    int n = items.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(items, n, i, descending);
    }

    for (int i = n - 1; i > 0; i--) {
        Item temp = items[0];
        items[0] = items[i];
        items[i] = temp;

        heapify(items, i, 0, descending);
    }

    return items;
}
