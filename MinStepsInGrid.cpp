/* You are in an infinite 2D grid where you can move in any of the 8 directions :
  (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
    You are given a sequence of points and the order in which you need
    to cover the points. Give the minimum number of steps in which you can achieve it.
    You start from the first point. 
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int max(int first,int second)
{
    return (first > second) ? first : second;     
}

int MinSteps(vector<int>first, vector<int>second)
{
    int storeSteps = 0;
    for(int i = 1; i < first.size(); i++)
    {
        int distX = abs(first[i] - first[i-1]);
        int distY = abs(second[i] - second[i-1]);

        storeSteps += max(distX,distY);                 // Adding the number of steps required to go to next co-ordinate
    }
    return storeSteps;
}

/*----------------------------MAIN BODY---------------------*/
int main()
{
    int totalX;
    cin >> totalX;
    vector<int> xIndexes(totalX);
    for(int i = 0 ; i < totalX; i++)
    {
        cin >> xIndexes[i];
    }
    
    int totalY;
    cin >> totalY;
    vector<int> yIndexes(totalY);
    for(int i = 0 ; i < totalY; i++)
    {
        cin >> yIndexes[i];
    }

    cout << MinSteps(xIndexes,yIndexes) << endl;

    return 0;
}