int hammingDistance(int x, int y) {
    int distance = 0;
    while(x != 0 || y != 0) {
        int n1 = (x & 1) ^ (y & 1);
        x = x >> 1;
        y = y >> 1;

        if(n1 == 1) {
            distance++;
        }
    }