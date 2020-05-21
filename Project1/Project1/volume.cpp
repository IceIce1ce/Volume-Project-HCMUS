#include"volume.h"

void create_file_default(const char*path,int size, ofstream &fin){

//	fin.open(path,ios::binary);//
	if (fin.is_open() == false)
	{
		return ;//int 4
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 1000000; j++) {
			fin.write((char*)&"",1);
		}
	}
}
void jump_code(const char* path, ofstream &fin) {

	//fin._Seekbeg;
	//fin.seekp;
	fin.seekp(0);
	string hex_array[3] = { "EB","3C","90" };
	char* arr = new char[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
		//cout << arr[i] << " ";
	}
	for (int i = 0; i < 3; i++)
	{
		//fwrite(arr,1,3,fin);
		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
	//fin.close();
}
void num_of_byte_sector(const char*path,ofstream &fin){
	fin.seekp(11);
	string hex_array[2] = { "02","00" };
	char* arr = new char[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 2; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_of_sector_cluster(const char* path, ofstream &fin) {
	fin.seekp(13);
	string hex_array[1] = { "08" };
	char* arr = new char[1];
	for (int i = 0; i < 1; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 1; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_of_sector_boot(const char* path, ofstream &fin) {
//	fin.seekp(14);
	string hex_array[2] = {"08","00" };
	char* arr = new char[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 2; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_of_fat(const char* path, ofstream &fin) {
	//	fin.seekp(14);
	string hex_array[1] = { "02" };
	char* arr = new char[1];
	for (int i = 0; i < 1; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 1; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_cluster_start(const char* path, ofstream& fin) {
	//2 byte tạo offset 1a
	string hex_array[1] = { "02" };
	char* arr = new char[1];
	for (int i = 0; i < 1; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 1; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;

}
void size_volume(const char* path, ofstream &fin) {
	//	fin.seekp(14);
	string hex_array[1] = { "02" };
	char* arr = new char[1];
	for (int i = 0; i < 1; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 1; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_sector_cluster(const char* path, ofstream& fin) {
	//	fin.seekp(14);
	string hex_array[4] = { "02" };
	char* arr = new char[1];
	for (int i = 0; i < 1; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 1; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}
void num_entry_rdet(const char* path, ofstream &fin) {
	fin.seekp(17);
	string hex_array[2] = { "00","02" };
	char* arr = new char[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 2; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;
}

bool createvolume(const char* path, int size,ofstream &fin){
	//create_file_default(path, size,fin);
	//ofstream fout;
	jump_code(path,fin);
	num_of_byte_sector(path, fin);
	num_of_sector_cluster(path, fin);
	num_of_sector_boot(path, fin);
	num_of_fat(path, fin);
	num_entry_rdet(path, fin);
	//char* name = new char[12];
	//for (int i = 0; i < strlen(name); i++) {
	//	name[i] = path[i];
	//}
	//char* name = new char[8];
	//char* a = new char[3];
	for(int i=0;i<strlen(path);i++){
		if (path[i] == '.')
		{
			for (int j = i + 1; j < strlen(path); j++) {
				fin.write((char*)&path[j], 1);
			}
			break;
		
		}
		fin.write((char*)&path[i], 1);
	}
	//fin.seekp(1000);
	//cout << fin.tellp();
	//delete name;
//	fin.close();
	return true;
}
int seekentryempty(char*&vol,int &size,ifstream &fin)
{
	int move = 248*512-1;
	fin.seekg(248 * 512 - 1, 0);//truy xuat toi entry
	char a;
	fin.read((char*)&a,1);
	int count = 1;
	while (a != '\0')//cuoi file import
	{
		fin.seekg(-1, 1);
		count++;
		fin.seekg(move, 1);
		fin.read((char*)&a, 1);
	}
	size = fin.tellg();
	cout << size;
	return count;
}
void writefile(char*&vol, const char* path,int &size,ofstream &fout){
		
	for (int i = 0; i < strlen(path); i++) {
		if (path[i] == '.') {
			for (int j = i + 1; j < strlen(path); j++) {
				fout.write((char*)&path[j], 1);
			}
			break;
		}
		fout.write((char*)&path[i], 1);
	}
}
void write_properties(const char*vol,const char* path, ofstream &fin){

		char c ;
		DWORD subattr = GetFileAttributesA(path);
		if (subattr & FILE_ATTRIBUTE_READONLY)
			c |= (1 << 0);
		if (subattr & FILE_ATTRIBUTE_HIDDEN)
			c |= (1 << 1);
		if (subattr & FILE_ATTRIBUTE_SYSTEM)
			c |= (1 << 2);
		if (subattr & FILE_ATTRIBUTE_DIRECTORY)
			c |= (1 << 4);
		if (subattr & FILE_ATTRIBUTE_ARCHIVE)
			c |= (1 << 5);
		fin.write(&c,1);
		//fin.close();
}

void write_cluster_start(const char* vol,ofstream &fin) {
	fin.seekp(10, 1);
	string hex_array[2] = { "06","00" };
	char* arr = new char[2];
	for (int i = 0; i < 2; i++) {
		arr[i] = char(hexToDecimal(hex_array[i]));
	}
	for (int i = 0; i < 2; i++)
	{

		fin.write((char*)&arr[i], sizeof(arr[i]));
	}
	//fin.write((char*)&arr[i], sizeof(arr));
	delete[] arr;

}
int firstFreeCluster(ifstream &fin) {
	int f = 8;
	fin.seekg(f * 512 * 4, 0);
	char check;
	fin.read((char*)&check,1);
	if (check == '\0')
		cout << "quang";
	while (check != '\0') {
		fin.seekg(-1, 1);
		f++;
		fin.seekg(f*512*4, 1);
		fin.read((char*)&check, 1);
	}
	return f;
}

bool import_file_to_volume(char*&vol,const char*path,int &cur,ofstream &fout,ifstream &fin, uint64_t pass){
//cur lay vi tri hien tai cua entry trong
		ifstream f;
		f.open(path);
		f.seekg(0, 2);//lay kich thuong file
		int ei = f.tellg();
		fout.seekp(cur-1, 0);
		writefile(vol, path,cur,fout);
		fout.seekp(11 - strlen(path), 1);
		write_properties(vol, path, fout);
		write_cluster_start(vol,fout);//2 byte tai offset 1a can dich them  1a
		int size;
		string a;

		//write_size_content_file(vol, path,size);//size la vi tri sau khi viet noi dung
		int b = firstFreeCluster(fin);
		if (b >= 8) {
			//cai f la cai ifstream f de tro toi cai path
			//cai fout de viet len volume
			//dung cai f de doc cai fout de viet het r
			f.seekg(0, 0);
			fout.seekp(b * 512 *4 , 0);
			char c;
			f >> c;
			for(int i=0;i<ei;i++){
				char c;
				f >> c;
				fout.write((char*)&c, 1);
			}
	
		}
		f.close();
		remove(path);
	return true;
}

//print list file in folder
/*string WcharToString(wchar_t* wchar_str) 
{
  string str = "";
  int index = 0;
  while(wchar_str[index] != 0) 
  {
	  str += (char)wchar_str[index];
	  ++ index;
  }
  return str;
}
wchar_t* StringToWchar(string str) 
{
	int index = 0, count = str.size();
	wchar_t *ws_str = new wchar_t [count + 1]; 
	while (index < str.size()) 
	{
		ws_str[index] = (wchar_t)str[index];
		index++;
	}
	ws_str[index] = 0;
	return ws_str;
}
vector<string> ListFileInVolume(string path_folder) 
{
  WIN32_FIND_DATA find_file_data;
  vector<string> list_file;
  wchar_t *path_folder_full = StringToWchar(path_folder);
  HANDLE hFind = FindFirstFile(path_folder_full, &find_file_data);
  list_file.push_back(WcharToString(find_file_data.cFileName));
  while(FindNextFile(hFind, &find_file_data)) list_file.push_back(WcharToString(find_file_data.cFileName));
  return list_file;
}*/

//hash password
uint64_t hashtables(string str)
{
	uint64_t d = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 31 || str[i] == 132)
		{
			if (i + 1 <= 20) str = str.substr(0, i) + str.substr(i + 1);
			else str = str.substr(0, i);
		}
		d += d * 256 + str[i];
	}
	d %= (uint64_t)pow(2, 64);
	return d;
}
string inputPassword()
{
	string psw, str = "";
	cout << "Input password for your file: ";
	char temp;
	while(true)
	{
		temp = _getch();
		if(temp != char(13))
		{
			cout << "*";
			str += temp;
		}
		else break;
	}
	for(int i = 0; i < str.length(); i++) psw += str[i];
	return psw;
}

//export file, just export filename with extension, problem when export content of file
bool exportfile(char*&vol,const char*file, ifstream &fin) {
//	//truy xuat rdet
	ofstream f;
	f.open(file);
	int j = 248 * 512 - 1; 
	char c;
	int count = 1;
	fin.seekg(j, 0);
	fin.read((char*)&c, 1);
	file = new char[32];
	///doc 8 byte dau la file name

	char* namevsex = new char[12];
	while (c != '\0') {
		fin.seekg(-1, 1);
		int i;
		for (i = 0; i < 8; i++) {
			fin.read((char*)&c, 1);
			namevsex[i] = c;
		}
		namevsex[i] = '.';
		/*for(int i=0;i<3;i++){
			fin.read((char*)&c, 1);
			namevsex[i] = c;
		}*/
		for(int j=0;j<3;j++){
			i++;
			fin.read((char*)&c, 1);
			namevsex[i] = c;
		}
		namevsex[0] = '\0';//xoa file 
		count++;
		fin.seekg(32, 1);
		fin.read((char*)&c, 1);
	}
	/*if (c == '\0')
	{
		cout << "not file";
		return 0;//het file de move
	}*/
	//move data cua file, tìm cluster bat dau cua file
	int a = 8;//cluster bat dau cua file 1 la 8
	fin.seekg(a * 512 * 4-1, 0);//truy xuat toi cluster do

	fin.read((char*)&c, 1);
	//doc nd cua file do
	f.seekp(0, 0);
	while (c != '\0') {
		f << c;
		fin.read((char*)&c, 1);
	}
	return true;
}

//print file 
void printListFile(const char*vol,ifstream &fin) 
{
	int curEntry = 1;
	fin.seekg(248 * 512 - 1, 0);
	int count = 1;
	char temp;
	fin.read((char*)&temp, 1);
	cout << "List of file in volume:" << endl;
	char* file = new char[13];
	while (temp != '\0') {
		fin.seekg(-1, 1);
		int i;
		for(i=0;i<8;i++){
			fin.read((char*)&temp, 1);
			file[i] = temp;
			
		}
		//i++;
		file[8] = '.';//i=9
		for (int j= 0; j < 3; j++) {

			fin.read((char*)&temp, 1);
			i++;
			file[i] = temp;
		}
		cout << file << endl;
		fin.seekg(-12, 1);
		fin.seekg(32, 1);
		fin.read((char*)&temp, 1);
	}
	delete[] file;
	return;
}