
#include <iostream>
#include <iomanip>//to give the space setw().
#include <fstream>//to write and read from the txt file.


using namespace std;
//validate inputs from user.
void limit(int &num,int lowbd, int upbd)    //function to bound number between lowbd & upbd
{
    if(!(num>=lowbd&&num<=upbd))
    {
        cout<<"The entered number must be between "<<lowbd<<" and "<<upbd<<".\n";
        cout<<"Enter again: ";
        cin>>num;
        cout<<"\n";
    }

}
void limit1(string &name, int upsize)       //function to bound string character less than upsize
{
    if(name.size()>upsize)
    {
      cout<<"The entered name must be lessthan "<<upsize<<".\n";
      cout<<"Enter again: ";
      cin>>name;
      cout<<"\n";
    }
}
void limit2(int date[3])    //function to bound number of date in appropriate way
{
    char a;
    if(!((1<=date[0]&&31>=date[0])&&(1<=date[1]&&12>=date[1])&&(1980<=date[2]&&2100>=date[2])))
    {
      cout<<"The entered date must be between 1 & 31; month must be between 1 & 12 and year must be between 1980 & 2100.\n";
      cout<<"Enter again: ";
      cin>>date[0]>>a>>date[1]>>a>>date[2];
      cout<<"\n";
    }
}





//Data structure of Book
struct Book{// A node represent each book.
int ISBN;
string Author;
string Title;
int Publishing_date[3];
int No_page;
int Total_quantity;
};
//MAIN BOOK LIST ADT
class BookList
{
private:
    struct Node{
    Book book1;
    Node *nxt;
    Node *prv;
    };
    Node *head,*temp,*curr;
    int pos;
public:
	void Menu();// Menu-driver function
	//Books' doubly linked list ADT
    BookList()
    {
    head = NULL;
    }
    void Add_book();
    void Update_book();
    void Display_book();
    void Delete_book();
	void Search_book();
    //Books file ADT: to save book list change in the file
    void copy_file();
    void save_list();

};

