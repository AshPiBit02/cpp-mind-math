/*
 * PROBLEM: Find Peak Index in a Mountain Array
 * 
 * A peak element is an element that is strictly greater than its neighbors.
 * Given an array that increases up to a peak and then decreases, find the index
 * of the peak element.
 * 
 * SOLUTION: Binary Search Approach (Recursive)
 * - Time Complexity: O(log n) - Binary search eliminates half of the search space in each iteration
 * - Space Complexity: O(log n) - Recursive call stack
 * 
 * Algorithm:
 * 1. Find the middle element
 * 2. If middle element is greater than both neighbors, it's the peak - return its index
 * 3. If middle element is greater than left neighbor, peak is on the right side - search right half
 * 4. Otherwise, peak is on the left side - search left half
 * 
 * NOTE: In this program, the array is guaranteed to always contain exactly ONE peak element.
 *       The array follows a mountain/bitonic pattern: increases then decreases.
 */

#include<iostream>
using namespace std;

// Function to find peak index using binary search
// Parameters: arr - input array, n - size of array, start - start index, end - end index
// Returns: index of the peak element
int BinSrchForpeakIndex(int* arr,int n,int start,int end)
{
    // Calculate middle index using bit manipulation to avoid overflow
    int mid=start+((end-start)/2);
    
    // Base case: if mid element is greater than both neighbors, it's the peak
    if( arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] )
    {
        return mid;
    }
    // If mid element is greater than left neighbor, peak is on the right side
    // Recursively search in right half
    else if(arr[mid]>arr[mid-1])
    {
        return BinSrchForpeakIndex(arr,n,mid+1,end);
    }
    // Otherwise, peak is on the left side
    // Recursively search in left half
    else
    {
        return BinSrchForpeakIndex(arr,n,start,mid-1);
    }
}
int main()
{
    // Input array: increases to 8 (peak) then decreases
    int arr[]={1,2,3,4,5,8,7,6};
    
    // Calculate array size
    int n=sizeof(arr)/sizeof(arr[0]);
    
    // Call binary search function to find peak index
    // Expected output: 5 (index of peak element 8)
    cout << "Peak element is at index: " << BinSrchForpeakIndex(arr,n,0,n-1) << endl;
    
    return 0;
}