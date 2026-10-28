/*This program will find the second largest element in the array*/
#include <iostream>
using namespace std;

// function
int secondlargestNumber(int nums[], int size)
{
    // Initilize the index to check with
    int largestNumber = nums[0];
    int secondlargestNumber = nums[0];

    for (int i = 1; i < size; i++)
    {
        // check the array nums to find the largest
        if (nums[i] > largestNumber)
        {
            // update
            secondlargestNumber = largestNumber;
            largestNumber = nums[i];
        }
        // compare the secondlargest and element of an array
        else if (nums[i] > secondlargestNumber)
        {
            secondlargestNumber = nums[i];
        }
    }

    return secondlargestNumber;
}

int main()
{
    // example of an array
    int nums[] = {12, 90, 44, 50, 77, 13, 17, 33, 88};
    // find the size of an array
    int size = sizeof(nums) / sizeof(nums[0]);

    // call the function into main
    int result = secondlargestNumber(nums, size);

    // print
    cout << "Secondlargest number is " << result << endl;
    return 0;
}