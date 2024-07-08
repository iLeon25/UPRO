int postaviBitove(unsigned short int *pokNaBroj, int n) {
    // Calculate the bitmask with n least significant bits set to 1
    unsigned short int mask = (1 << n) - 1;

    // Count the number of bits that will change from 0 to 1
    unsigned short int original = *pokNaBroj;
    unsigned short int modified = original | mask;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if ((original & (1 << i)) == 0) {
            count++;
        }
    }

    // Apply the mask to set the n least significant bits to 1
    *pokNaBroj = modified;

    // Return the number of bits changed from 0 to 1
    return count;
}
