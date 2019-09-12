/* Pascal Triangle */
#include<iostream>
#include<vector>

using namespace std;

void printVec(vector<vector<int>> vec)                           // Print function              
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        for(int j = 0 ; j < vec[i].size() ; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> getPascal(int size)                         // Creating Pascal Triangle of required size
{
    vector<vector<int>> vec(size);
    if(size == 0)
    {
        return vec;
    }
    
    vec[0].push_back(1);                                       // Initializing Pascal Triangle


    for(int i = 1 ; i < size ;i++)
    {
        vec[i].push_back(1);                                   // First element of each row is always 1;
        for(int j = 1; j < i ; j++)
        {
            vec[i].push_back(vec[i-1][j] + vec[i-1][j-1]);
        }
        vec[i].push_back(1);                                   // Last element of each row is always 1;
    }
    return vec;
}

/*--------------------------MAIN BODY----------------------*/

int main()
{
    int size;
    cin >> size;
    vector<vector<int>> pascalTriangle = getPascal(size);
    printVec(pascalTriangle);
    return 0;
}