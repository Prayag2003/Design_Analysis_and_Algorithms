#include <bits/stdc++.h>
using namespace std;
int numOfCities;

void printDataBase(string names[], int x_DB[], int y_DB[])
{
    for (int i = 0; i < numOfCities; i++)
    {
        cout << names[i] << " --> X Coordinate = " << x_DB[i] << "  and Y Coordinate = " << y_DB[i] << "\n";
    }
}

void searchByName(string queryCity, string names[], int x_DB[], int y_DB[])
{
    for (int i = 0; i < numOfCities; i++)
    {
        if (queryCity == names[i])
        {
            cout << queryCity << " is found and is located at X-Coordinate = " << x_DB[i] << " and Y-Coordinate =" << y_DB[i] << "\n";
            return;
        }
    }
    cout << queryCity << " is not available in the database\n";
}

void searchByCoordinates(int x, int y, string names[], int x_DB[], int y_DB[])
{
    for (int i = 0; i < numOfCities; i++)
    {
        if (x == x_DB[i] && y == y_DB[i])
        {
            cout << "City Found is  " << names[i] << "\n";
            return;
        }
    }
    cout << "The City with such Coordinates is not found in the DataBase \n ";
}

void deleteByName(string queryCity, string *names, int *x_DB, int *y_DB)
{
    int i = 0;
    while (queryCity != names[i] && i < numOfCities)
    {
        ++i;
    }
    string deleted = names[i];
    if (i == numOfCities)
    {
        cout << queryCity << " is Not Found in the DataBase ! \n ";
    }

    /* Shifting all Cities so as to delete the QueryCity */
    for (int j = i + 1; j < numOfCities; j++)
    {
        names[j - 1] = names[j];
        x_DB[j - 1] = x_DB[j];
        y_DB[j - 1] = y_DB[j];
    }
    numOfCities--;
    cout << deleted << " is been DELETED !\n";
}

void deleteByCoordinates(int x, int y, string *names, int *x_DB, int *y_DB)
{
    int key = 0;
    for (int i = 0; i < numOfCities; i++)
    {
        if (x == x_DB[i] && y == y_DB[i])
        {
            key = i;
        }
    }
    /* Shifting all Cities so as to delete the QueryCity */
    for (int j = key + 1; j < numOfCities; j++)
    {
        names[j - 1] = names[j];
        x_DB[j - 1] = x_DB[j];
        y_DB[j - 1] = y_DB[j];
    }
    numOfCities--;
    cout << names[key] << " is been deleted !\n";
}

void availableCitiesWithinRadius(int x, int y, int dist, string names[],
                                 int x_DB[], int y_DB[])
{
    for (int i = 0; i < numOfCities; i++)
    {
        int x_dist = x - x_DB[i];
        int y_dist = x - y_DB[i];
        int radius = pow(x_dist, 2) + pow(y_dist, 2);
        double distance = sqrt(radius);
        if (distance <= dist)
        {
            cout << names[i] << " is in Range of " << dist << " km \n";
        }
    }
}

int main()
{
    cout << "--------------Welcome to Prayag's MegaCities DataBase--------------\n\n";
    cout << "Enter Number of Cities into your Database : \n";
    cin >> numOfCities;

    string names[numOfCities];
    int x_DB[numOfCities];
    int y_DB[numOfCities];

    for (int i = 0; i < numOfCities; i++)
    {
        cout << "\nEnter City Name : ";
        cin >> names[i];
        cout << "Enter X-Coordinate : ";
        cin >> x_DB[i];
        cout << "Enter Y-Coordinate : ";
        cin >> y_DB[i];
    }

doYouWantToContinue:
    while (true)
    {
        char choice;
        cout << "Enter Your Queries : \n";
        cout << " 1. Search a city with Name :\n";
        cout << " 2. Search a city with Coordinates :\n";
        cout << " 3. Delete a city with Name :\n";
        cout << " 4. Delete a city with Coordinates :\n";
        cout << " 5. Find all cities within a given distance : \n";
        cout << " 6. To View City DataBase : \n";
        cout << "Enter Your Choice :\n";
        cin >> choice;

        switch (choice)
        {
            {
            case '1':
                cout << "Enter the name of city you want to search :\n";
                string queryCity;
                cin >> queryCity;

                searchByName(queryCity, names, x_DB, y_DB);
                break;
            }
            {
            case '2':
                cout << "Enter the Coordinates of city you want to Search :\n";
                int x, y;
                cout << "Enter X - Coordinate : ";
                cin >> x;
                cout << "Enter Y - Coordinate : ";
                cin >> y;
                searchByCoordinates(x, y, names, x_DB, y_DB);
                break;
            }
            {
            case '3':
                cout << "Enter the name of city you want to Delete :\n";
                string queryCity;
                cin >> queryCity;

                deleteByName(queryCity, names, x_DB, y_DB);
                break;
            }
            {
            case '4':
                cout << "Enter the Coordinates of city you want to delete :\n";
                int x, y;
                cout << "Enter X - Coordinate : ";
                cin >> x;
                cout << "Enter Y - Coordinate : ";
                cin >> y;
                deleteByCoordinates(x, y, names, x_DB, y_DB);
                break;
            }
            {
            case '5':
                cout << "Enter You Current Coordinates and Radius : \n";
                int x, y, dist;
                cout << "Enter X - Coordinate : ";
                cin >> x;
                cout << "Enter Y - Coordinate : ";
                cin >> y;
                cout << "Enter Radius Distance : ";
                cin >> dist;
                availableCitiesWithinRadius(x, y, dist, names, x_DB, y_DB);
                break;
            }
            {
            case '6':
                printDataBase(names, x_DB, y_DB);
                break;
            }
        }

        cout << "To Quit :- Press 'q' .\n To Search more Queries : Press Any Other Key, \n";
        char check;
        cin >> check;
        if (check != 'q')
            goto doYouWantToContinue;
        return 0;
    }
}
