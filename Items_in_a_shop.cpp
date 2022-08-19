#include <iostream>
#include <fstream>
using namespace std;
class Item
{

public:
    int price, quantity;
    string name;
    Item() {}
    Item(string n, int p, int q)
    {
        price = p;
        quantity = q;
        name = n;
    }
    friend ofstream &operator<<(ofstream &out, Item &i);
    friend ifstream &operator>>(ifstream &in, Item &i);
};

ofstream &operator<<(ofstream &out, Item &i)
{
    out << i.name << endl
        << i.price << endl
        << i.quantity << endl;
}

ifstream &operator>>(ifstream &in, Item &i)
{
    in >> i.name >> i.price >> i.quantity;
}

ostream & operator<<(ostream & cout,Item &i)
{
        cout<<"Name= " <<i.name<<endl
            << "Price= " <<i.price<<endl
            << "Quantity= " <<i.quantity<<endl;
        cout<<endl;
}

int main()
{
    int a;
    int p, q;
    string n;

    cout << "Enter number of product: ";
    cin >> a;
    Item *list[a];

    for (int i = 0; i < a; i++)
    {
        cout << "Enter name of product "<<i+1<<": ";
        cin >> n;

        cout << "Enter price of product: ";
        cin >> p;

        cout << "Enter quantity of product: ";
        cin >> q;

        cout<<endl;

        list[i] = new Item(n, p, q);
    }

    ofstream out("Shop.txt", ios::app);
    for (int i = 0; i < a; i++)
    {
        out << *list[i];
    }

    Item I;
    ifstream in("Shop.txt");
    for (int i = 0; i < a; i++)
    {
      in>>I;
      cout<<I;
    }

    return 0;
}