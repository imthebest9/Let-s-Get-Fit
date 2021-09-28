// Let's Get Fit (LGF) Program
#include <iostream>
#include <ctime>		// include library to display time
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
// function prototype
void inputData();
void readData(string[], string[], string[], string[], int[], float[], float[], int &);
void computeData(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void menu();
void printDataHeader();
void printData(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void printAllData(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void searchviaID(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void getSlim(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void modifyData(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
void displayStats(string[], string[], string[], string[], int[], float[], float[], float[], float[], float[], string[], int &);
int searchData(string [], int , string );
int main()
{
	// variable declaration
	string fname[100], lname[100], id[100], gender[100], weightc[100], cont, gender2;
	int age[100]={0}, i=0, choice=0, age2=0;
	float weight[100]={0}, height[100]={0}, bmi[100]={0}, bmr[100]={0}, rmr[100]={0}, maxbmi2=0.0, minbmi2=0.0, rmr2=0.0, 
	maxbmr2=0.0, minbmr2=0.0, maxrmr2=0.0, minrmr2=0.0;
	cout << fixed << showpoint << setprecision(2);	// 2 digits after decimal point for every output
	readData(fname, lname, id, gender, age, weight, height, i);	// function call to read data from file
	do
	{
		// function call to calculate bmi, bmr, rmr, weight category.
		computeData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, i);
		menu();
		cin >> choice;	// input choice from user
		system("cls");	// clearing the screen
		switch(choice)
		{
			case 1:{
				inputData();	// function call to print data into file
				break;}
			case 2:{
				// function call to print data of all stuff
				printAllData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, i);
				break;}
			case 3:{
				do
				{
					// function call to display data of stuff by searching via ID
					searchviaID(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, i);
					cout << "Would like to search again? (yes/no)";	// ask if user wants to search another stuff
					cin >> cont;
				}
				while(cont== "yes");
				break;}
			case 4:{
				// search for combinational criteria with gender and bmi, bmr, rmr
				int cri1=1, cri2;
				do
				{
					cout << "What two criteria do you wish to search for? " << endl;
					cout << "Input 3 for bmi, 4 for bmr and 5 for rmr."<< endl;
					do
					{
						cout << "Criteria (bmi, bmr or rmr): ";
						cin >> cri2;
						if(cin.fail() || cri2 != 3 && cri2 != 4 && cri2 != 5)	// input validation
						{
							cin.clear();
							cin.ignore();
							cout << "Please enter 3, 4 or 5 only!" << endl;
						}
					}while( cri2 != 3 && cri2 != 4 && cri2 !=5);
					
					
					if (cri1==1)
					{
						do{
						cout << "Gender: ";
						cin >> gender2;
						if(cin.fail() || gender2 != "male" && gender2 != "female")	// input validation
						{
							cin.clear();
							cin.ignore();
							cout << "Please enter male or female (in small letters) only!" << endl;
						}
						}while(gender2 != "male" && gender2 != "female");
						if(cri2==3)
						{
							// gender and bmi
							do
							{
								cout << "Please enter minimum bmi value (between 0 and 50 only): ";
								cin >> minbmi2;
								if(cin.fail() || minbmi2 <0 || minbmi2>50)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter bmi value (between 0 and 50 only): ";
								}
							}while(minbmi2<0 || minbmi2 > 50);
							do
							{
								cout << "Please enter maximum bmi value (between 0 and 50 only): ";
								cin >> maxbmi2;
								if(cin.fail() || maxbmi2 <0 || maxbmi2>50)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter bmi value (between 0 and 50 only): ";
								}
							}while(maxbmi2<0 || maxbmi2 > 50);
							for(int a=0; a<i; a++)
							{
								if(gender2 == "male" && gender[a] == "male" && bmi[a] > minbmi2 && bmi[a] < maxbmi2 )
									printData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, a);
								else if (gender2 == "female" && gender[a] == "female" && bmi[a]> minbmi2 && bmi[a] < maxbmi2)
									printData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, a);
							}
						}
						if(cri2==4)
						{
							// gender and bmr
							do
							{
								cout << "Please enter minimum bmr value (between 0 and 5000 only): ";
								cin >> minbmr2;
								if(cin.fail() || minbmr2 <0 || minbmr2>5000)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter bmr value (between 0 and 5000 only): ";
								}
							}while(minbmr2 <0 || minbmr2>5000);
							do
							{
								cout << "Please enter maximum bmr value (between 0 and 5000 only): ";
								cin >> maxbmr2;
								if(cin.fail() || maxbmr2 <0 || maxbmr2>5000)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter bmr value (between 0 and 5000 only): ";
								}
							}while(maxbmr2 <0 || maxbmr2>5000);
							for(int a=0; a<i; a++)
							{
								if(gender2 == "male" && gender[a] == "male" && bmr[a] > minbmr2 && bmr[a] < maxbmr2 )
									printData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, a);
								else if (gender2 == "female" && gender[a] == "female" && bmr[a]> minbmr2 && bmi[a] < maxbmr2)
									printData(fname, lname, id, gender, age, weight, height, bmi, bmr, rmr, weightc, a);
							}
						}
						if(cri2==5)
						{
							// gender and rmr
							do
							{
								cout << "Please enter minimum rmr value (between 0 and 5000 only): ";
								cin >> minrmr2;
								if(cin.fail() || minrmr2 <0 || minrmr2>5000)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter rmr value (between 0 and 5000 only): ";
								}
							}while(minrmr2 <0 || minrmr2>5000);
							do
							{
								cout << "Please enter maximum rmr value (between 0 and 5000 only): ";
								cin >> maxrmr2;
								if(cin.fail() || maxrmr2 <0 || maxrmr2>5000)	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please reenter rmr value (between 0 and 5000 only): ";
								}
							}while(maxrmr2 <0 || maxrmr2>5000);
							for(int a=0; a<i; a++)
							{
								if(gender2 == "male" && gender[a] == "male" && rmr[a] > minrmr2 && rmr[a] < maxrmr2 )
									printData(fname, lname, id, gender, age, weight, height, bmi, rmr, rmr, weightc, a);
								else if (gender2 == "female" && gender[a] == "female" && rmr[a]> minrmr2 && bmi[a] < maxrmr2)
									printData(fname, lname, id, gender, age, weight, height, bmi, rmr, rmr, weightc, a);
							}
						}
					}
					cout << "Would like to continue? (type yes/no):" ;
					cin >> cont;
				}
				while(cont == "yes");
				break;}
			case 5:{
				// Suggest healthy routine
				do
				{
					getSlim(fname, lname, id, gender, age, weight, height, bmi, rmr, rmr, weightc, i);
					cout << "Would you like to have routine suggestion for another stuff? (type yes/no): ";
					cin >> cont;
				}while(cont == "yes");
				break;
			}
			case 6:{
				// Modify selective information
				do
				{
					modifyData(fname, lname, id, gender, age, weight, height, bmi, rmr, rmr, weightc, i);
					cout << "Would you like to update the information of another stuff?\n continue(yes/no): ";
					cin >> cont; 
				}while(cont == "yes");
				break;
			}
			case 7:{
				// Display minimal statistical information
				displayStats(fname, lname, id, gender, age, weight, height, bmi, rmr, rmr, weightc, i);
				break;
			}
			case 8:{
				// Exit
				cout << "Thank you for using this program!!!\nKeep fit!!!\n";
				break;
			}
			default:
				cout <<  "invalid input\n";	// choice cannot be less than or equal to 0 and more than 8
		}
		system("pause");	// pausing the screen
		system("cls");		// clearing the screen
	}
	while(choice!=8);	// continue to loop until the user asks to stop
}