// function for adding book
void BookList::Add_book() //:: define function out side the class scope resolution operator
{
Book book2;
char c,d;
int choose;
m: //point m to use unconditional jump using goto operation.
cout<<"\n\n\n\t\t\t Add Book in Book List at\n";
cout<<"\t\t\t| _____ #1) Add Book in the Beginning _____________________|\n";       //Display  choice
cout<<"\t\t\t|                                                          |\n";
cout<<"\t\t\t| _____ #2) Add Book at the End ___________________________|\n";
cout<<"\t\t\t|                                                          |\n";
cout<<"\t\t\t| _____ #3) In its position assuming sorted based on title_|\n";
cout<<"\t\t\t|                                                          |\n";
cout<<"\t\t\t| _____ #4) In its position assuming sorted based on ISBN__|\n";
cout<<"\t\t\t|                                                          |\n";
cout<<"\t\t\t| _____        #5) <- Back to main menu      ______________|\n";
cout<<"\t\t\t|                                                          |\n";
cout<<"\n\t Please enter your choice: ";
cin>>choose;


switch(choose)
{
case 1:// at the beginning
        temp= new Node;
        cout<<"\nEnter ISBN of the book: ";
        cin>>temp->book1.ISBN;
        limit(temp->book1.ISBN,0,9999999);
        cout<<"\nEnter Author of the book: ";
        cin>>temp->book1.Author;
        limit1(temp->book1.Author, 20);
        cout<<"\nEnter Title of the book: ";
        cin>>temp->book1.Title;
        limit1(temp->book1.Title, 20);
        cout<<"\nEnter number of page of the book: ";
        cin>>temp->book1.No_page;
        limit(temp->book1.No_page,0,9999);
        cout<<"\nEnter publication date of the book(DD/MM/YY)[e.g. 2/3/2023]: ";
        cin>>temp->book1.Publishing_date[0]>>c>>temp->book1.Publishing_date[1]>>d>>temp->book1.Publishing_date[2];
        limit2(temp->book1.Publishing_date);
        cout<<"\nEnter Total Quantity of the book: ";
        cin>>temp->book1.Total_quantity;
        limit(temp->book1.Total_quantity,0,99);
        temp->nxt=NULL;
        temp->prv=NULL;

        //if it is empty
        if(head==NULL){
            temp->nxt=head;
            head=temp;
        }else{
            temp->nxt=head;
            head->prv=temp;
            head = temp;}
        break;
case 2: // at the end
        temp= new Node;
        cout<<"\nEnter ISBN of the book: ";
        cin>>temp->book1.ISBN;
        limit(temp->book1.ISBN,0,9999999);
        cout<<"\nEnter Author of the book: ";
        cin>>temp->book1.Author;
        limit1(temp->book1.Author, 20);
        cout<<"\nEnter Title of the book: ";
        cin>>temp->book1.Title;
        limit1(temp->book1.Title, 20);
        cout<<"\nEnter number of page of the book: ";
        cin>>temp->book1.No_page;
        limit(temp->book1.No_page,0,9999);
        cout<<"\nEnter publication date of the book[e.g. 2/3/2023]: ";
        cin>>temp->book1.Publishing_date[0]>>c>>temp->book1.Publishing_date[1]>>d>>temp->book1.Publishing_date[2];
        limit2(temp->book1.Publishing_date);
        cout<<"\nEnter Total Quantity of the book: ";
        cin>>temp->book1.Total_quantity;
        temp->nxt=NULL;
        temp->prv=NULL;

        //if it is empty
        if(head==NULL){
            temp->nxt=head;
            head=temp;
        }else if(head!=NULL){
            curr=head;
            while(curr->nxt!= nullptr){
                curr=curr->nxt;
                }
            curr->nxt=temp;
            temp->prv=curr;
        }

        break;
case 3: //// inserting assuming it is sorted based on title
        temp= new Node;
        cout<<"\nEnter ISBN of the book: ";
        cin>>temp->book1.ISBN;
        limit(temp->book1.ISBN,0,9999999);
        cout<<"\nEnter Author of the book: ";
        cin>>temp->book1.Author;
        limit1(temp->book1.Author, 20);
        cout<<"\nEnter Title of the book: ";
        cin>>temp->book1.Title;
        limit1(temp->book1.Title, 20);
        cout<<"\nEnter number of page of the book: ";
        cin>>temp->book1.No_page;
        limit(temp->book1.No_page,0,9999);
        cout<<"\nEnter publication date of the book[e.g. 2/3/2023]: ";
        cin>>temp->book1.Publishing_date[0]>>c>>temp->book1.Publishing_date[1]>>d>>temp->book1.Publishing_date[2];
        limit2(temp->book1.Publishing_date);
        cout<<"\nEnter Total Quantity of the book: ";
        cin>>temp->book1.Total_quantity;
        temp->nxt=NULL;
        temp->prv=NULL;

        //if it is empty
        if(head==NULL){
            temp->nxt=head;
            head=temp;
        }else{
        if(head->book1.Title>=temp->book1.Title){
            temp->nxt= head;
            head->prv=temp;
            head=temp;}
        else{
            curr = head;
            while(curr->nxt != NULL && curr->nxt->book1.Title<temp->book1.Title){
                curr=curr->nxt;
                }
            temp->nxt=curr->nxt;
            if(curr->nxt!=NULL){curr->nxt->prv=temp;}
            curr->nxt = temp;
            temp->prv=curr;}}
            break;
case 4: // inserting assuming it is sorted based on ISBN
        temp= new Node;
        cout<<"\nEnter ISBN of the book: ";
        cin>>temp->book1.ISBN;
        limit(temp->book1.ISBN,0,9999999);
        cout<<"\nEnter Author of the book: ";
        cin>>temp->book1.Author;
        limit1(temp->book1.Author, 20);
        cout<<"\nEnter Title of the book: ";
        cin>>temp->book1.Title;
        limit1(temp->book1.Title, 20);
        cout<<"\nEnter number of page of the book: ";
        cin>>temp->book1.No_page;
        limit(temp->book1.No_page,0,9999);
        cout<<"\nEnter publication date of the book[e.g. 2/3/2023]: ";
        cin>>temp->book1.Publishing_date[0]>>c>>temp->book1.Publishing_date[1]>>d>>temp->book1.Publishing_date[2];
        limit2(temp->book1.Publishing_date);
        cout<<"\nEnter Total Quantity of the book: ";
        cin>>temp->book1.Total_quantity;
        temp->nxt=NULL;
        temp->prv=NULL;

        //if it is empty
        if(head==NULL){
            temp->nxt=head;
            head=temp;
        }else{
        if(head->book1.ISBN>=temp->book1.ISBN){
            temp->nxt= head;
            head->prv=temp;
            head=temp;}
        else{
            curr = head;
            while(curr->nxt != NULL && curr->nxt->book1.ISBN<temp->book1.ISBN){
                curr=curr->nxt;}
            temp->nxt=curr->nxt;
            if(curr->nxt!=NULL){curr->nxt->prv=temp;}
            curr->nxt = temp;
            temp->prv=curr;}}
            break;
case 5: //Back to menu
    Menu();
    break;
default:
    cout<<"\n\t\tInvalid Choice\n";
}
goto m; //to go to point m
}

