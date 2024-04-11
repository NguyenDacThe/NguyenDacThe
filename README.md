Dĩ nhiên, dưới đây là phần còn thiếu của mã C++ với hàm `main`:

```cpp
        // S-boxes
        string sbox_str = "";
        for (int j = 0; j < 8; ++j) {
            int row = bin2dec(xor_x.substr(j * 6, 1) + xor_x.substr(j * 6 + 5, 1));
            int col = bin2dec(xor_x.substr(j * 6 + 1, 4));
            int val = sbox[j][row][col];
            sbox_str += dec2bin(val);
        }

        // Straight D-box
        int per[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
        string sbox_permuted = permute(sbox_str, per, 32);

        // XOR left and sbox_str
        string result = xor_strings(left, sbox_permuted);
        left = result;

        // Swapper
        if (i != 15) {
            swap(left, right);
        }
        cout << "Round " << i + 1 << " " << bin2hex(left) << " " << bin2hex(right) << " " << rk[i] << endl;
    }

    // Combination
    string combine = left + right;

    // Final permutation
    int final_perm[64] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
    string cipher_text = permute(combine, final_perm, 64);
    return cipher_text;
}

int main() {
    string pt = "123456ABCD132536";
    string key = "AABB09182736CCDD";

    // Key generation
    key = hex2bin(key);
    int keyp[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
    key = permute(key, keyp, 56);
    int shift_table[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    int key_comp[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    vector<string> rkb, rk;
    string left = key.substr(0, 28);
    string right = key.substr(28);
    for (int i = 0; i < 16; ++i) {
        left = shift_left(left, shift_table[i]);
        right = shift_left(right, shift_table[i]);
        string combine_str = left + right;
        string round_key = permute(combine_str, key_comp, 48);
        rkb.push_back(round_key);
        rk.push_back(bin2hex(round_key));
    }

    cout << "Encryption" << endl;
    string cipher_text = encrypt(pt, rkb, rk);
    cout << "Cipher Text: " << bin2hex(cipher_text) << endl;

    cout << "Decryption" << endl;
    vector<string> rkb_rev(rkb.rbegin(), rkb.rend());
    vector<string> rk_rev(rk.rbegin(), rk.rend());
    string text = encrypt(bin2hex(cipher_text), rkb_rev, rk_rev);
    cout << "Plain Text: " << text << endl;

    return 0;
Dĩ nhiên, dưới đây là phần còn thiếu của mã C++ với hàm `main`:

```cpp
        // S-boxes
        string sbox_str = "";
        for (int j = 0; j < 8; ++j) {
            int row = bin2dec(xor_x.substr(j * 6, 1) + xor_x.substr(j * 6 + 5, 1));
            int col = bin2dec(xor_x.substr(j * 6 + 1, 4));
            int val = sbox[j][row][col];
            sbox_str += dec2bin(val);
        }

        // Straight D-box
        int per[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
        string sbox_permuted = permute(sbox_str, per, 32);

        // XOR left and sbox_str
        string result = xor_strings(left, sbox_permuted);
        left = result;

        // Swapper
        if (i != 15) {
            swap(left, right);
        }
        cout << "Round " << i + 1 << " " << bin2hex(left) << " " << bin2hex(right) << " " << rk[i] << endl;
    }

    // Combination
    string combine = left + right;

    // Final permutation
    int final_perm[64] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
    string cipher_text = permute(combine, final_perm, 64);
    return cipher_text;
}

int main() {
    string pt = "123456ABCD132536";
    string key = "AABB09182736CCDD";

    // Key generation
    key = hex2bin(key);
    int keyp[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
    key = permute(key, keyp, 56);
    int shift_table[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    int key_comp[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    vector<string> rkb, rk;
    string left = key.substr(0, 28);
    string right = key.substr(28);
    for (int i = 0; i < 16; ++i) {
        left = shift_left(left, shift_table[i]);
        right = shift_left(right, shift_table[i]);
        string combine_str = left + right;
        string round_key = permute(combine_str, key_comp, 48);
        rkb.push_back(round_key);
        rk.push_back(bin2hex(round_key));
    }

    cout << "Encryption" << endl;
    string cipher_text = encrypt(pt, rkb, rk);
    cout << "Cipher Text: " << bin2hex(cipher_text) << endl;

    cout << "Decryption" << endl;
    vector<string> rkb_rev(rkb.rbegin(), rkb.rend());
    vector<string> rk_rev(rk.rbegin(), rk.rend());
    string text = encrypt(bin2hex(cipher_text), rkb_rev, rk_rev);
    cout << "Plain Text: " << text << endl;

    return 0;
}
```

Hãy chú ý rằng bạn cần phải thay đổi một số phần của mã Python khi chuyển đổi sang C++, chẳng hạn như sử dụng mảng thay vì danh sách và chấp nhận các tham số trong hàm theo kiểu dữ liệu cụ thể.

Hãy chú ý rằng bạn cần phải thay đổi một số phần của mã Python khi chuyển đổi sang C++, chẳng hạn như sử dụng mảng thay vì danh sách và chấp nhận các tham số trong hàm theo kiểu dữ liệu cụ thể.