// input data from file
void readData(string fname[], string lname[], string id[], string gender[], int age[], float weight[], float height[], int &i)
{
	ifstream inData;
	string filename;
	cout << "Which file do you want to input?" << endl;
	cin	>> filename;
	inData.open(filename.c_str(), ios::app);	// input data from file that is specified by user and add data into end of the file
	for(int j=0; !inData.eof(); j++)
	{
		if(inData.eof() == true)	// end the loop if it reaches end of file
			break;
		else
		{
			inData >> fname[j] >> lname[j] >> id[j] >> gender[j] >> age[j] >> weight[j] >> height[j];	// putting data into arrays
			i++;	// increment the number of staff
		}
	}
	inData.close();	//closing file
}

// print data into file
void inputData()
{
	string choice, fname, lname, id, gender, cont, filename;
	int age = 0;
	float height = 0.0, weight = 0.0;
	ofstream outData;
	ifstream readFile;
	outData.open("USMstaff.txt", ios::app); 
	cout << "Do you want to input any data? (yes/no) \n";	// ask user to input data or not
	while(true)
	{
		cout << "Choice: ";
		cin >> choice;
		if(cin.fail() || choice != "yes" && choice != "no")	// input validation
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter yes or no (in small letters) only!" << endl;
			continue;
		}
		break;
	}
	if(choice == "yes")
	{
		do
		{
			string line = "___________________________________________________________________";
			cout << line << endl;
			cout << "| First name					:|";
			cin >> fname;
			cout << "| Last name					:|";
			cin >> lname;
			cout << "| Staff ID					:|";
			cin >> id;
			do
			{
				cout << "| Gender (male or female)			:|";
				cin >> gender;
				if(cin.fail() || gender != "male" && gender != "female")	// input validation
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter male or female (in small letters) only!" << endl;
				}
			}
			while(gender != "male" && gender != "female");	
			do
			{
				cout << "| Age						:|";
				cin >> age;
				if(cin.fail() || (age < 16 || age > 65))	// input validation
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter age ranged between 16 and 65 only!" << endl;
				}
			}
			while(cin.fail() ||(age < 16 || age > 65));
			do
			{
				cout << "| Weight (kg)					:|";
				cin >> weight;
				if(cin.fail() || (weight <0 || weight> 500))	// input validation
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter weight ranged between 0 and 500 only!" << endl;
				}
			}
			while(cin.fail() || (weight <0 || weight> 500));	
			do
			{
				cout << "| Height (cm)					:|";
				cin >> height;
				if(cin.fail() || (height<0 || height>250))	// input validation
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter height ranged between 0 and 250 only!" << endl;
				}
			}
			while(cin.fail() || (height<0 || height>250));
			outData << " " << fname << "\t"	
					<< " " << lname << "\t"
					<< " " << id << "\t"
					<< " " << gender << "\t"
					<< " " << age << "\t"
					<< " " << weight << "\t"
					<< " " << height << endl;
			cout << "Do you wish to input data again? (yes/no)";
			cin >> cont;
			if(cin.fail() || cont != "yes" && cont != "no")	//input validation
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter yes or no (in small letters) only!" << endl;			
			}
		}
		while(cin.fail() || cont != "no" || cont == "yes");
	}
	outData.close();
	system("pause");
	system("cls");
}