//function to update Books' detail by traversing using ISBN
void BookList::Update_book(){
	Book book2;
	int isbn;
	char c,d;
    if(head==NULL){
		cout<<"\nThe BookList is empty.";}
	else {
	cout<<"\nEnter ISBN of the book you want to update: ";
	cin>>isbn;
	limit(isbn,0,9999999);
	curr=head;
    while(curr!=NULL&&curr->book1.ISBN!=isbn){
        curr=curr->nxt;
        }
    if(curr == NULL) // if There is no book with that ISBN
	{cout<<"\nThere is no book with that ISBN.";}
    else{// if There is book with that ISBN, Enter Updated data
		cout<<"\nEnter updated ISBN of the book: ";
		cin>>book2.ISBN;
		limit(book2.ISBN,0,9999999);
		cout<<"\nEnter updated Author of the book: ";
		cin>>book2.Author;
        limit1(book2.Author, 20);
		cout<<"\nEnter updated Title of the book: ";
		cin>>book2.Title;
        limit1(book2.Title, 20);
		cout<<"\nEnter updated number of page of the book: ";
		cin>>book2.No_page;
        limit(book2.No_page,0,9999);
		cout<<"\nEnter updated publication date of the book[e.g. 2/3/2023]: ";
		cin>>book2.Publishing_date[0]>>c>>book2.Publishing_date[1]>>d>>book2.Publishing_date[2];
        limit2(book2.Publishing_date);
		cout<<"\nEnter updated Total Quantity of the book: ";
		cin>>book2.Total_quantity;
		temp->book1=book2;
		cout<<"\n\t\t***** Successfully updated *****\n";
		}

	}

}
//Function that Display all the list
void BookList::Display_book(){
  if(head==NULL)
  {
     cout<<"The Book list is empty\n";
  }
  else
  {
  	curr=head;
  	//for designing purpose
      cout<<"\n\n ________________________________________________________________________________________________\n";
      cout<<"|"<<setw(15)<<"ISBN"<<"|"<<setw(21)<<"Author of    "<<"|"<<setw(21)<<"Title of   "<<"|"<<setw(13)<<"Publication "<<"|"<<setw(13)<<"  Number of  "<<"|"<<setw(8)<<" Total  "<<"|"<<"\n";
      cout<<"|"<<setw(15)<<"code"<<"|"<<setw(21)<<" Book        "<<"|"<<setw(21)<<"  Book     "<<"|"<<setw(13)<<"date of book"<<"|"<<setw(13)<<"pages of book"<<"|"<<setw(8)<<"Quantity"<<"|"<<"\n";
      cout<<"|________________________________________________________________________________________________|\n";

      //traversing the list
      while(curr!=NULL)
      {
           cout<<"|"<<setw(15)<<curr->book1.ISBN<<"|"<<setw(21)<<curr->book1.Author<<"|";
           cout<<setw(21)<<curr->book1.Title<<"|"<<setw(3)<<curr->book1.Publishing_date[0];
           cout<<"/"<<setw(3)<<curr->book1.Publishing_date[1]<<"/"<<setw(5)<<curr->book1.Publishing_date[2];
           cout<<"|"<<setw(13)<<curr->book1.No_page<<"|"<<setw(8)<<curr->book1.Total_quantity<<"|"<<"\n";
           curr=curr->nxt;
      }
      cout<<" ------------------------------------------------------------------------------------------------\n";
  }
}
//To delete book detail
void BookList::Delete_book(){
	Book book2;
	int isbn;
	if(head==NULL){// check the booklist is whether empty or not
		cout<<"\nThe BookList is empty.";
		}
	else {
	cout<<"\nEnter ISBN of the book you want to delete: ";
	cin>>isbn;
	limit(isbn,0,9999999);
    curr=head;
    while(curr!=NULL&&curr->book1.ISBN!=isbn){
        curr=curr->nxt;}
    if(curr==NULL){
    	cout<<"The book with this ISBN is not found in list";
	}else if(curr->prv!=NULL){
		curr->prv->nxt=curr->nxt;
	}else
		head=curr->nxt;
	if (curr->nxt!=NULL)
		curr->nxt->prv=curr->prv;
	delete curr;
	cout<<"\n\t\t**** Successfully Deleted ***** \n";
	}
}
//function that search book and display book detail
void BookList::Search_book(){
		m:
		Book book2;
		char c,d;
		string title;
		string author;
		int isbn;
		int choose;
		if(head==NULL){
		cout<<"\nThe booklist is empty.";
		return;
		}
		cout<<"\n\n\n\t\t\t Search Book in Book List:\n";
		cout<<"\t\t\t|_____ #1) Search Book Title _____|\n";       //Display your choice
		cout<<"\t\t\t|                               |\n";
		cout<<"\t\t\t|_____ #2) Search Book Author ____|\n";
		cout<<"\t\t\t|                               |\n";
		cout<<"\t\t\t|_____ #3) Search Book ISBN ______|\n";
		cout<<"\t\t\t|                               |\n";
		cout<<"\t\t\t|_____ #4) Back to main menu _____|\n";
		cout<<"\t\t\t|                               |\n";
		cout<<"\n\t        Please enter your choice: ";
		cin>>choose;
		switch(choose)
		{
		case 1://search based on title
			cout<<"\nEnter Title of the book you are searching for: ";
			cin>>title;
            limit1(title, 20);
			curr=head;
			while(curr!=NULL&&curr->book1.Title!=title){
			curr=curr->nxt;
			}
			if(curr==NULL){
			cout<<"The book with this title is not found in list";
			}else {
				cout<<"\nISBN of the book: "<<curr->book1.ISBN;
				cout<<"\nAuthor of the book: "<<curr->book1.Author;
				cout<<"\nTitle of the book: "<<curr->book1.Title;
				cout<<"\nNumber of page of the book: "<<curr->book1.No_page;
				cout<<"\nPublication date of the book: "<<curr->book1.Publishing_date[0]<<"/"<<curr->book1.Publishing_date[1]<<"/"<<curr->book1.Publishing_date[2];
				cout<<"\nTotal Quantity of the book: "<<curr->book1.Total_quantity;
			}
		    break;
		case 2://search based on Author
		    cout<<"\nEnter Author of the book you are searching for: ";
			cin>>author;
            limit1(author, 20);
			curr=head;
			while(curr!=NULL&&curr->book1.Author!=author){
			curr=curr->nxt;}
			if(curr==NULL){
			cout<<"The book with this title is not found in list";
			}else {
				cout<<"\nISBN of the book: "<<curr->book1.ISBN;
				cout<<"\nAuthor of the book: "<<curr->book1.Author;
				cout<<"\nTitle of the book: "<<curr->book1.Title;
				cout<<"\nNumber of page of the book: "<<curr->book1.No_page;
				cout<<"\nPublication date of the book: "<<curr->book1.Publishing_date[0]<<"/"<<curr->book1.Publishing_date[1]<<"/"<<curr->book1.Publishing_date[2];
				cout<<"\nTotal Quantity of the book: "<<curr->book1.Total_quantity;
			}
		    break;
		case 3://Search based on ISBN
		    cout<<"\nEnter ISBN of the book you are searching for: ";
			cin>>isbn;
			limit(isbn,0,9999999);
			curr=head;
			while(curr!=NULL&&curr->book1.ISBN!=isbn){
			curr=curr->nxt;}
			if(curr==NULL){
			cout<<"The book with this title is not found in list";
			}else {
				cout<<"\nISBN of the book: "<<curr->book1.ISBN;
				cout<<"\nAuthor of the book: "<<curr->book1.Author;
				cout<<"\nTitle of the book: "<<curr->book1.Title;
				cout<<"\nNumber of page of the book: "<<curr->book1.No_page;
				cout<<"\nPublication date of the book: "<<curr->book1.Publishing_date[0]<<"/"<<curr->book1.Publishing_date[1]<<"/"<<curr->book1.Publishing_date[2];
				cout<<"\nTotal Quantity of the book: "<<curr->book1.Total_quantity;
			}
			break;
		case 4:
		    Menu();     //to go back to menu
		    break;
		default:
		    cout<<"Please select from given options\n";
		}
		goto m;
		}

