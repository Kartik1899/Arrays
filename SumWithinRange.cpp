/* Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false. */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

float getMax(float x, float y)                         // returns max element
{
    return (x > y) ? x : y;
}
float getMin(float x, float y)                         // returns min element
{
    return (x < y) ? x : y;
}

int checkTripletWithinGivenRange(vector<string> input)
{
    if(input.size() < 3)                               // if input size is less than 3, triplets cannot be formed.
    {
        return 0;
    }

    vector<float> vec;
    for(int i = 0 ; i < input.size() ; i++)
    {
        vec.push_back(stof(input[i]));                  // taking float values from string using string to float function.
    }


    float sum = vec[0] + vec[1] + vec[2];               
    if(sum < 2.00 && sum > 1.00)                        // checking if the condition is satisfied
    {
        return 1;
    }


    float min;
    float max;
    float mid;
    max = getMax(vec[0],getMax(vec[1],vec[2]));         // storing max among the three elements used previously
    min = getMin(vec[0],getMin(vec[1],vec[2]));         // storing min among the three elements used previously
    mid = sum - min - max;
    
    for(int i = 3; i < vec.size(); i++)
    {
        if(sum > 2.00)
        {
            if(vec[i] < max)                            // if some is more than 2.0 we find element which is smaller than current max element.
            {
                sum = min + mid + vec[i];
                min = getMin(min,getMin(mid,vec[i]));
                max = getMax(min,getMax(mid,vec[i]));
                mid = sum - max - min;
            }
        }
        if( sum < 1.00)                                 // if some is less than 1.0 we find element which is more than current min element.
        {
            if(vec[i] > min)
            {
                sum = vec[i] + mid + max;
                min = getMin(vec[i],getMin(max,mid));
                max = getMax(vec[i],getMax(mid,max));
                mid = sum - max - min;    
            }
        }
        if(sum > 1.00 && sum < 2.00)                    // checking condition
        {
            return 1;
        }
    }
    return 0;
}

/*--------------------------------MAIN BODY-----------------------*/

int main()
{
    vector<string> input;
    int size;
    cin >> size;
    for(int i = 0 ; i < size ; i++)
    {
        string temp;
        cin >> temp;
        input.push_back(temp);
    }
    cout << endl;
    cout << checkTripletWithinGivenRange(input) << endl;
    return 0;



}