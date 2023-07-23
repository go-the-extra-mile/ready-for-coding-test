#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int sum=0;
int nums[500000];
int tmp[8001];

int avg(){
    double round_avg = round((double)sum/n);
    return (int)round_avg;
}

int midval(){
    return nums[n/2];
}

int mostfrequent(){
    int * appears = &(tmp[4000]);
    int max_appears = *max_element(tmp, tmp + sizeof(tmp)/sizeof(int));
    bool first_has_appeared = false;
    int most_frequent;
    for(int num=-4000; num<=4000; num++){ 
        if(max_appears != appears[num]) continue;
        if(first_has_appeared) return num;
        else {
            first_has_appeared = true;
            most_frequent = num;
        }
    }
    return most_frequent;
}

int rng(){
    return nums[n-1] - nums[0];
}

int main(){
    cin >> n;
    
    int * appears = &(tmp[4000]);
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
        appears[nums[i]]++;
    }

    cout << avg() << '\n';
    sort(nums, nums+n);
    cout << midval() << '\n';
    cout << mostfrequent() << '\n';
    cout << rng() << '\n';

    return 0;
}

