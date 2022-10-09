#include<bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &arr) {
    if (arr.size() <= 1) {
        return;
    }
    int n = arr.size();
    int mid = n / 2;
    vector<int> leftData;
    vector<int> rightData;
    for (int i = 0; i < mid; ++i) {
        leftData.push_back(arr.at(i));
    }
    for (int i = mid; i < n; ++i) {
        rightData.push_back(arr.at(i));
    }
    mergeSort(leftData);
    mergeSort(rightData);
    int leftIndex = 0;
    int rightIndex = 0;
    int dataIndex = 0;
    int leftDataSz = leftData.size();
    int rightDataSz = rightData.size();
    while (leftIndex < leftDataSz && rightIndex < rightDataSz) {
        if (leftData.at(leftIndex) < rightData.at(rightIndex)) {
            arr.at(dataIndex) = leftData.at(leftIndex);
            leftIndex += 1;
        } else {
            arr.at(dataIndex) = rightData.at(rightIndex);
            rightIndex += 1;
        }
        dataIndex += 1;
    }
    if (leftIndex < leftDataSz) {
        arr.erase(arr.begin() + dataIndex, arr.begin() + n);
        for (int i = leftIndex; i < leftDataSz; ++i) {
            arr.push_back(leftData.at(i));
        }
    } else if (rightIndex < rightDataSz) {
        arr.erase(arr.begin() + dataIndex, arr.begin() + n);
        for (int i = rightIndex; i < rightDataSz; ++i) {
            arr.push_back(rightData.at(i));
        }
    }
}


int main() {
    vector<int> arr = { -22, 1, 0, 3, 4, 8, 5};
    mergeSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
}