void computeData(string fname[], string lname[], string id[], string gender[], int age[], float weight[], float height[],
 float bmi[], float bmr[], float rmr[], string weightc[], int &i)
{
	// BMI depends on weight and height of a person
	// BMR is that men and women of same age, weight and height have different values.
	// RMR is that it is completely different even though gender, age, weight and height are the same.
	for(int k=0; k<i; k++)
	{
		bmi[k] = weight[k] / ((height[k]/100)*(height[k]/100));
		// The formula for BMR for male and female differs only in +5 and -161
		bmr[k]= 10 * weight[k] + 6.25 * height[k] - 5 * age[k];
		// Update BMR for male and female and
		// Calculate RMR for male and female
		if(gender[k] == "male")
		{
			bmr[k] += 5;
			rmr[k] = 88.362 + (13.397 * weight[k]) + (4.799 * height[k]) - (5.677 * age[k]);
		}
		else if(gender[k] == "female")
		{
			bmr[k] -= 161;
			rmr[k] = 447.593 + (9.247 * weight[k]) + (3.098 * height[k]) - (4.330 * age[k]);
		}
		// Calculate weight category according to bmi
		if(bmi[k] < 20)
			weightc[k] = "Underweight";
		else if (bmi[k] >= 20 && bmi[k] < 25)
			weightc[k] = "Normal weight";
		else if (bmi[k] >= 25 && bmi[k] < 30)
			weightc[k] = "Overweight";
		else if (bmi[k] >= 30)
			weightc[k] = "Obese";
	}
}
// menu interface
void menu()
{
	time_t now = time(0);
	string line = "_______________________________";
	char* dt = ctime(&now);
	cout << "\t\t\t\t\t\t\t\t " << "Current time: " << dt << endl;	// display time
	cout << "\t\t\t\t" << line << endl;
	cout << "\t\t\t\t\t" << "| MAIN MENU |" << endl;
	cout << "\t\t\t\t" << line << endl;
	cout << endl << endl;
	cout << "-------------------------------------->" << "LET'S GET FIT!" << "<------------------------------------" << endl << endl << endl;
	cout << "\t\t 1) Add new staff information" << endl;
	cout << "\t\t 2) Display all data for all USM stuff." << endl;
	cout << "\t\t 3) Display data of specific stuff via ID" << endl;
	cout << "\t\t 4) Display data of specific stuff via 2 specific criteria" << endl;
	cout << "\t\t 5) Suggest healthy routine for stuff." << endl;
	cout << "\t\t 6) Modify selective information (age and weight)." << endl;
	cout << "\t\t 7) Display statistical information." << endl;
	cout << "\t\t 8) Exit" << endl << endl;
	cout << "\t\t Choice: ";
}
// print data of specified stuff
void printData(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	printDataHeader();
	cout << "\t" << fname[i] << "\t\t" << lname[i] << "\t\t" << id[i] << "\t\t" << gender[i] << "\t    " << age[i] << "\t\t" <<
	weight[i] << "\t       " << height[i] << "\t" << bmi[i] << "\t" << bmr[i] << "\t" << rmr[i] << "\t\t" << weightc[i] 
	<< endl << endl; 

}
// function to print all data of all stuff
void printAllData(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	printDataHeader();
	for(int a=0; a< i-1; a++)
	{
		cout << "\t" << fname[a] << "\t\t" << lname[a] << "\t\t" << id[a] << "\t\t" << gender[a] << "\t    " << age[a] << "\t\t" <<
		weight[a] << "\t       " << height[a] << "\t" << bmi[a] << "\t" << bmr[a] << "\t" << rmr[a] << "\t\t" << weightc[a] 
		<< endl << endl; 
	}
}
// function to search data via stuff ID
void searchviaID(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	string search;
	cout << "Please enter the stuff ID you wish to search: ";
	cin >> search;
	printDataHeader();
	int a = searchData(id, 100, search);
	if(a >= 0)
		cout << "\t" << fname[a] << "\t\t" << lname[a] << "\t\t" << id[a] << "\t\t" << gender[a] << "\t    " << age[a] << "\t\t" <<
		weight[a] << "\t       " << height[a] << "\t" << bmi[a] << "\t" << bmr[a] << "\t" << rmr[a] << "\t\t" << weightc[a] 
		<< endl << endl;
	else
		cout << "Staff not found! " << endl;
}
void printDataHeader()
{
	cout << "__________________________________________________________________________________________________________________________________________________\n";
	cout << "| First name\t| Last name\t| Stuff ID\t| Gender\t| Age\t| Weight(kg)\t|Height(cm)\t| BMI\t| BMR\t| RMR\t| Weight category\t|"
	<< endl;
}

