#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int timesSwap;

void printData(int *arr, int sizeAr)
{
    //cout << "--------------------------------" << endl;
    //cout << "array : ";
    for (int x = 0; x < sizeAr; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}

void swapData(int val, int Da, pair<int, int> Pair, int *arr, int sizeAr, int index, pair<int, int> *pairBound)
{
    //cout << "Find value " << val;
    //cout << " for putting which not in range of " << Pair.first << " , " << Pair.second << endl;

    for (int i = pairBound[Da].first; i <= pairBound[Da].second; i++)
    {
        if (arr[i] == val)
        {
            //cout << "index " << i << " not appropiate val " << arr[i] << endl;
            arr[i] = Da;
            //cout << "index " << i << " now appropiage had been changed to" << arr[i] << endl;
            timesSwap++;
            // cout << "change return" << change << endl;
            arr[index] = val;
            return;
        }
    }
    for (int i = 0; i < sizeAr; i++)
    {
        if ((i >= Pair.first && i <= Pair.second) || (i <= pairBound[Da].first && i >= pairBound[Da].second))
        {
            continue;
        }

        if (arr[i] == val)
        {
            //cout << "index " << i << " not appropiate val " << arr[i] << endl;
            arr[i] = Da;
            //cout << "index " << i << " now appropiage had been changed to" << arr[i] << endl;
            timesSwap++;
            // cout << "change return" << change << endl;
            arr[index] = val;
            return;
        }
    }
}

int main()
{
    int number;
    cin >> number;
    int data[number];
    map<int, int> numberOfEachType;
    pair<int, int> pairBound[4];
    pair<int, int> putData[3];
    putData[0] = make_pair(2, 3);
    putData[1] = make_pair(1, 3);
    putData[2] = make_pair(1, 2);
    for (int round = 0; round < number; round++)
    {
        int dataa;
        cin >> dataa;
        data[round] = dataa;
        numberOfEachType[dataa]++;
    }
    printData(data, number);
    pairBound[1] = make_pair(0,
                             numberOfEachType[1] - 1);
    pairBound[2] = make_pair(numberOfEachType[1],
                             numberOfEachType[1] + numberOfEachType[2] - 1);
    pairBound[3] = make_pair(numberOfEachType[1] + numberOfEachType[2],
                             numberOfEachType[1] + numberOfEachType[2] + numberOfEachType[3] - 1);

    for (int val = 1; val <= 3; val++)
    {
        for (int i = pairBound[val].first; i <= pairBound[val].second; i++)
        {
            if (data[i] == putData[val - 1].first)
            {
                //cout << "---------------------------------" << endl;
                //cout << "changing data index " << i << " val " << data[i] << endl;
                swapData(val, data[i], pairBound[val], data, number, i, pairBound);
                //cout << "changed Data index " << i << " val " << data[i] << endl;
                //printData(data, number);
            }
            else if (data[i] == putData[val - 1].second)
            {
                //cout << "---------------------------------" << endl;
                //cout << "changing data index " << i << " val " << data[i] << endl;
                swapData(val, data[i], pairBound[val], data, number, i, pairBound);
                //cout << "changed Data index " << i << " val " << data[i] << endl;
                //printData(data, number);
            }
        }
    }
    //cout << "---------------------------------" << endl;
    //cout << "!!!!!! timesSwap is " << timesSwap << endl;
    cout << timesSwap << endl;

    return 0;
}