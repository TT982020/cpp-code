#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//class A {
//public:
//	A(int a)
//		:_a(a){}
//private:
//	int _a;
//};
//
//class B {
//
//	B(const A& a) {
//
//	}
//};

//int main() {
//	int i = 1;
//	// ��ʽ����ת��
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//	// ��ʾ��ǿ������ת��
//	int address = (int)p;
//	printf("%p, %d\n", p, address);
//
//	//����������ʽת��
//	A aa = 1;
//
//	return 0;
//}

//int main() {
//	volatile const int n = 10;
//	int* p = (int*)&n;
//	(*p)++;
//	cout << n << endl;
//	cout << *p << endl;
//}

class A {
public:
	A(int a = 0)
		:_a(a)
	{}
	virtual void func() {}
	int _a;
	operator bool() {
		return _a;
	}

	explicit operator int() {
		return _a;
	}
};

class B :public A {
public:
	B(int b = 0) :_b(b) {}
	int _b;
};

void fun(A* pa) {
	B* pb = dynamic_cast<B*>(pa);
	if (pb == nullptr)
	{
		cout << "ת��ʧ��" << endl;
	}
	else {
		cout << "ת���ɹ�" << endl;
		pb->_b++;
		pb->_a++;
		cout << pb->_a << "," << pb->_b << endl;
	}
}
class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	operator bool()
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}

struct ServerInfo
{
	char _address[32];
	//�����ƶ�д������string vector �����Ķ��������
	//����д��ȥ����һ��ָ�룬���̽�������Ұָ�룬��һ�����̶������Ϳ���
	//string _address;
	int _port;
	Date _date;
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename = "file.txt")
		:_filename(filename)
	{}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}
	// C++�ļ��������ƾ��ǿ��Զ��������ͺ��Զ������ͣ���ʹ��
	// һ���ķ�ʽ��ȥ�����������ȡ����
	// ��Ȼ�����Զ�������Date��Ҫ����>> �� <<
	// istream& operator >> (istream& in, Date& d)
	// ostream& operator << (ostream& out, const Date& d)
	void WriteText(const ServerInfo & info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " " << info._port << " " << info._date;
	}
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address >> info._port >> info._date;
	}
private:
	string _filename; // �����ļ�
};

//int main() {
//	ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
//	ConfigManager cm;
//	cm.WriteBin(winfo);
//
//	ServerInfo rbinfo;
//	cm.ReadBin(rbinfo);
//	cout << rbinfo._address << " " << rbinfo._port << " "<< rbinfo._date << endl;
//
//	return 0;
//}

//int main() {
//	ServerInfo winfo = { "192.0.0.1", 80, { 2022, 4, 10 } };
//	ConfigManager cm;
//	cm.WriteText(winfo);
//
//	ServerInfo rbinfo;
//	cm.ReadText(rbinfo);
//	cout << rbinfo._address << " " << rbinfo._port << " " << rbinfo._date << endl;
//
//	return 0;
//}

//int main() {
//	ifstream ifs("Test.cpp");
//	char ch;
//	while (ifs.get(ch))
//	{
//		cout << ch;
//	}
//}

//int main() {
//	/*int x = 10;
//	char buffer[128];
//	sprintf(buffer, "int:%d", x);
//	cout << buffer << endl;*/
//
//	Date d1(2023, 10, 22);
//	ostringstream oss;
//	oss << d1;
//	cout << oss.str() << endl;
//
//	string str("2023 10 22");
//	istringstream iss(str);
//	Date d;
//	iss >> d;
//	cout << d << endl;
//	
//}

//int main() {
//	A aa;
//	fun(&aa);
//
//	B bb;
//	fun(&bb);
//
//	int i = aa;
//	double d = aa;
//	int j = (int)aa;
//
//	/*string str;
//	while (cin >> str)
//	{
//		cout << str << endl;
//	}*/
//
//	ofstream ofs("file.txt");
//	//ofstream ofs("file.txt", ios_base::out | ios_base::binary);
//
//	Date d1(2023,10,22);
//	//ofs.write((const char*) & d1, sizeof(d1));
//	ofs << d1;
//
//}

//int main() {
//
//	//�������/�������
//	double d = 2.33;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	//���������
//	int* p = new int(2);
//	int x = reinterpret_cast<int>(p);
//	cout << x << endl;
//
//	//ȥ��const����
//	volatile const int b = 2;
//	int* pp = const_cast<int*>(&b);
//	cout << pp << endl;
//
//	return 0;
//}


struct ChatInfo
{
	string _name; // ����
	int _id;	//  id
	Date _date;		//  ʱ��
	string _msg;	// ������Ϣ
};

int main() {
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;

	string str = oss.str();
	cout << str << endl;


	ChatInfo rinfo;
	istringstream iss(str);
	iss >> rinfo._name >> rinfo._id >> rinfo._date >> rinfo._msg;
	cout << "-------------------------------------------------------"
		<< endl;
	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------"
		<< endl;
}