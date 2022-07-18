int editDistance(string str1, string str2)
{
    //write you code here
    int m = str1.size(), n = str2.size(), pre;
    vector<int> cur(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        cur[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        pre = cur[0];
        cur[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = cur[j];
            if (str1[i - 1] == str2[j - 1]) {
                cur[j] = pre;
            } else {
                cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
            }
            pre = temp;
        }
    }
    return cur[n];
}