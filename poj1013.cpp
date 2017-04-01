#include<iostream>
#include<string>
#include<vector>
#include<set> 
#include <algorithm>
using namespace std;


void printSet(set<char> a)
{
    for (char i : a)
    {
        cout << i;
    }
}

void printVec(vector<string> a)
{
    for (string s : a)
    {
        cout << s << " "; 
    }
}

bool find(vector<string> left, vector<string> right, vector<string> balance, string& counterfeit)
{
    set<char> mHeavy, mLight, tDollar;
    for (int i = 0; i < 3; ++i)
    {
        if (balance[i].compare("even") == 0)
        {
            for (char& c : left[i])
            {
                tDollar.insert(c);
            }
            for (char& c : right[i])
            {
                tDollar.insert(c);
            }
        } else if (balance[i].compare("up") == 0)
        {
            for (char& c : left[i])
            {
                mHeavy.insert(c);
            }
            for (char& c : right[i])
            {
                mLight.insert(c);
            }
        } else if (balance[i].compare("down") == 0)
        {
            for (char& c : right[i])
            {
                mHeavy.insert(c);
            }
            for (char& c : left[i])
            {
                mLight.insert(c);
            }
        }
    }
    for (char c : tDollar)
    {
        mHeavy.erase(c);
        mLight.erase(c);
    }

    if (mHeavy.size() == 1)
    {
        counterfeit = *mHeavy.begin();
        return true;
    }
    if (mLight.size() == 1)
    {
        counterfeit = *mLight.begin();
        return false;
    }
    return true;
}

int main() {
	int n;
	vector<string> left(3), right(3), balance(3);
	string counterfeit;
	bool light = true;  // true is heavy, false is light
	cin >> n;
    while(n > 0)
	{
        for (int i = 0; i < 3; i++)
        {
            string a, b, c;
			cin >> a >> b >> c;
            left[i] = a;
            right[i] = b;
            balance[i] = c;
		}
		if (find(left, right, balance, counterfeit))
		{
			cout << counterfeit << " is the counterfeit coin and it is heavy" << endl;
		} else {
			cout << counterfeit << " is the counterfeit coin and it is light" << endl;
		}
		n--;
	}
}
