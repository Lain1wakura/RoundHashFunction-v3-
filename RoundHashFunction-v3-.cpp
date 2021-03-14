#include <iostream>
#include "HeaderHash.h"
using namespace std;

int main()
{
	Hash hash;
	int len, quan, size = 2;
	string str, finalhash, newsalt, texthash, salthash;
	cout << "Enter input text, salt, hash lenght and quantity of rounds: ";
	cin >> str >> newsalt >> len >> quan;

	if (quan <= 1)
	{
		finalhash += hash.gethash(str, len);
		finalhash = hash.gethash(finalhash + newsalt, len);
		cout << finalhash << endl;
	}
	else if (quan > 1)
	{
		size += quan;
		string* arr = new string[size];
		arr[0] = hash.gethash(str, len);
		arr[1] = hash.gethash(newsalt + texthash, len); 
		string temphash = arr[0] + arr[1];
		for (int i = 2; i <= quan; i++)
		{
			finalhash = hash.gethash(temphash, len);
			arr[i] = finalhash;
			temphash += arr[i];
		}
		cout << finalhash << endl;
	}
	else
		cout << "Wrong quantity of rounds, must be >0!";

	return 0;
}
