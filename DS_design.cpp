
/*  
  
  introduce:     This file use to the data structer design 
  Class Name:    data structure
  Project Name:  book information manager system
  copyright by DIY 
  date: 2018.12.6
  email:2650822367@qq.com
*/
#include"function.h"
using namespace std;
int Menu();
int Menu()
{
	int end_number;//Mennu
	cout << ("\n                       Book information   manage system                    \n");
	cout << ("      ************************************************************************\n");
	cout << ("      *        1.Add a new book's information                                *\n");
	cout << ("      *        2.Print all books information                                 *\n");
	cout << ("      *        3.Change  a book's information by ISBN                        *\n");
	cout << ("      *        4.Sort all book's ISBN                                        *\n");
	cout << ("      *        5.Delet a book's informaion by ISBN                           *\n");
	cout << ("      *        6.Save all book's information from memory to file(disk)       *\n");
	cout << ("      *        7.Read all book's information from file(disk) to memory       *\n");
	cout << ("      *        0.exit                                                        *\n");
	cout << ("      ************************************************************************\n");
	cout << ("Enter a number to represent your choice(0-7):");
	cin >> end_number;
	return  end_number;
}
void main()
{
	manager my;
	int chose;
	while (1)
	{
		chose = Menu();
		switch (chose)
		{
		case 1:
			my.AddNewBook();
			break;
		case 2:
			my.Print_information();
			break;
		case 3: {
			long long ISBN;
			cin >> ISBN;
			my.Modify_information(ISBN);
			break;
		}
		case 4:
			my.sort(); break;
		case 5: {
			long long ISBN;
			cin >> ISBN;
			my.DeleteBook(ISBN);
			break;
		}
		case 6: {	
			my.Output_of_file();
			break;
		}
		case 7: {
			my.Input_of_file();
			break;
		}	
		case 0:exit(0);
			cout<<("End of the Employee information management system !");
			break;
		default:cout<<("Your input was errored!"); break;
		}
	}
	system("pause");
}


