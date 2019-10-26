/*
Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        Total Rooms : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool checkPossibility(vector<int> arrive, vector<int>depart, int rooms)
{
    if(rooms < 1)                   // If no rooms are available, return false;
    {
        return false;
    }

    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    
                      
    int arriveIndex = 1;            // first person always gets the room, hence starting from 1
    int count = 1;                  // room given
    int departIndex = 0;
    int size = arrive.size();

    while(arriveIndex < size && departIndex < size)
    {
        if(arrive[arriveIndex] < depart[departIndex])
        {
            arriveIndex++;
            count++;
            if(count > rooms)      // if count exceeds total rooms, return false;
            {
                return false;
            }
        }
        else
        {
            count--;                // Room is free
            departIndex++;
        }
    }
    return true;
}

/*----------------------MAIN BODY------------------*/

int main()
{
    vector<int> arrivalDates;
    vector<int> departDates;
    int customerCount;
    cin >> customerCount;
    int x;
    for(int i = 0 ;i < customerCount; i++)
    {
        cin >> x;
        arrivalDates.push_back(x);
    }
    for(int i = 0 ;i < customerCount; i++)
    {
        cin >> x;
        departDates.push_back(x);
    }

    int totalRooms;
    cin >> totalRooms;

    cout << checkPossibility(arrivalDates,departDates,totalRooms) << endl;

    return 0;
}