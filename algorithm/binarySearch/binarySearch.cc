#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <algorithm>

size_t rank(int key, vector<int> &data)
{
    size_t first = 0;
    size_t last = data.size()-1;
    cout << "searching..." << endl;
    while (first <= last) {
        size_t mid = first + (last-first)/2;
        if (key < data[mid]) {
            last = mid-1;
        } else if (data[mid] < key) {
            first = mid+1;
        } else {
            return mid;
        }
    }
    cout << "data not in the text"<< endl;
    return 0;
}

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    vector<int> vecdata;
    int key;
    int data;
    while (ifs >> data) {
        vecdata.push_back(data);
    }
    sort(vecdata.begin(), vecdata.end());
    cout << "the size of text is: " << vecdata.size();
    cout << "please enter the number you want to search: ";
    while (cin >> key) {
        auto result = rank(key, vecdata);
        cout << "the return is: " << result;
        cout << "please enter the number you want to search: ";
    }
    return 0;
}