// function to search data of stuff, return array index if found, return -1 if not found
int searchData(string id[], int size, string search)
{
	for(int i=0; i<size; i++)
	{
		if(search == id[i])
			return i;
	}
	return -1;
}

// function to suggest daily calorie intake for each stuff of different gender, age and weight category
void getSlim(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	int often=0;
	double calories=0.0, newweight=0.0, newcal=0.0;
	string search;
	cout << "Please enter your stuff ID: ";
	cin >> search;
	int a = searchData(id, 100, search);
	if(a >= 0)
	{
		cout << "Your weight category is " << weightc[a] << endl;
		cout << "How often do you exercise per week?\n";
			cout << "1 - Sedentary, 2 - Slightly, 3 - Moderately, 4 - Actively\n";
			cin >> often;
			switch(often)	//suggest calorie intake based on activity
			{
				case 1:
					calories = bmr[a] * 1.2;
					break;
				case 2:
					calories = bmr[a] * 1.375;
					break;
				case 3:
					calories = bmr[a] * 1.55;
					break;
				case 4:
					calories = bmr[a] * 1.725;
					break;
				default:
					cout << "Invalid input.\n";}
		if(weightc[a] == "Underweight")
		{
			cout << "You need to gain weight!\n In order to gain weight, you must consume more than "
			<< bmr[a] << "kcal per day.\n" << endl;
			cout << "How much weight(kg) do you want to gain per week?" << endl;
			cout << "Weight(kg): " ;
			cin >> newweight;
			newcal = bmr[a] + newweight*1000;
			cout << "You need to add more than " << calories << "kJ per day.\n" << endl;
		}
		else if(weightc[a] == "Normal weight")
		{
			cout << "To maintain your normal weight, you must consume about " << calories << "kJ per day.\n";
		}
		else if(weightc[a] == "Overweight" || weightc[a] == "Obese")
		{
			cout << "You need to lose weight!\n In order to lose weight, you must consume less than "
			<< bmr[a] << endl;
			cout << "How much weight (kg) do you want to lose per week?" << endl;
			cout << "Weight (kg): " << endl;
			cin >> newweight;
			newcal = bmr[a] - newweight* 1000;
			cout << "You should consume not more than " << newcal << "kJ per day.\n";
		}
	}
	else
		cout << "Staff not found!\n";
}

