#include <iostream>
#include <cstring>
using namespace std;


struct Car
{
    char name[26];
    double price;
    int year;
    char Number[10];
    double razhod;
    int power;


};
Car car[100];
int n;
int MainMenu()
{
    int choice;
    cout<<"1 - Input"<<endl;
    cout<<"2 - Output"<<endl;
    cout<<"3 - Search by price"<<endl;
    cout<<"4 - Search by Number"<<endl;
    cout<<"5 - Search by Name"<<endl;
    cout<<"6 - Min power of car"<<endl;
    cout<<"7 - Sort by Name"<<endl;
    cout<<"8 - Fuel consumption:"<<endl;
    cout<<"9 - Sort by Price"<<endl;
    cout<<"10 - Add a car"<<endl;
    cout<<"11 - Remove a car"<<endl;
    cout<<"12 - Edit a car"<<endl;
    cout<<"13 - Sort by year"<<endl;
    cout<<"14 - Sort by name"<<endl;
    cout<<"0 - Exit"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    return choice;
}
void Input(Car &a)
{
    cin.ignore(100, '\n');
    cout<<"Name: ";
    cin.getline(a.name,26);
    cout<<"Number: ";
    cin>>a.Number;
    cout<<"Year: ";
    cin>>a.year;
    cout<<"Fuel consumption: ";
    cin>>a.razhod;
    cout<<"Price: ";
    cin>>a.price;
    cout<<"Power: ";
    cin>>a.power;


}
void Output()
{
    for(int i=0; i<n; i++)
    {
        cout<<"Car: "<<i+1<<endl;
        cout<<"Name: "<<car[i].name<<endl;
        cout<<"Number: "<<car[i].Number<<endl;
        cout<<"Year: "<<car[i].year<<endl;
        cout<<"Fuel consumption:: "<<car[i].razhod<<endl;
        cout<<"Price: "<<car[i].price<<endl;
        cout<<"Power: "<<car[i].power<<endl;
    }

}
void Search_by_Price()
{
    int search_price;
    cout<<"Enter Price: ";
    cin>>search_price;
    for(int i=0; i<n; i++)
    {
        if(search_price<car[i].price)
        {
            cout<<"Car: "<<i+1<<endl;
            cout<<"Name: "<<car[i].name<<endl;
            cout<<"Number: "<<car[i].Number<<endl;
            cout<<"Year: "<<car[i].year<<endl;
            cout<<"Fuel consumption: "<<car[i].razhod<<endl;
            cout<<"Price: "<<car[i].price<<endl;
            cout<<"Power: "<<car[i].power<<endl;
        }
    }

}
void Search_by_Number()
{
    char number[10];
    cout<<"Enter the cars number: ";
    cin>>number;
    for(int i=0; i<n; i++)
    {
        if(strcmp(number,car[i].Number)==0)
        {

            cout<<"Name: "<<car[i].name<<endl;
            cout<<"Number: "<<car[i].Number<<endl;
            cout<<"Year: "<<car[i].year<<endl;
            cout<<"Fuel consumption: "<<car[i].razhod<<endl;
            cout<<"Price: "<<car[i].price<<endl;
            cout<<"Power: "<<car[i].power<<endl;
        }
    }
}
void Search_by_Name()
{
    string Name;
    cout<<"Enter the Name: ";
    cin>>Name;
    for(int i=0; i<n; i++)
    {
        if(Name==car[i].name)
        {
            cout<<"Name: "<<car[i].name<<endl;
            cout<<"Number: "<<car[i].Number<<endl;
            cout<<"Year: "<<car[i].year<<endl;
            cout<<"Fuel consumption: "<<car[i].razhod<<endl;
            cout<<"Price: "<<car[i].price<<endl;
            cout<<"Power: "<<car[i].power<<endl;
        }
    }
}
void Power()
{
    double powers;
    cout<<"Enter a min power: ";
    cin>>powers;
    for(int i=0; i<n; i++)
    {
        if(powers<car[i].power)
        {
            cout<<"Name: "<<car[i].name<<endl;
            cout<<"Number: "<<car[i].Number<<endl;
            cout<<"Year: "<<car[i].year<<endl;
            cout<<"Fuel consumption: "<<car[i].razhod<<endl;
            cout<<"Price: "<<car[i].price<<endl;
            cout<<"Power: "<<car[i].power<<endl;
        }
    }
}
void Razhod_Na_Firmata()
{
    double raz=0;
    for(int i=0; i<n; i++)
    {
        raz=raz+car[i].price;
    }
    cout<<"Razhod na Firmata: "<<raz<<endl;
}
void Sort_by_Price()
{
    int ch;
    cout<<"1 - Low to high"<<endl;
    cout<<"2 - High to low"<<endl;
    cout<<"Choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(car[i].price > car[j].price)
                {

                    Car pom=car[i];
                    car[i]=car[j];
                    car[j]=pom;
                }
        break;
    }
    case 2:
    {
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(car[i].price < car[j].price)
                {

                    Car pom=car[i];
                    car[i]=car[j];
                    car[j]=pom;
                }
        break;
    }
    }
    Output();
}
void Add()
{
    Car a;
    n++;
    Input(a);
    car[n-1]=a;
}
void Remove()
{
    int pos;
    cout<<"Remove car number: ";
    cin>>pos;
    for(int i=pos-1; i<n; i++)
    {
        car[i]=car[i+1];
    }
    n--;
}
void Edit()
{
    int chp;
    int num;
    cout<<"Number of the car: ";
    cin>>num;
    cout<<"1 - Name"<<endl;
    cout<<"2 - Number"<<endl;
    cout<<"3 - Year"<<endl;
    cout<<"4 - Fuel consumption"<<endl;
    cout<<"5 - Price"<<endl;
    cout<<"6 - Power"<<endl;
    cin>>chp;
    switch(chp)
    {
    case 1:
    {
        cout<<"The new name: ";
        cin.getline(car[num-1].name,26);
        break;
    }
    case 2:
    {
        cout<<"The new number: ";
        cin>>car[num-1].Number;
        break;
    }
    case 3:
    {
        cout<<"The new year: ";
        cin>>car[num-1].year;
        break;
    }
    case 4:
    {
        cout<<"Nov razhod: ";
        cin>>car[num-1].razhod;
        break;
    }
    case 5:
    {
        cout<<"The new price: ";
        cin>>car[num-1].price;
        break;
    }
    case 6:
    {
        cout<<"The new power: ";
        cin>>car[num-1].power;
        break;
    }
    }
}
void Sort_razh()
{
    int ch;
    cout<<"1 - Low to high"<<endl;
    cout<<"2 - High to low"<<endl;
    cout<<"Choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(car[i].year > car[j].year)
                {

                    Car pom=car[i];
                    car[i]=car[j];
                    car[j]=pom;
                }
        break;
    }
    case 2:
    {
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(car[i].year < car[j].year)
                {

                    Car pom=car[i];
                    car[i]=car[j];
                    car[j]=pom;
                }
        break;
    }
    }

    Output();
}

void Sort_by_Name()
{

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(car[i].name, car[j].name)==1)
            {
                Car pom=car[i];
                car[i]=car[j];
                car[j]=pom;
            }
        }
    }
    Output();
}

int main()
{
    int choice;
    do
    {
        choice=MainMenu();
        switch(choice)
        {
        case 1:
        {
            cout<<"Broi koli: ";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                Input(car[i]);
            }
            break;
        }
        case 2:
        {
            Output();
            break;
        }
        case 3:
        {
            Search_by_Price();
            break;
        }
        case 4:
        {
            Search_by_Number();
            break;
        }
        case 5:
        {
            Search_by_Name();
            break;
        }
        case 6:
        {
            Power();
            break;
        }
        case 7:
        {

            break;
        }
        case 8:
        {
            Razhod_Na_Firmata();
            break;
        }
        case 9:
        {
            Sort_by_Price();
            break;
        }
        case 10:
        {
            Add();
            break;
        }
        case 11:
            Remove();
            break;
        case 12:
        {
            Edit();
            break;
        }
        case 13:
        {
            Sort_razh();
            break;
        }
        case 14:
        {
            Sort_by_Name();
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        }
    }
    while(choice!=0);
}
