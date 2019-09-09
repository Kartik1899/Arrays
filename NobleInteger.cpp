/* 
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int checkNobleInteger(vector<int> vec)
{
    sort(vec.begin(),vec.end());                                            // Sorting 

    if(vec[vec.size() - 1] == 0)                                   // If last element is zero, it will always satisfy the condition
    {
        return 1;
    }
    
    for(int i = 0 ; i < vec.size() ; i++)
    {
        if(vec[i] == vec.size() - 1 - i && vec[i] != vec[i+1])
        {
            return 1;                                             // returing 1 when noble integer is found
        }
    }
    return -1;                              
}


/*---------------------------------------MAIN BODY-------------------------------*/

int main()
{
    vector<int> givenArr;
    int size;
    cin >> size;
    int x;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> x;
        givenArr.push_back(x);
    }

    cout << checkNobleInteger(givenArr);

    return 0;
}