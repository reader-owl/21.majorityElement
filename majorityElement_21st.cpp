#include <iostream>

/*
                        Q. Majority Element ( >n/2 times)

                    explanation - we will be given array -  arr[] = {2, 2, 3, 3, 1, 2, 2}
                                    we have to find the element which appears more than n/2 times
                                    from above array where its length is 7 and 2 appears 4times which is more than 7/2 = 3 times

                Brute force -  we will take an element and iterate through whole array and do 'cnt++' and check if it
                                appears more than n/2 times
                                we will repeat this iteration for every element

        Pseudo code
for(i=0; i<n; i++)
{
    cnt = 0;
    for(j=0; j<n; j++)
    {
        if(arr[j] == arr[i])
            cnt++;
    }
    if(cnt > n/2)
        return arr[i];
}

                TC - O(N^2)


                Better sol -  will use hashing
                            create a hash table where we store 'element, cnt' as 'key, value'
                            scan through the whole array and their count
                            first we store 2 and its count - (2, 1)
                            then we store 2                - (2, 2)     // <- add up from previous
                            then 3                         - (3, 1)
                            then 3                         - (3, 2)
                            then 1                         - (1, 1)
                                 2                         - (2, 3)
                                 2                         - (2, 4)
                                            map store in sorted order

        Actual code
int majorityElement(vector<int> v)
{
    map<int, int> mpp;
    for(int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }
    for(auto it : mpp)
    {
        if(it.second > (v.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

                TC - O(N*log N) + O(N)
                SC - O(N)                   // when array includes all unique elements


                Optimal sol -  will be using  Moore's Voting Algorithm
                                array - arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5}

            explanation - initially we take 2 variables - element and count
                          at first element is not being intialized and count (cnt) is '0'
                            initially we take first element (7) and assume it to be our answer, we also increase our
                            cnt = 1 (0 to 1)
                            by moving fwd we again meet 7 and count goes to cnt = 2
                            moving we get 5 and cnt = 1     (2 to 1, bcz it is 5 not 7)
                            moving        7 and cnt = 2
                            moving        5 and cnt = 1
                            moving        1 and cnt = 0
                             as we get cnt = 0, we create an array {7, 7, 5, 7, 5, 1}   ...(i)
                             in this array cnt is '0' that means there is no element which appears more than n/2 in (i)

                            now moving to next element which is 5 (assume it to be the majority element) and set
                            cnt = 1  (1 for element 5)
                            moving        7 and cnt = 0
                             we got cnt = 0, there is array {5, 7}   ... (ii)

                            now next element, 5 and cnt = 1
                            moving, 5 and cnt = 2
                            moving, 7 and cnt = 1
                            moving, 7 and cnt = 0
                             we got cnt = 0, there is array {5, 5, 7, 7}    ...(iii)

                            now next element, 5 and cnt = 1
                            moving, 5 and cnt = 2
                            moving, 5 and cnt = 3
                            moving, 5 and cnt = 4
                             we got cnt = 4, and respective element is 5
                             if there exist a majority element in original array then the answer will be 5

                        process - 1. apply Moore's voting algo
                                  2. verify if the element is majority or not (by iteration)

        Actual code
int majorityElement(vector<int> v)
{
    int cnt = 0;
    int el;
    for(int i = 0; i < v.size(); i++)
    {
        if(cnt == 0)
        {
            cnt = 1;
            el = v[i];
        }
        else if(v[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == el)
            cnt1++;
    }
    if(cnt1 > (v.size() / 2))
    {
        return el;
    }
    return -1;
}

                    TC - O(N) + O(N)
                                  |_ if there is majority element
                    SC - O(1)
*/

int main()
{
    std::cout << "Hello World!\n";
}