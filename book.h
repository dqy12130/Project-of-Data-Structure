
#include<string>
#include<list>
using namespace std;
class book;
class manager;
class book
{
public:
	long long ISBN;// book's ISBN
	string  BookName;//book's name
	string  Press;
	string author;
	double  price;//book's price
	int Counter;
public:
	friend manager;
};
class manager//:public book
{
private:
	book * books;
	list<book*> book_list;
	//books = new book;
public:
	manager()
	{
		this->books = new book;
		books->author = "DIY";
		books->BookName = "NULL";
		books->ISBN = 00000000000;
		books->Press = "NULL";
		books->price = 0.00;
		books->Counter = 0;
	}
	manager(book) {}
	void AddNewBook();
	void Print_information();
	void input_base_informaion(book*&);
	void Output_base_information(book*);
	void File_output_base_information(ofstream fout, book* pbook);
	book *Search_ISBN(long long);
	void Modify_information(long  long);
	void DeleteBook(long long);
	void sort();
	bool insort(book*, book*);
	bool  operator <(book* b1)
	{
		return this->books->ISBN < b1->ISBN;
	}
	void Output_of_file();
	void Input_of_file();
};
