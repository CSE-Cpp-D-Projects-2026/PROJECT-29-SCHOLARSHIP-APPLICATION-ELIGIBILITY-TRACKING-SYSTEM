# include <iostream>
# include <string>
# include <vector>
# include <fstream>
using namespace std;
struct Scholarship{
    int id;
    string name;
    int year;
    int amount;
    float minmarks;
    float maxincome;
    bool active;
    
};


int main()
{
    vector<Scholarship>s;
    int choice;
    do
    {
        cout << "\n--- SCHOLARSHIP MANAGEMENT ---\n";
        cout << "1. Add Scheme\n";
        cout << "2. Display Schemes\n";
        cout << "3. Activate Scheme\n";
        cout << "4. Deactivate Scheme\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            Scholarship x;

            cout << "Enter Scheme ID: ";
            cin >> x.id;
            cout << "Enter Scheme Name: ";
            getline(cin, x.name);
            cout << "Enter Academic Year: ";
            cin>>x.year;
            cout << "Enter Benefit Amount: ";
            cin >> x.amount;
            cout << "Enter Minimum Marks: ";
            cin >> x.minmarks;
            cout << "Enter Maximum Family Income: ";
            cin >> x.maxincome;
            x.active = true;
            s.push_back(x);
            cout << "Scheme Added Successfully!\n";
        }

        else if (choice == 2)
        {
            for (int i = 0; i < s.size(); i++)
            {
                cout << "\nScheme ID: " << s[i].id;
                cout << "\nScheme Name: " << s[i].name;
                cout << "\nAcademic Year: " << s[i].year;
                cout << "\nBenefit Amount: " << s[i].amount;
                cout << "\nMinimum Marks: " << s[i].minmarks;
                cout << "\nMaximum Income: " << s[i].maxincome;
                cout << "\nStatus: "
                     << (s[i].active ? "Active" : "Inactive");
                cout << "\n";
            }
        }

        else if (choice == 3 || choice == 4)
        {
            int id;
            cout << "Enter Scheme ID: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i].id == id)
                {
                    s[i].active = (choice == 3);
                    cout << "Status Updated Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Scheme Not Found!\n";
        }

        else if (choice == 5)
        {
            cout << "Exiting Program...\n";
        }

        else
        {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}