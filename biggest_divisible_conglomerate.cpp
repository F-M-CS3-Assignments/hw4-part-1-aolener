#include "bdc.h"
#include <vector>

#include <algorithm>

#include <iostream>
#include <string>



using namespace std;

//Recieved some helpful hints from Wesley Ihuezo :)
bool canAdd(int num, const vector<int>& conglomerate) {
    for (size_t ii = 0; ii < conglomerate.size(); ii++) {
        int currentNum = conglomerate[ii];
        if (num % currentNum != 0 && currentNum % num != 0) {
            return false;
        }
    }
    return true;
}

vector<int> findConglomerate(vector<int>& startingList, vector<int>current) {
    if (startingList.empty()) {
        return current;
    }

    vector<int> largestConglomerate = current;

    for (size_t ii = 0; ii < startingList.size(); ii++) {
        if (canAdd(startingList[ii], current)) {
            vector<int> newLargest = current;
            newLargest.push_back(startingList[ii]);

            vector<int> remainingList(startingList.begin() + ii + 1, startingList.end());
            vector<int> result = findConglomerate(remainingList, newLargest);

            if (result.size() > largestConglomerate.size()) {
                largestConglomerate = result;
            }
        }
    }
    return largestConglomerate;
}

vector<int> biggest_divisible_conglomerate(vector<int> input) {
    sort(input.rbegin(), input.rend());
    vector<int> current;
    return findConglomerate(input, current);
}

string vec_to_string(vector<int> vector) {
    string result = "{";
    for (size_t ii = 0; ii < vector.size(); ii++) {
        result += to_string(vector[ii]);
        if (ii != vector.size() - 1) {
            result +=", ";
        }
        result += "}";
        return result;
    }
}
