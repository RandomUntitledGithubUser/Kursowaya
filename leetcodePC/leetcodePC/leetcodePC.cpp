#include <iostream>
#include <vector>

using namespace std;

vector<int> searchInterpol(vector<int>& nums, int target) {
    int counter = 0;
    int leftPos = 0;
    int rightPos = size(nums) - 1;
    int middlePos;
    bool findIt = false;

    while (target >= nums[leftPos] && target <= nums[rightPos] && findIt != true) {

        middlePos = leftPos + ( ( (target - nums[leftPos]) * (rightPos-leftPos) ) / (nums[rightPos]-nums[leftPos]+1) );
        counter++;
        if (nums[middlePos] == target){
            findIt = true;
            break;
        }
        else if (nums[middlePos] > target)
            rightPos = middlePos - 1;
        else if (nums[middlePos] < target)
            leftPos = middlePos + 1;
        if (target == nums[leftPos])
            return { leftPos, counter };
        else if (target == nums[rightPos])
            return { rightPos, counter };
        
    }

    if (findIt)
        return { middlePos, counter };
    //cout << middlePos << "\n" << "Interpollar search itterations: " << counter << "\n";
    else
        return  { -1, counter };
        //cout << "No elements: " << -1 << " Interpollar search itterations: " << counter << "\n";
}

int search(vector<int>& nums, int target)
{
    int left = 0, right = size(nums) - 1;
    while (target >= nums[left] && target <= nums[right])
    {
        int mid = left + (target - nums[left]) * (right - left) / (nums[right] - nums[left] + 1);
        if (target == nums[mid])
        {
            return mid;
            break;
        }
        else if (target > nums[mid])
            left = mid + 1;
        else if (target < nums[mid])
            right = mid - 1;
        if (target == nums[left])
            return left;
        else if (target == nums[right])
            return right;

    }
    return -1;
}

vector<int> searchBinar (vector<int>& nums, int target) {
    int counter = 0;
    int leftPos = 0;
    int rightPos = size(nums) - 1;
    int middlePos = 0;
    int findIt = false;
    cout << "\n";

    while (leftPos <= rightPos && findIt != true) {

        middlePos = (leftPos + rightPos) / 2;
        counter++;
        if (nums[middlePos] == target)
            findIt = true;

        if (nums[middlePos] > target)
            rightPos = middlePos - 1;
        else
            leftPos = middlePos + 1;

        
    }

    if (findIt)
        return { middlePos,counter };
    //cout << middlePos << "\n" << "Binary search itterations: " << counter << "\n";
    else
        return { -1, counter };
        //cout << "No elements: " << -1 << " Binary search itterations: " << counter << "\n";
    
}

void main()
{

    int target;
    //int arr[6] {-1,0,3,5,9,12};
    //vector<int> arr { 2, 5, 8, 11, 14, 17, 20, 23, 25, 29, 32, 35, 38, 41 };
    vector<int> buff{};
    vector<int> arr {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

    cout << "Enter target value: ";
    cin >> target;
    cout << "\n";

    buff = searchInterpol(arr, target);

    cout << buff[0]+1 << "\n" << "Interpollar search itterations: " << buff[1] << "\n";

    buff = searchBinar(arr, target);
       
    cout << buff[0]+1 << "\n" << "Binary search itterations: " << buff[1] << "\n";

    system("pause");
}


//#include <iostream>
//#include <cstdlib>
//#include <vector>
//
//
//using namespace std;
//
//vector<int> searchRange(vector<int>& nums, int target) {
//    int left, right, mid=0, temp, answ1 =-1, answ2=-1;
//    bool find = false;
//    left = 0;
//    right = size(nums)-1;
//
//    while ((left <= right) && !find) {
//
//        mid = (left + right) / 2;
//
//        if (nums[mid] == target)
//            find = true;
//
//        else if (nums[mid] > target)
//            right = mid - 1;
//
//        else left = mid + 1;
//
//    }
//
//    if (!find)
//        return { -1, -1 };
//
//    temp = mid;
//
//    for (;;mid--) {
//        if (mid < 0 || nums[mid] != target)
//            break;
//        answ1 = mid;
//    }
//
//    mid = temp;
//
//    for (;; mid++) {
//        if (mid > (size(nums)-1) || nums[mid] != target )
//            break;
//        answ2 = mid;
//    }
//    return { answ1, answ2 };
//
//
//
//}
//
// /*int temp;
//    int temp1;
//    int mid;
//    int left = 0;
//    int right = size(nums);
//    if (right <= 0) {
//        return { -1, -1 };
//    }
//    bool find = 0;
//    bool no = true;
//    while ((left <= right) && !find) {
//
//        mid = (left + right) / 2;
//
//        if(mid > (size(nums)-1))
//            return { -1, -1 };
//
//        if (nums[mid] == target) {
//            find = true;
//            temp = mid;
//        }
//
//
//        if (nums[mid] > target)
//            right = mid - 1;
//
//        else left = mid + 1;
//    }
//
//    if (left <= right) {
//
//
//        mid++;
//        left = 0;
//        right = mid;
//        find = 0;
//        while ((left <= right)  && !find && no) {
//
//            mid = (left + right) / 2;
//
//            if (nums[mid] == target)
//                find = 1;
//
//
//            if (nums[mid] > target)
//                right = mid - 1;
//
//            else left = mid + 1;
//        }
//        temp1 = mid;
//
//        mid = temp;
//        mid--;
//        left = mid;
//        right = size(nums);
//        find = 0;
//        while ((left <= right)  && !find && no) {
//
//            mid = (left + right) / 2;
//
//            if (nums[mid] == target)
//                find = 1;
//
//
//            if (nums[mid] > target)
//                right = mid - 1;
//
//            else left = mid + 1;
//        }
//
//
//
//
//        return { temp1, mid };
//        
//    }
//    else {
//        return { -1, -1 };
//    }*/
//
//int main()
//{   
//    int target;
//    vector<int> nums = {2,2};
//    vector<int> last;
//    cout << "target: ";
//    cin >> target;
//    last = searchRange(nums, target);
//    cout << "\n" << last[0] << ", " << last[1];
//}
