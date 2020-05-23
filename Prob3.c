/* Structures and Pointers - Problem set #3 */

/* Book */
struct Book
{
	unsigned int isbn;
	char title[40];
	char publisher[20];
	char author1[35];
	char author2[35];
	unsigned short num_editions; /* Maximum value = 10 */
	unsigned int num_pages[10];  /* Pages for each edition */
};

/* BooksLibrary */
struct BooksLibrary
{
	unsigned short num_books;	  /* Max = 1000 */
	struct Book books_set[1000];  /* Library can keep only a max of 1000 unique books - there could be many copies of each though */
	unsigned short copies[1000];  /* number of copies for each book */
	struct Book* last_issued_book;
	struct Book* popular_book[5]; /* Top 5 popular books */
};

void InitializeBook(struct Book *pbook)
{
	if (pbook == NULL)
		return;
		
	pbook->isbn = 0;
	pbook->title[0] = '\0';
	pbook->publisher[0] = '\0';
	pbook->author1[0] = '\0';
	pbook->author2[0] = '\0';
	pbook->num_editions = 0;
	for (int i = 0; i < 10; i++)
		pbook->num_pages[i] = 0;
}

void InitializeBooksLibrary(struct BooksLibrary *pblibrary)
{
	/* TODO: Implement this function */
}


/*
Question 1:  Draw the memory layout of the struct Book. What is the total size of Book?
*/

/*
Question 2:  Draw the memory layout of the struct BooksLibrary. What is the total size of BooksLibrary?
*/

/*
Question 3:  Implement the function "InitializeBooksLibrary" to initialize a books library object passed into it
*/


