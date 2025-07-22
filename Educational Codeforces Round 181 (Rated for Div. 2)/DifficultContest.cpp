#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string solve(string s) {
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    // Check if FFT is possible: need at least 2 F and 1 T
    bool canFFT = (freq['F'] >= 2 && freq['T'] >= 1);
    // Check if NTT is possible: need at least 1 N and 2 T
    bool canNTT = (freq['N'] >= 1 && freq['T'] >= 2);
    
    if (!canFFT && !canNTT) {
        return s; // no possible forbidden substring
    }
    
    // Strategy: separate F's and T's, and N's and T's
    // One way is to arrange all F's first, then other letters, then T's
    // Or arrange T's first, then others, then F's
    // Or arrange in some interleaved manner
    
    // Another approach: sort and then check, if forbidden exists, rearrange
    
    // Try to arrange all F's not together with T's following, or N's not followed by TT
    
    // Let's try arranging all T's first, then other characters, then F's
    string part1, part2, partF;
    for (auto &p : freq) {
        char c = p.first;
        int cnt = p.second;
        if (c != 'F') {
            part1 += string(cnt, c);
        } else {
            partF += string(cnt, c);
        }
    }
    string res1 = part1 + partF;
    
    // Check if res1 has FFT or NTT
    bool bad1 = (res1.find("FFT") != string::npos) || (res1.find("NTT") != string::npos);
    if (!bad1) {
        return res1;
    }
    
    // Alternative: arrange F's first, then others
    string res2 = partF + part1;
    bad1 = (res2.find("FFT") != string::npos) || (res2.find("NTT") != string::npos);
    if (!bad1) {
        return res2;
    }
    
    // Another strategy: interleave F's and T's with other characters
    // Or sort and then swap adjacent characters to break FFT or NTT
    
    // If previous attempts fail, try to distribute F's and T's
    // Let's collect all characters and sort them in a way that F's and T's are not together in forbidden patterns
    string all = s;
    sort(all.begin(), all.end());
    // Check if sorted string is bad
    bool bad = (all.find("FFT") != string::npos) || (all.find("NTT") != string::npos);
    if (!bad) {
        return all;
    }
    
    // If sorted is bad, try to permute adjacent characters to break the patterns
    for (size_t i = 1; i < all.size(); ++i) {
        if (i + 1 < all.size()) {
            string sub = all.substr(i-1, 3);
            if (sub == "FFT" || sub == "NTT") {
                swap(all[i], all[i+1]);
                i++; // skip next to avoid overlap checks
            }
        }
    }
    bad = (all.find("FFT") != string::npos) || (all.find("NTT") != string::npos);
    if (!bad) {
        return all;
    }
    
    // If still bad, try reversing
    reverse(all.begin(), all.end());
    bad = (all.find("FFT") != string::npos) || (all.find("NTT") != string::npos);
    if (!bad) {
        return all;
    }
    
    // Another approach: group same characters except F and T, then arrange
    
    // If all else fails, try a random shuffle (though not ideal, but problem states solution exists)
    // But for programming, better to find a deterministic way
    
    // As a last resort, arrange T's separated by other characters
    string res;
    vector<char> chars(s.begin(), s.end());
    // Place T's separated by at least one non-T
    int t_count = freq['T'];
    int other_pos = 0;
    vector<char> others;
    for (auto &p : freq) {
        if (p.first != 'T') {
            for (int i = 0; i < p.second; ++i) {
                others.push_back(p.first);
            }
        }
    }
    if (t_count == 0) {
        return string(others.begin(), others.end());
    }
    // Distribute T's as evenly as possible among others
    int slots = others.size() + 1;
    if (t_count > slots) {
        // Not possible to distribute without adjacent T's, but problem says solution exists
        // So maybe other approach is needed
    }
    res.reserve(s.size());
    int t_pos = 0;
    for (size_t i = 0; i < others.size(); ++i) {
        res += others[i];
        if (t_pos < t_count && (i+1) * t_count > t_pos * others.size()) {
            res += 'T';
            t_pos++;
        }
    }
    // Add remaining T's if any
    while (t_pos < t_count) {
        res += 'T';
        t_pos++;
    }
    // Check if this arrangement works
    bad = (res.find("FFT") != string::npos) || (res.find("NTT") != string::npos);
    if (!bad) {
        return res;
    }
    
    // If not, try another arrangement: place all non-F and non-T first, then F's and T's
    string others2;
    string f_part;
    string t_part;
    for (auto &p : freq) {
        char c = p.first;
        int cnt = p.second;
        if (c == 'F') {
            f_part += string(cnt, c);
        } else if (c == 'T') {
            t_part += string(cnt, c);
        } else {
            others2 += string(cnt, c);
        }
    }
    string res3 = others2 + f_part + t_part;
    bad = (res3.find("FFT") != string::npos) || (res3.find("NTT") != string::npos);
    if (!bad) {
        return res3;
    }
    res3 = others2 + t_part + f_part;
    bad = (res3.find("FFT") != string::npos) || (res3.find("NTT") != string::npos);
    if (!bad) {
        return res3;
    }
    
    // If still not found, try to interleave F's and T's with others
    // This is a fallback; problem states solution exists
    // So return any possible arrangement after some tries
    // For example, sort and reverse
    string res4 = s;
    sort(res4.begin(), res4.end());
    reverse(res4.begin(), res4.end());
    bad = (res4.find("FFT") != string::npos) || (res4.find("NTT") != string::npos);
    if (!bad) {
        return res4;
    }
    
    // As a last resort, return the original string sorted (though it might be bad)
    // But the problem says solution exists, so perhaps previous steps missed some cases
    // Alternatively, distribute F's and T's with other characters
    
    // Another idea: arrange all characters in alphabetical order, but split F's and T's
    // For example, all non-F/non-T, then F's, then T's
    string res5;
    for (auto &p : freq) {
        char c = p.first;
        if (c != 'F' && c != 'T') {
            res5 += string(p.second, c);
        }
    }
    for (auto &p : freq) {
        char c = p.first;
        if (c == 'F') {
            res5 += string(p.second, c);
        }
    }
    for (auto &p : freq) {
        char c = p.first;
        if (c == 'T') {
            res5 += string(p.second, c);
        }
    }
    bad = (res5.find("FFT") != string::npos) || (res5.find("NTT") != string::npos);
    if (!bad) {
        return res5;
    }
    
    // If still bad, try to place T's first, then others, then F's
    string res6;
    for (auto &p : freq) {
        char c = p.first;
        if (c == 'T') {
            res6 += string(p.second, c);
        }
    }
    for (auto &p : freq) {
        char c = p.first;
        if (c != 'F' && c != 'T') {
            res6 += string(p.second, c);
        }
    }
    for (auto &p : freq) {
        char c = p.first;
        if (c == 'F') {
            res6 += string(p.second, c);
        }
    }
    bad = (res6.find("FFT") != string::npos) || (res6.find("NTT") != string::npos);
    if (!bad) {
        return res6;
    }
    
    // If all else fails, return the original string (though problem states solution exists)
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res;
        
        // Check if the string already meets the criteria
        if (s.find("FFT") == string::npos && s.find("NTT") == string::npos) {
            cout << s << '\n';
            continue;
        }
        
        // Count frequencies
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Strategy: arrange all F's not followed by another F and then a T
        // Or all T's not preceded by N and another T
        
        // One way is to arrange all T's first, then other characters, then F's
        string partT(freq['T'], 'T');
        string partOther;
        string partF(freq['F'], 'F');
        for (auto &p : freq) {
            char c = p.first;
            if (c != 'T' && c != 'F') {
                partOther += string(p.second, c);
            }
        }
        string candidate1 = partT + partOther + partF;
        if (candidate1.find("FFT") == string::npos && candidate1.find("NTT") == string::npos) {
            cout << candidate1 << '\n';
            continue;
        }
        
        // Another candidate: arrange F's first, then others, then T's
        string candidate2 = partF + partOther + partT;
        if (candidate2.find("FFT") == string::npos && candidate2.find("NTT") == string::npos) {
            cout << candidate2 << '\n';
            continue;
        }
        
        // Another candidate: arrange others first, then F's, then T's
        string candidate3 = partOther + partF + partT;
        if (candidate3.find("FFT") == string::npos && candidate3.find("NTT") == string::npos) {
            cout << candidate3 << '\n';
            continue;
        }
        
        // Another candidate: arrange others first, then T's, then F's
        string candidate4 = partOther + partT + partF;
        if (candidate4.find("FFT") == string::npos && candidate4.find("NTT") == string::npos) {
            cout << candidate4 << '\n';
            continue;
        }
        
        // If none of the above, try to distribute F's and T's
        // For example, place F's and T's separated by other characters
        string distributed;
        distributed.reserve(s.size());
        vector<char> others;
        for (auto &p : freq) {
            if (p.first != 'F' && p.first != 'T') {
                for (int i = 0; i < p.second; ++i) {
                    others.push_back(p.first);
                }
            }
        }
        int f_pos = 0, t_pos = 0;
        int f_total = freq['F'];
        int t_total = freq['T'];
        for (size_t i = 0; i < others.size(); ++i) {
            distributed += others[i];
            // Decide whether to place F or T next
            if (f_pos < f_total && (i * f_total >= f_pos * others.size())) {
                distributed += 'F';
                f_pos++;
            }
        }
        // Add remaining F's
        while (f_pos < f_total) {
            distributed += 'F';
            f_pos++;
        }
        // Add T's at the end
        while (t_pos < t_total) {
            distributed += 'T';
            t_pos++;
        }
        if (distributed.find("FFT") == string::npos && distributed.find("NTT") == string::npos) {
            cout << distributed << '\n';
            continue;
        }
        
        // If still not found, try to place T's first, then others, then F's
        string candidate5;
        candidate5 += partT;
        candidate5 += partOther;
        candidate5 += partF;
        if (candidate5.find("FFT") == string::npos && candidate5.find("NTT") == string::npos) {
            cout << candidate5 << '\n';
            continue;
        }
        
        // As a last resort, sort the string and then check
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        if (sortedS.find("FFT") == string::npos && sortedS.find("NTT") == string::npos) {
            cout << sortedS << '\n';
            continue;
        }
        
        // Reverse sorted string
        reverse(sortedS.begin(), sortedS.end());
        if (sortedS.find("FFT") == string::npos && sortedS.find("NTT") == string::npos) {
            cout << sortedS << '\n';
            continue;
        }
        
        // If all else fails, output any permutation (problem states solution exists)
        // For example, shuffle until a valid one is found (but might not be efficient)
        // Alternatively, find any valid permutation by construction
        // Here, we can try to place all F's and T's not adjacent to each other
        string lastResort;
        for (char c : partOther) {
            lastResort += c;
        }
        // Interleave F's and T's with others
        int f_count = freq['F'];
        int t_count = freq['T'];
        int max_block = max(f_count, t_count);
        for (int i = 0; i < max_block; ++i) {
            if (i < f_count) {
                lastResort += 'F';
            }
            if (i < t_count) {
                lastResort += 'T';
            }
        }
        if (lastResort.find("FFT") == string::npos && lastResort.find("NTT") == string::npos) {
            cout << lastResort << '\n';
            continue;
        }
        
        // If nothing works, output the original string (though problem states solution exists)
        cout << s << '\n';
    }
    
    return 0;
}