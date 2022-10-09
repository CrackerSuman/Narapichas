void merge(vector<int>& arr, int l, int mid, int r) {
    int index = 0;
    int ptrL = l;
    int ptrR = mid;
    static vector<int>tempary;
    if (arr.size() > tempary.size()) {
        tempary.resize(arr.size());
    }
    while (ptrL != mid && ptrR != r) {
        if (arr[ptrL] < arr[ptrR]) {
            tempary[index++] = arr[ptrL++];
        } else {
            tempary[index++] = arr[ptrR++];
        }
    }
    while (ptrL != mid) {
        tempary[index++] = arr[ptrL++];
    }
    while (ptrR != r) {
        tempary[index++] = arr[ptrR++];
    }
    copy(tempary.begin(), tempary.begin() + index, arr.begin() + l);
}
void mergeSort(vector<int>& arr, int l, int r) { // sort the range [l, r) in arr
    if (r - l <= 1) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid, r);
    merge(arr, l, mid, r);
}
