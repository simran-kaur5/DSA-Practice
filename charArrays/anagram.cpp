#include <iostream>
#include <cstring>
using namespace std;
bool validAnagram(string str1, string str2, int n1, int n2)
{
    if (n1 != n2)
    {
        return false;
    }
    int arr[26] = {0};  //initialize array with 0 values at all indices

    for (int i = 0; i < n1; i++)
    {
        arr[str1[i] - 'a']++;    //index 0 to 25
    }

    for (int i = 0; i < n2; i++)
    {
        if (arr[str2[i] - 'a'] <= 0)
        {
            return false;
        }
        arr[str2[i] - 'a']--;
    }
    return true;
}

// Two strings are valid anagrams if and only if they contain exactly the same characters with exactly the same frequency, regardless of order.
int main()
{
    string str1 = "anagram";
    string str2 = "nagaram";

    bool valid = validAnagram(str1, str2, str1.length(), str2.length());
    if (valid)
    {
        cout << "Its valid Anagram" << endl;
    }
    else
    {
        cout << "Not valid Anagram" << endl;
    }

    return 0;
}