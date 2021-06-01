int binarySearch(int *arr, int leftIndex, int rightIndex, int x) {
    if (rightIndex >= 1) {
        int mid = leftIndex + (rightIndex - 1) / 2;

        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] > x)
            return binarySearch(arr, leftIndex, mid - 1, x);
        return binarySearch(arr, mid + 1, rightIndex, x);
    }
    return -1;
}