//To copy all data from file to Book list
void BookList::copy_file(){
  fstream data;
  Book book2;
  int isbn, page, amount, p_date[3];
  string author, title;
  data.open("DataBase.txt",ios::in);
  // if the file doesn't exist or it is empty
  if(!data)
  { data.close();
    return;
  }else//if the file exist trace all data and store it to book list
  {
  	  curr=head;

      while (data >> isbn >> title >> author >> p_date[0] >> p_date[1] >> p_date[2] >> page >> amount) {
        temp = new Node();
        temp->book1.ISBN = isbn;
        temp->book1.Title = title;
        temp->book1.Author = author;
        temp->book1.Publishing_date[0] = p_date[0];
        temp->book1.Publishing_date[1] = p_date[1];
        temp->book1.Publishing_date[2] = p_date[2];
        temp->book1.No_page = page;
        temp->book1.Total_quantity = amount;

        temp->nxt = NULL;
        temp->prv = NULL;

        if (head == NULL) {
            temp->nxt=head;
            head=temp;
            }
        else {
            while (curr->nxt != nullptr) {
                curr = curr->nxt;
            }
            curr->nxt = temp;
            temp->prv = curr;
        }
    }
      data.close();} // at last close the file
}

void BookList::save_list(){
	fstream data, data1;
    Book book2;
	int isbn, page, amount, p_date[3];
	string author, title;
	data.open("DataBase.txt",ios::in);
	// if the file doen't exist or it is empty
    if(!data)
    {
    	curr=head;
        data.open("DataBase.txt",ios::app|ios::out);
        while(curr!=NULL)
        {
            isbn=curr->book1.ISBN;
            title=curr->book1.Title;
            author=curr->book1.Author;
            p_date[0]=curr->book1.Publishing_date[0];
            p_date[1]=curr->book1.Publishing_date[1];
            p_date[2]=curr->book1.Publishing_date[2];
            page=curr->book1.No_page;
            amount=curr->book1.Total_quantity;
            data<<isbn<<" "<<title<<" "<<author<<" "<<p_date[0]<<" "<<p_date[1]<<" "<<p_date[2]<<" "<<page<<" "<<amount<<" \n";
            curr=curr->nxt;
        }
		data.close();
        cout<<"\nSuccess fully saved\n";
    }
    else
    {
      data1.open("DataBase1.txt", ios::app|ios::out);
      curr=head;
      while(curr!=NULL)
      {
		isbn=curr->book1.ISBN;
		title=curr->book1.Title;
		author=curr->book1.Author;
		p_date[0]=curr->book1.Publishing_date[0];
		p_date[1]=curr->book1.Publishing_date[1];
		p_date[2]=curr->book1.Publishing_date[2];
		page=curr->book1.No_page;
		amount=curr->book1.Total_quantity;
		data1<<isbn<<" "<<title<<" "<<author<<" "<<p_date[0]<<" "<<p_date[1]<<" "<<p_date[2]<<" "<<page<<" "<<amount<<" "<<"\n";
		curr=curr->nxt;
		}
		data.close();
        data1.close();
        remove("DataBase.txt");
        rename("DataBase1.txt","DataBase.txt");
        }
}

