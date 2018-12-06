#pragma once
#include<iostream>
#include<fstream>
#include"book.h"
void manager::AddNewBook()
{
	book *pbook;
	pbook = new book;
	if (pbook == nullptr)
	{
		cout << "Memory allocation failure" << endl;
		return;
	}
	else
	{
		input_base_informaion(pbook);
	}
	this->book_list.push_back(pbook);
}

void manager::input_base_informaion(book* &pbook)
{
	cout << "Please input the new book's information" << endl;
	cout << "please input this new book's ISBN" << endl;
	cin >> pbook->ISBN;
	cout << "please input this new book's name" << endl;
	cin >> pbook->BookName;
	cout << "please input this new book's author" << endl;
	cin >> pbook->author;
	cout << "please input this new book's Press" << endl;
	cin >> pbook->Press;
	cout << "please input this new book's Price" << endl;
	cin >> pbook->price;
	cout << "please input this new book's Counter" << endl;
	cin >> pbook->Counter;
}
void manager::Output_base_information(book* pbook)
{
	cout << pbook->ISBN << "  " << pbook->BookName << "   "\
		<< pbook->author << "  " << pbook->Press << "  "\
		<< pbook->price << "  " << pbook->Counter << endl;
}
void manager::File_output_base_information(ofstream fout, book* pbook)
{
	fout << pbook->ISBN << "  " << pbook->BookName << "   "\
		<< pbook->author << "  " << pbook->Press << "  "\
		<< pbook->price << "  " << pbook->Counter << endl;
}
void manager::Print_information()
{
	//this->book_list.pop_back();
	auto begin = this->book_list.begin();
	auto end = this->book_list.end();
	cout << "ISBN" << "    " << "BookName" << "     " \
		<< " author " << "   " << " Press" << "   " << " price" << "   " << "Counter" << endl;
	for (begin; begin != end; begin++)
	{
		cout << (*begin)->ISBN << "  " << (*begin)->BookName \
			<< "  " << (*begin)->author << "   " << (*begin)->Press \
			<< "    " << (*begin)->price \
			<< "   " << (*begin)->Counter << endl;
	}
}

book* manager::Search_ISBN(long long ISBN)
{
	auto begin = this->book_list.begin();
	auto end = this->book_list.end();
	for (begin; begin != end; begin++)
	{
		if ((*begin)->ISBN == ISBN)
		{
			cout << " The ISBN of " << ISBN << " was found" << endl;
			return *begin;
		}

	}
}
void manager::Modify_information(long  long ISBN)
{

	book* pbook = Search_ISBN(ISBN);
	cout << "Now you can chang the book's information  of " << ISBN << endl;
	input_base_informaion(pbook);
}
void manager::DeleteBook(long long ISBN)
{
	auto pbook = Search_ISBN(ISBN);
	cout << "Now you can delete the book's information  of " << ISBN << endl;
	cout << "Do you want to delete this book's information? (Y/NO) " << endl;
	string enter;
	cin >> enter;
	if (enter == "Y")
	{
		this->book_list.remove(pbook);
		cout << "Delete compete" << endl;
	}
	return;
}
void manager::sort()
{
	auto begin = this->book_list.begin();
	auto end = this->book_list.end();
	auto next = begin++;
	auto temp = begin;
	for (begin; begin != end; begin++)
	{
		if ((*begin)->ISBN > (*next)->ISBN)
		{

			*temp = *begin;
			*begin = *next;
			*next = *temp;
		}
		next++;
	}
}
bool manager::insort(book* b1, book* b2)
{
	return b1->ISBN < b2->ISBN;
}
void manager::Output_of_file()
{
	auto begin = this->book_list.begin();
	auto  end = this->book_list.end();

	ofstream fout;
	char filename[40] = "c:\\book_information_system.txt";//file name
	cout << "Please input the file's  path and  name" << endl;
	cin >> filename;
	fout.open(filename, ios::out | ios::in | ios::app);//Open  file and mode 
													   /*   ios::out is a mode of read£¬ios::inis a mode of write   */
	fout << "ISBN" << " " << "book name" << " " << "author" << " "\
		<< "press " << " " << "price" << " " << "margin" << endl;
	if (fout.bad())
	{
		cout << ("Not find the file \n");
		fout << "Writing to a basic_ofstream object..." << endl;
		fout.close();
		abort();//ÍË³öº¯Êý
	}
	else
		for (begin; end != begin; begin++)
		{
			//File_output_base_information(fout,*begin);
			fout << (*begin)->ISBN << "  " << (*begin)->BookName << "   "\
				<< (*begin)->author << "  " << (*begin)->Press << "  "\
				<< (*begin)->price << "  " << (*begin)->Counter << endl;
		}
	fout.close();//close file 

}
void manager::Input_of_file()
{
	char str[500];//buffer
	ifstream fin;// read pointer
	char filename[500] = "c:\\book_information_system.txt";//File name
	cout << " Please input the file's  path and  name " << endl;
	cin >> filename;
	fin.open(filename, ios::out | ios::in);
	int count = 0;
	while (fin.getline(str, 500))
	{
		cout << str << endl;
	}
	fin.close();
}