// function to modify data of stuff such as gender, age, weight and height
void modifyData(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	int choice=0;
	string search;
	cout << "Please enter the ID of the stuff you would like to modify: ";
	cin >> search;
	int a = searchData(id, 100, search);	// function call to search data via id
	ofstream outData2;
	outData2.open("Temp.txt");	// open a temporary text file
	if(a>=0)
	{
		cout << "Stuff is found!\n";
		for (int b=0; b < i-1 ; b++)	// loop to transfer data to temp.txt
		{
			if(b!=a)	// avoid transferring data that user wants to be modified to temp.txt
			{
				outData2 << " " << fname[b] << "\t"	
						<< " " << lname[b] << "\t"
						<< " " << id[b] << "\t"
						<< " " << gender[b] << "\t"
						<< " " << age[b] << "\t"
						<< " " << weight[b] << "\t"
						<< " " << height[b] << endl;
			}	}
				cout << "Please choose the data you wish to update.\n ";
				cout << "1 - gender, 2 - age, 3 - weight, 4 - height.\n";
				cout << "Choice: ";
				cin >> choice;
				switch(choice)
				{
					case 1:
						{
							do
							{
								cout << "Please enter correct gender: ";
								cin >> gender[a];
								if (cin.fail() || (gender[a] != "male" && gender[a] != "female"))	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please enter correct gender again (male or female) : ";
								}
							}while(gender[a] != "male" && gender[a] != "female");
							break;
						}
					case 2:
						{
							do{
							cout << "Please enter new age: ";
							cin >> age[a];
							if (cin.fail() || (age[a] < 16 || age[a] > 65 ))	// input validation
							{
								cin.clear();
								cin.ignore();
								cout << "Please enter age between 16 to 65 years old only.\n";
							}
							}while(age[a]<16 || age[a]>65);
							break;
						}
					case 3:
						{
							do{
								cout << "Please enter new weight: ";
								cin >> weight[a];
								if(cin.fail() || (weight[a] < 0 || weight[a] > 500)) 	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please enter correct weight (0-500kg) only!\n";
								}
							}while(weight[a] <0 || weight[a] < 0 || weight[a] > 500);
							break;
						}
					case 4:
						{
							do{
								cout << "Please enter new height: ";
								cin >> weight[a];
								if(cin.fail() || (height[a] < 0 || height[a] > 250)) 	// input validation
								{
									cin.clear();
									cin.ignore();
									cout << "Please enter correct height (0-250cm) only!\n";
								}
							}while(weight[a] <0 || height[a] < 0 || height[a] > 250);
							break;
						}
					default: cout << "Invalid input! ";
				}
				// Transfering new data from old file to new file
				outData2 << " " << fname[a] << "\t"	
						<< " " << lname[a] << "\t"
						<< " " << id[a] << "\t"
						<< " " << gender[a] << "\t"
						<< " " << age[a] << "\t"
						<< " " << weight[a] << "\t"
						<< " " << height[a] << endl;
				outData2.close();	// closing the temp file
				remove("USMstaff.txt");	//deleting old file
				rename("Temp.txt", "USMstaff.txt");	// renaming new file
			
		}
	
	else
		cout << "Data not found!\n";
}

