#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

class Book{
    friend class BookStore;
    static unordered_set<string> check;
    const char *isbn;
    const char *title, *author;
    int price;

public:
    Book(const char *isbn, const char *title, const char *author, int price)
    : isbn(isbn), title(title), author(author), price(price) {}


};
unordered_set<string> Book::check;

class BookStore{
    static unordered_map<string, int>  freq;
    vector<Book> listBooks;
    int num;

public:
    BookStore() :num(0){}

    void books(){
        for(auto item : freq)
                cout<<item.first<<endl;
    }

    void addBook(Book b){
        if(freq.find((string)b.isbn)==freq.end()){
            listBooks.push_back(b);
            freq[(string)b.isbn]=1;
        }
        else freq[(string)b.isbn]++;
    }
    int noOfCopies(const char *isbn){
        if(freq.find((string)isbn)==freq.end()){
                return 0;
        }
        else return freq[(string)isbn];
    }
    int totalPrice(){
        int total=0;
        for(Book b : listBooks){
            total+= (b.price*freq[(string)b.isbn]);
        }

	return total;
    }
    void showBooks(){
        for(Book b : listBooks){
            cout<<"Book: Title: "<<b.title<<"\n\
            Number of copies: "<<freq[(string)b.isbn]<<endl;
        }
    }

};
unordered_map<string, int> BookStore::freq;

int main(){

    BookStore bs;

    Book books[5] = {
        {
            "12345678", "Introduction To Algorithms", "CLRS", 999
        },
        {
            "12345679", "Elements of Programming Interviews", "Anand-Tsung-Amit", 650
        },
        {
            "12345680", "OOP with C++", "E. Balagurusamy", 450
        },
        {
            "12345681", "Computer Organization", "W. Stallings", 900
        },
        {
            "12345682", "Database Essentials", "Kroth", 850
        }
    };

    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            bs.addBook(books[i]);
        }
    }

    bs.showBooks();



    return 0;
}
