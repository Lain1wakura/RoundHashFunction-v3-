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
		arr[0] = hash.gethash(str, len); // text1 = hash1
		arr[1] = hash.gethash(newsalt + texthash, len); // hash1 + text2 = hash2
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

//Enter input text, salt, hash lenght and quantity of rounds: string10 salty 10 0 - afVUvneScd
//Enter input text, salt, hash lenght and quantity of rounds: string10 10 0 - TMNXhTLLwd
//TMNXhTLLwdsalty - afVUvneScd

//Enter input text, salt, hash lenghtand quantity of rounds : string10 salt 10 5
//TMNXhTLLwd
//xxwpvYQwQd
//gDzQXQVXnU
//G1xNcxpXPU
//gNPOy11XQU
//r1TpDtDXlU
//
//r1TpDtDXlU 

//string* arr = new string[quan];
//arr[0] = hash.gethash(str, len); // text1 = hash1
//arr[1] = hash.gethash(newsalt + texthash, len); // hash1 + text2 = hash2
//for (int i = 2; i < quan; i++)
//{
//	finalhash = hash.gethash(arr[i - 1] + arr[i - 2], len);
//	arr[i] = finalhash;
//}
//for (int i = 0; i < quan; i++)
//{
//	cout << arr[i] << endl;
//}
//cout << finalhash << endl;

/*for (int i = 2; i <= quan; i++)
{
finalhash = hash.gethash(arr[i - 1] + arr[i - 2], len);
arr[i] = finalhash;
}
cout << finalhash << endl;*/