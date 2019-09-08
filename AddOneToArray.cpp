/* 

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list. 
Remove leading zero's in the output.

Input =  0 0 0 9 9 
Output = 1 0 0; ( 99 + 1)

Input = 9 9 9 9;
Output = 1 0 0 0 0; ( 9999 + 1)

Input = 1 2 3;
Output = 1 2 4; ( 123 + 1)

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


vector<int> addOneToArray(vector<int>givenArray)                  // Addition Function();
{
    int i;

    int carry = 0;
    int size = givenArray.size() - 1;

    do{                                                         
        if(carry > 0)                                           // If there is carry, we add it to the next number;
        {
            givenArray[size] += carry;
            if(givenArray[size] >= 10)                          // Checking if carry is present;
            {
                carry = givenArray[size] / 10;
                givenArray[size] %= 10;
            }
            else
            {
                carry = 0;
            }
            size--;                                             
        }
        else                                                    // Adding 1 to last element of array;
        {
            givenArray[size] += 1;
            if(givenArray[size] >= 10)
            {
                carry = givenArray[size] / 10;                  // Storing carry, if any;
                givenArray[size] %= 10;
            }
            else
            {
                carry = 0;
            }
            size--;            
        }
    }while(carry > 0 && size != -1);                            // The loop will break if there is no carry
    
    
    int countZero = 0;
    for(i = 0 ; i < givenArray.size(); i++)                     // Counting leading zero's as they have to be removed;
    {
        if(givenArray[i] != 0)
        {
            break;
        }
        countZero++;
    }


    vector<int> resultArr;                                      // result vector
    if(carry > 0)
    {
        resultArr.push_back(carry);                             // inserting carry;
    }

    /* If number of 0's is equal to the size of array, we need to print only 1*/
    i = (countZero < givenArray.size()) ? countZero : 0;

    for(i ; i < givenArray.size() ; i++)
    {
        resultArr.push_back(givenArray[i]);
    }
    
    return resultArr;                                           // returning vector
}





/*-------------------Main Body--------------------*/

int main()
{
    int size;
    cin >> size;

    vector<int> givenArray;
    for(int i = 0 ; i < size ; i++)
    {
        int x;
        cin >> x;
        givenArray.push_back(x);
    }

    vector<int> resultVector = addOneToArray(givenArray);

    for(int i = 0 ; i < resultVector.size(); i++)
    {
        cout << resultVector[i] <<" ";
    }

    return 0;
}
