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
class application{
   public:
   int studentid;
   string name;
   string program;
   int year;
   long int contact;
   int schemeid;
   int schemeyear;
   string appref;
   bool found;
   void input()
   {
    cout<<"Enter studentid :";
    cin>>studentid;

    cout<<"Enter name :";
    cin>>name;
    cout<<"Enter program :";
    cin>>program;
    cout<<"Enter year :";
    cin>>year;
    cout<<"Enter contact :";
    cin>>contact;
    cout<<"Enter schemeid :";
    cin>>schemeid;
    cout<<"Enter schemeyear :";
    cin>>schemeyear;
    cout<<"Enter appref :";
    cin>>appref;
   }
    void status(bool active)
    {

      if(active==true)
        {
            cout<<"Application Accepted";
        }
        else
        {
            cout<<"The Scheme is inactive.Application Rejected";
        }
    }

};


int main()
{
     ofstream fout("schemes.txt", ios::app);


    vector<Scholarship>s;
    bool found = false;
    bool active=false;
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

            bool duplicate=false;
            for(int i=0;i<s.size();i++)

            {
                if(s[i].id==x.id)
                {
                    duplicate=true;
                    break;
                }
            }
            if(duplicate)
            {
                cout<<"\nScheme already exists\n";
            }
            else
            {
            cin.ignore();
            cout << "Enter Scheme Name: ";
            getline(cin, x.name);
            cout << "Enter Academic Year: ";
            cin>>x.year;
            cout << "Enter Benefit Amount: ";
            cin>>x.amount;
            cout << "Enter Minimum Marks: ";
            cin>>x.minmarks;
            cout << "Enter Maximum Family Income: ";
            cin>>x.maxincome;
            x.active = true;
            s.push_back(x);
            cout << "Scheme Added Successfully!\n";


        fout << x.id << " "
       << x.name << " "
       << x.year << " "
       << x.amount << " "
       << x.minmarks << " "
       << x.maxincome << " "
       << x.active << endl;

       fout.close();

        }


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

        else if (choice == 3 )
        {
            int id;
            cout << "Enter Scheme ID: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i].id == id)
                {
                    s[i].active = true;
                    cout << "Status Activated Successfully!\n";
                    found = true;
                    break;
                }
            }


        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Scheme ID: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i].id == id)
                {
                    found=true;
                    cout << "Status Deactivated Successfully!\n";
                    active=s[i].active;

                    break;
                }
            }



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

     application a;
     a.input();
     a.status(active);




    return 0;
}
