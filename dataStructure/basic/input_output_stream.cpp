#include<iostream> 
#include<string>//getline
#include<iomanip>
#include<fstream>
#include<sstream>//字符流

using namespace std;
template <class T>
inline string toString(const T &v) {//#include<sstream>
	ostringstream os;//创建字符串输出流 
	os << v;//将v的值写入字符串流 
	return os.str();//返回输出流生成的字符串 

}



template <class U>
inline U fromString(const string &str) {

	istringstream is;//创建字符串输入流
	U u;
	is >> u;//从字符串输入流中读 u

	return u;

}
struct Teacher {


};


int main() {

	//①cin.get(ch) 
	char ch;
	cin.get(ch);//读入一个字符并把它存储在ch 
	while (cin.get(ch)) {
		cout << ch;

	}

	//②ch = cin.get()
	ch = cin.get(); //读入一个字符并返回它的值

	while (ch != '\n') {
		cout << ch;
		ch = cin.get();
	}

	while (ch = cin.get() != EOF) {//到达文件尾后（不管是真正的文件尾还是模拟的文件尾），
							 //cin.get（void）都将返回EOF，以此来结束循环。
		cout << ch;
		cin >> ch;

	}
	/*
	 * 第一个参数是用于放字符串的内存单元的地址。
	 * 第二个参数比要读取的最大字符数大1,（额外的一个字符用于存储结尾的空字符）。
	 * 第三个参数指定用作分界符的字符。
	 * 只有两个参数的版本将使用换行符用作分界符。
	 */

	 /*
	  * 但一个明显的区别是get遇到 '\n '字符后便返回，这是 '\n '还在缓冲区中，所以下次读出来的将是 '\n '，
	  * 而getline遇到 '\n '也返回，但它会把 '\n '从缓冲区里移除掉 所以很多时候用getline方便些
	  */

	char input[25] = { 0 };
	cin.getline(input, 25, ',');
	cin.get(input, 25, ',');

	string str;
	getline(cin, str);//换行作分隔符
	getline(cin, str, ',');//以','作为分隔符


	/*
	setprecision(n)设置实数的精度为n位
	setw(n)设置字段宽度为n位
	setfill(c)设置填充宇符c
	setiosflags()设置输出格式状态,setiosflags不同于setw，它的影响是持久的，
				 直到使用resetiosflags重新恢复默认值时为止。
				 一般第一个输出先用setiosflags，第二个用resetiosflags。
				 括号中应给出格式状态,内容与控制符setosflags括号中的内容相同,如下所示。

	ios_base::left	输出数据在本域宽范围内向左对齐
	ios_base::right	输出数据在本域宽范围内向右对齐
	ios_base::internal	数值的符号位在域宽内左对齐,数值右对齐,中间由填充字符填充
	ios_base::dec	设置整数的基数为10
	ios_base::oct	设置整数的基数为8
	ios_base::hex	设置整数的基数为16
	ios_base::showbase	强制输出整数的基数(八进制数以0打头 ,十六进制数以0x打头)
	ios_base::howpoint	强制输出浮点数的小点和尾数0
	ios_base::uppercase	在以科学记数法格式E和以十六进制输出字母时以大写表示
	ios_base::showpos	对正数显示"+”号
	ios_base::scientific	浮点数以科学记数法格式输出
	ios_base::fixed	浮点数以定点格式(小数形式)输出
	ios_base::unitbuf	每次输出之后刷新所有的流
	ios_base::stdio	每次输出之后清除stdout, stderr

	*/

	double f = 12.365;
	cout << setiosflags(ios_base::fixed) << setw(6) << setprecision(2) << f << '\n';



	/*

	文件原理

	ifstream类，它是从istream类派生的，用来支持从磁盘文件的输入。
	ofstream类，它是从ostream类派生的，用来支持向磁盘文件的输出。
	fstream类，它是从iostream类派生的，用来支持对磁盘文件的输入输出。

	文件打开都有一个文件指针，该指针的初始位置由I/O方式指定，每次读写都从文件指针的当前位置开始。
	读入一个字节，指针就后移一个字节。当文件指针移到最后，就会遇到文件结束EOF（文件结束符也占一个字节，其值为-1)，
	此时流对象的成员函数eof的值为非0值(一般设为1)，表示文件结束 了。

	文件关闭，实际上是解除该磁盘文件与文件流的关联，原来设置的工作方式也失效，这样，就不能再通过文件流对该文件进行输入或输出

	文件类型:1、ASCII文件：文件的每一个字节中均以ASCII代码形式存放数据,即一个字节存放一个字符,这个文件就是ASCII文件(或称字符文件)。

			 2、二进制文件：文件中的信息不是字符数据，而是字节中的二进制形式的信息，因此它又称为字节文件

	*/


	/*
	 * ios:in	以输入方式打开文件
	 * ios::out	以输出方式打开文件(这是默认方式) , 如果已有此名字的文件,则将其原有内容全部清除
	 * ios:app	以输出方式打开文件,写入的数据添加在文件末尾
	 * ios::ate	打开一个已有的文件,文件指针指向文件末尾
	 * ios::trunc	打开一个文件,如果文件已存在,则删除其中全部数据,如文件不存在,则建立新文件。如已指
	 *	            定了ios:out方式，而未指定ios: :app，ios:ate , ios: :in，则同时默认此方式
	 * ios::binary	以进制方式打开一 个文件,如不指定此方式则默认为ASCII方式
	 * ios:in|ios:out	以输入和输出方式打开文件,文件可读可写
	 * ios::out|ios:binary	以进制方式打开一个输出文件
	 * ios::in|ios::binary	以二进制方式打开一个输入文件
	 */


	char fname[] = "E:/file.txt";
	char buff[1024] = { 0 };

	/***********  写文件  *************/

	//方式1 调用输出流ofstream对象的构造函数
	ofstream fout(fname, ios_base::out | ios_base::app);
	if (!fout)
	{
		cout << "打开文件失败";
	}
	fout.put('h'); //通过put函数写入字符
	fout.put('e');
	fout.put('l');
	fout.put('l');
	fout.put('o');
	fout.put('\n');
	fout.flush();
	fout.close();

	//方式2 输出流ofstream对象调用fopen函数
	ofstream fout;
	fout.open(fname, ios_base::out | ios_base::app);
	if (!fout)
	{
		cout << "打开文件失败";
	}
	fout << "hello world !";  //通过左移运算符写入字符串
	fout.flush();
	fout.close();

	//方式3 二进制文件 ostream& write(const char * buffer,int len),第一个参数是指针类型，第二个参数是要写入的字节数

	//遇到空字符时并不停止，会写完整的内容
	ofstream file3(fname, ios::out);
	if (!file3)
	{
		cout << "打开文件失败";
	}
	file3.write(buff, 1024);

	file3.close();

	//Teacher t1(31,"xiaoming");
	//fs.write((char *)&t1,sizeof(Teacher)); Teacher可以是结构体类型的，t1为结构体对象
	//fs.flush();
	//fs.close();



	//字符串输出流，将其他类型转化为字符串
	string str = toString(5);
	cout << str;


	//文件流对象写文件
	fstream file2(fname, ios::in | ios::out);
	file2 << "abdfd\n";
	file2 << "11111\n";
	file2.flush();
	file2.close();


	/***********  读文件  *************/

	//输入流ifstream对象读取文件内容
	//通过getline函数读取字符串，但是遇到换行会停止，空格不会
	ifstream fin;
	fin.open(fname, ios::in);
	fin.getline(buff, 1024);
	cout << buff << endl;
	fin.close();

	//getline一行一行读取文件
	string str;
	ifstream fin;
	fin.open(fname, ios::in);
	if (fin.peek() == EOF)
	{
		cout << "file is empty." << endl;
		return 0;
	}

	while (!fin.eof()) {//eof()函数来判断文件是否为空或者是否读到文件结尾了
	/*while(fin.peek() != EOF)*/
		getline(fin, str);
		cout << str;
	}

	fin.close();


	//文件流对象读文件内容
	fstream file1(fname, ios::in | ios::out);
	file1 >> buff;  //通过右移运算符读出字符串
	file1.close();
	cout << buff << endl;

	// 二进制文件  istream& read(char *buffer,int len);
	fstream fs2(fname, ios::binary | ios::in);
	if (!fs2)
	{
		cout << "文件打开失败" << endl;
	}

	Teacher tt;
	fs2.read((char *)&tt, sizeof(Teacher));

	//字符串输入流，将字符串转化为其他类型，例如 int 型
	int u = fromString<int>("5");


	return 0;
}