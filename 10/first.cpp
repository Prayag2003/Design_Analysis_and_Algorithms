#include <bits/stdc++.h>
using namespace std;

// Define a struct to store license growth rate and index
struct License
{
    double growth_rate;
    int index;
};

bool compareLicenses(const License &license1, const License &license2)
{
    return license1.growth_rate < license2.growth_rate;
}

vector<int> findLicenseOrder(const vector<double> &growth_rates)
{
    int n = growth_rates.size();
    vector<License> licenses(n);

    for (int i = 0; i < n; ++i)
    {
        licenses[i].growth_rate = growth_rates[i];
        licenses[i].index = i + 1;
    }

    sort(licenses.begin(), licenses.end(), compareLicenses);

    vector<int> order(n);
    double total_cost = 0.0;

    for (int i = 0; i < n; ++i)
    {
        order[i] = licenses[i].index;
        total_cost += 100.0 * licenses[i].growth_rate;

        for (int j = i + 1; j < n; ++j)
        {
            licenses[j].growth_rate *= licenses[i].growth_rate;
        }
    }
    cout << "Total cost: $" << total_cost << endl;
    return order;
}

int main()
{
    vector<double> growth_rates = {2.0, 3.0, 1.5, 1.8, 2.5};
    vector<int> order = findLicenseOrder(growth_rates);
    cout << "License order : ";

    for (int i = 0; i < order.size(); ++i)
    {
        cout << order[i] << " ";
    }
    cout << endl;
}
