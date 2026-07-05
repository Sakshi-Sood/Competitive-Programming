bool isValid(vector<int> &arr, int k, long long mid) {
    long long pages = 0;
    int count = 1;

    for (int i : arr) {
        if (pages + i <= mid)
            pages += i;
        else {
            count++;
            pages = i;
            if (count > k)
                return false;
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k) {
    if (k > arr.size())
        return -1;

    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);

    int ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