// function to display statistics based on data of all USM's stuffs
void displayStats(string fname[], string lname[], string id[], string gender[], int age[] ,float weight[], float height[], float bmi[], 
float bmr[], float rmr[], string weightc[], int &i)
{
	int age16=0, age26=0, age36=0, age46=0, age56=0, nummale=0, numfemale=0, uw=0, nw=0, ow=0, ob=0;
	for(int a=0; a<i; a++)
	{
		if(gender[a] == "male")
			nummale++;
		else if(gender[a] == "female")
			numfemale++;
	}
	cout << "The number of male stuffs is " << nummale << endl;
	cout << "The number of female stuffs is " << numfemale << endl;
	
	for(int a=0; a<i; a++)
	{
		if(age[a] >= 16 && age[a] <= 25)
			age16++;
		else if(age[a] >= 26 && age[a] <= 35)
			age26++;
		else if(age[a] >= 36 && age[a] <= 45)
			age36++;
		else if(age[a] >= 46 && age[a] <= 55)
			age46++;
		else if(age[a] >= 56 && age[a] <= 65)
			age56++;
	}
	cout << "The number of stuffs aged between 16 and 25 is " << age16 << endl;
	cout << "The number of stuffs aged between 26 and 35 is " << age26 << endl;
	cout << "The number of stuffs aged between 36 and 45 is " << age36 << endl;
	cout << "The number of stuffs aged between 46 and 55 is " << age46 << endl;
	cout << "The number of stuffs aged between 56 and 65 is " << age56 << endl;
	for(int a=0; a<i; a++)
	{
		if(weightc[a] == "Underweight")
			uw++;
		else if(weightc[a] == "Normal weight")
			nw++;
		else if(weightc[a] == "Overweight")
			ow++;
		else if(weightc[a] == "Obese")
			ob++;
	}
	cout << "The number of stuffs that are underweight are " << uw << endl;
	cout << "The number of stuffs that are normal weight are " << nw << endl;
	cout << "The number of stuffs that are overweight are " << ow << endl;
	cout << "The number of stuffs that are obese are " << ob << endl;
}

