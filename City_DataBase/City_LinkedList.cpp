#include <bits/stdc++.h>
using namespace std;
int numOfCities;

class cityLinklist
{
public:
    string cityName;
    int x;
    int y;
    cityLinklist *nextCity;

    cityLinklist(string cityName, int x, int y)
    {
        this->cityName = cityName;
        this->x = x;
        this->y = y;
    }
} *firstCity = NULL, *lastCity = NULL;

void insertAtEnd(cityLinklist *&lastCity, string newCity, int x, int y)
{
    cityLinklist *last = new cityLinklist(newCity, x, y);
    // we use a variable called tail to reach to the pointer of the last element so as to insert new element into the LL

    lastCity->nextCity = last;
    lastCity = last;
}

void printDB()
{
    cityLinklist *temp = firstCity;
    while (temp != NULL)
    {
        cout << temp->cityName << " " << temp->x << " " << temp->y << "\n";
        temp = temp->nextCity;
    }
    cout << "\n";
}

void searchCityByName(string city)
{
    cityLinklist *temp = firstCity;
    while (temp->cityName != city && temp != NULL)
    {
        temp = temp->nextCity;
    }
    temp == NULL ? cout << "NOT FOUND \n" : cout << "CITY FOUND\n";
}

void searchCityByCoordinates(int x, int y)
{
    bool found = false;
    cityLinklist *temp = firstCity;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            found = true;
            break;
        }
        temp = temp->nextCity;
    }
    found == false ? cout << "NOT FOUND \n" : cout << "CITY FOUND\n";
}

void deleteCityByName(string city)
{
    cityLinklist *temp = firstCity;
    cityLinklist *header = firstCity;
    cityLinklist *prev = firstCity;
    int pos = 0;

    cout << city << " is successfully Deleted \n";
    /* If found at 1st Position */
    if (temp->cityName == city)
    {
        firstCity = firstCity->nextCity;
        return;
    }

    // Finding the Position of the city to be deleted
    while (temp->cityName != city)
    {
        pos++;
        temp = temp->nextCity;
    }

    while (pos--)
    {
        prev = header;
        header = header->nextCity;
    }
    prev->nextCity = header->nextCity;
    header->nextCity = NULL;
}

void deleteCityByCoordinates(int x, int y)
{
    cityLinklist *temp = firstCity;
    cityLinklist *header = firstCity;
    cityLinklist *prev = firstCity;
    int pos = 0;

    cout << "City with " << x << " and " << y << " Coordinates is successfully Deleted \n";
    /* If found at 1st Position */
    if (temp->x == x && temp->y == y)
    {
        firstCity = firstCity->nextCity;
        return;
    }

    // Finding the Position of the city to be deleted
    while (temp->x != x && temp->y != y)
    {
        pos++;
        temp = temp->nextCity;
    }

    while (pos--)
    {
        prev = header;
        header = header->nextCity;
    }
    prev->nextCity = header->nextCity;
    header->nextCity = NULL;
}

vector<string> availableCitiesWithinRadius(int x, int y, int dist)
{
    bool found = false;
    vector<string> cities;
    cityLinklist *start = firstCity;
    while (start != NULL)
    {
        int x_dist = x - start->x;
        int y_dist = x - start->y;
        int radius = pow(x_dist, 2) + pow(y_dist, 2);
        double distance = sqrt(radius);

        if (distance == 0)
            continue;
        if (distance <= dist)
        {
            found = true;
            string name = start->cityName;
            cities.push_back(name);
        }

        start = start->nextCity;
    }

    if (cities.size() == 0)
    {
        return {};
    }
    else
        return cities;
}

int main()
{

    cout << "\n\n********************  Welcome To Prayag's MegaCity DataBase  ******************** \n\n";

    cout << "Enter Number of Cities : ";
    cin >> numOfCities;

    int x, y;
    string cityName;
    cout << "Enter First City Name :- ";
    cin >> cityName;
    cout << "Enter X-Coordinate :- ";
    cin >> x;
    cout << "Enter Y-Coordinate :- ";
    cin >> y;

    lastCity = new cityLinklist(cityName, x, y);
    firstCity = lastCity;

    for (int i = 1; i < numOfCities; i++)
    {
        cout << "Enter City Name :- ";
        cin >> cityName;
        cout << "Enter X-Coordinate :- ";
        cin >> x;
        cout << "Enter Y-Coordinate :- ";
        cin >> y;
        insertAtEnd(lastCity, cityName, x, y);
    }

doYouWantToContinue:
    cout << "Enter Your Queries : \n";
    cout << " 1. Search a city with Name :\n";
    cout << " 2. Search a city with Coordinates :\n";
    cout << " 3. Delete a city with Name :\n";
    cout << " 4. Delete a city with Coordinates :\n";
    cout << " 5. Find all cities within a given distance : \n";
    cout << " 6. To View City DataBase : \n";
    cout << "Enter Your Choice :\n";
    char choice;
    cin >> choice;

    switch (choice)
    {

    case '1':
    {
        /* Searching */
        cout << "Enter the name of the city you want to search : ";
        string cityQuery;
        cin >> cityQuery;
        searchCityByName(cityQuery);
        break;
    }

    case '2':
    {
        /*Search by Coordinates*/
        cout << "Enter the Coordinates you want to Find : ";
        int xCoordinate, yCoordinate;
        cin >> xCoordinate >> yCoordinate;
        searchCityByCoordinates(xCoordinate, yCoordinate);
        break;
    }
    /*  Delete City By Name */
    case '3':
    {
        cout << "Enter the name of the city you want to delete : ";
        string delCity;
        cin >> delCity;
        deleteCityByName(delCity);
        printDB();
        break;
    }

    case '4':
    {
        cout << "Enter the Coordinates of city you want to delete :\n";
        int x, y;
        cout << "Enter X - Coordinate : ";
        cin >> x;
        cout << "Enter Y - Coordinate : ";
        cin >> y;
        deleteCityByCoordinates(x, y);
        printDB();
        break;
    }

    case '5':
    {
        int x, y, radius;
        cout << "Enter your X-Coordiante : ";
        cin >> x;
        cout << "Enter your Y-Coordiante : ";
        cin >> y;
        cout << "Enter the Radius : ";
        cin >> radius;
        vector<string> citiesWithinRadius = availableCitiesWithinRadius(x, y, radius);
        cout << "The Cities within Radius " << radius << " from X = " << x << " and Y = " << y << " are as follows : \n";
        for (auto &i : citiesWithinRadius)
        {
            cout << i << "\n";
        }
        break;
    }
    case '6':
    {
        printDB();
        break;
    }
    }

    cout << "To Quit :- Press 'q' .\n To Search more Queries : Press Any Other Key, \n";
    char check;
    cin >> check;
    if (check != 'q')
        goto doYouWantToContinue;
}