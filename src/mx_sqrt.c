int mx_sqrt(int x) {
    if ((x >= 0 && x <= 3) || x < 0)
        return 0;

    int start = 0, end = x, mid, res;

    while(start <= end) {
        mid = (start + end) / 2;

        if (mid * mid == x)
            return mid;
        
        if (mid * mid < x) {
            if ((mid + 1) * (mid + 1) > x)
                return 0;
            else {
                res = start;
                start = mid + 1;
            }
        }
        else
            end = mid - 1;
    }

    return res;
}