//function for menu driven
void BookList::Menu(){
	  m: //point m
  int choice;

 cout<<"\t\t\t\t_________________________________________  |\n";
  cout<<"\t\t\t\t***************************************** |\n";
  cout<<"\t\t\t\t                                          |\n";
  cout<<"\t\t\t\t         Automated Library                |\n";
  cout<<"\t\t\t\t         Management System                |\n";
  cout<<"\t\t\t\t_________________________________________ |\n";
  cout<<"\t\t\t\t***************************************** |\n";
  cout<<"\t\t\t\t                                          |\n";
    	copy_file();
  		cout<<"\t\t\t\t|*|         main menu             |*\n";
  		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*|    #1) Add book               |*\n"; // display your choices
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*|    #2) Delete book detail     |*\n";
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*|    #3) Display book detail    |*\n";
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*|    #4) Update book detail     |*\n";
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*|    #5) Search book            |*\n";
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t|*| ********** #6) Exit ********* |*\n";
		cout<<"\t\t\t\t|*|                               |*\n";
		cout<<"\t\t\t\t Please Select: ";
		cin>>choice;// enter your choice

		switch(choice)
		{
		case 1:// to add book
			Add_book();
			break;
		case 2:// to delete book by showing the book list
			Display_book();
			Delete_book();
			break;
		case 3://to view book list
			Display_book();
			break;
		case 4://to update book detail by showing list
			Display_book();
			Update_book();
			break;
		case 5://to search book
			Search_book();
			break;
		case 6:// to save file and exit the console
			save_list();
			cout<<"\n\n\n\n\n\t\t\t*********System Exited********\n\n\n\n\n\n";
			exit(0);        // to close program
		default:
			cout<<"Please, select from given options\n";
		}
  goto m;
}

int main()
{
    BookList s;  //declare booklist s
    s.Menu(); //call main menu of s
}

 
