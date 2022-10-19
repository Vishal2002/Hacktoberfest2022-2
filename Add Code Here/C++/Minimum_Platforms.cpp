#include <bits/stdc++.h>
using namespace std;
 
int findPlatform(int arr[], int dep[], int n)
{
    
    sort(arr, arr + n);
    sort(dep, dep + n);
 
    // plat_needed indicates number of platform and at initial 
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
 
        // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
 
        // Update result
        if (plat_needed > result)
            result = plat_needed;
    }
 
    return result;
}
 
int main()
{
 
    // Train 1 => Arrival : 01:00, Departure : 09:00
    // Train 2 => Arrival : 03:00, Departure : 04:00
    // Train 3 => Arrival : 05:00, Departure : 06:00
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}
 
// TC: O(Nlog(N))
//SC : O(1)
