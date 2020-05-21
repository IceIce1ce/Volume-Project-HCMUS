#include "volume.h"

int main()
{
	//create_file_default()
	char* p = new char[14];
	string userChoice;
	cout << "Do you want to open an existing volume or create a new volume (open/create): ";
	getline(cin, userChoice);
	if(userChoice == "create")
	{
	cout << "Input name of volume: ";
	cin.getline(p, 14);
	int size;
	cout << "Input size of volume: ";
	cin >> size;
	ofstream fout;
	fout.open(p, ios::binary);
	ifstream fin;
	fin.open(p, ios::binary);
	create_file_default(p, size,fout);
	bool ans = true;
	ans = createvolume(p, size,fout);
	if (ans == true)
		cout << "Create volume successfully!!!";
	else cout << "Error";
	char* a = new char[100];
	cout << "\nInput file to import: ";
	cin.ignore();
	cin.getline(a, 30);
	//pass for file
	string choice;
	cout << "Do you want to set password for your file (yes/no): ";
	getline(cin, choice);
	uint64_t psw;
	if(choice == "yes")
	{
		string str = inputPassword();
		psw = hashtables(str);
		cout << endl;
	}
	else if(choice == "no") psw = 0;
	//pass for file
	bool b = true;
	int cur;
	int f = seekentryempty(p, cur,fin);
	if (f != 0)
	{
		b = import_file_to_volume(p, a,cur,fout,fin, psw);
	}
	/*cout << endl;
	string path_vol(p);
	vector<string> list_file = ListFileInVolume(path_vol);
	cout << "List file in volume:" << endl;
	for (int i = 0; i < list_file.size(); i++) cout << list_file[i] << endl;*/ 
	cout << endl;
	printListFile(p, fin);
	//export file
	char*file = new char[31];
	cout << "Input file for exporting: ";
	cin.getline(file, 30);
	exportfile(p, file, fin);
	//export file
	delete[] p;
	delete[] a;
	}
	else if(userChoice == "open")
	{
		char *p1 = new char[14];
		cout << "Input name of your volume to open: ";
		cin.getline(p1, 13);
		ifstream myfin;
		myfin.open(p1, ios::binary);
		if(!myfin.is_open())
		{
			cout << "Can't found this volume";
			exit(0);
		}
		cout << "open volume successfully!!!";
		Sleep(500);
		delete[] p1;
	}
	return 0;
}