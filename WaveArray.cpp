/* Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... 

Example :
Given [1, 2, 3, 4]
One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

Return Lexicographically smallest
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> arr)
{
    for(int i = 0; i< arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> turntoWave(vector<int> vec)
{
    if(vec.size() <= 1)
    {
        return vec;
    }
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i < vec.size() - 1; i+=2)
    {
        int temp = vec[i];
        vec[i] = vec[i+1];
        vec[i+1] = temp;
    }
    return vec;
}

/*-----------------------MAIN BODY------------------*/
int main()
{
    int size;
    cin >> size;

    vector<int> array(size);
    for(int i = 0 ; i < size ; i++)
    {
        cin >> array[i];
    }
    
    print(turntoWave(array));
    return 0;

}