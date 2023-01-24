#include <iostream>
#include <iomanip>
#include <occi.h>
#include <unistd.h>
#include <termios.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
using namespace oracle::occi;

void help()
{
	cout << "Hello! This is the program to manage your deadlines. List of commands:\n";
	cout << "  deadlines - show info for incomplete deadlines for course [cno] in increasing order of deadlines;\n";
	cout << "  instructor - show info for instructor for course [cno] or with id [insid] or with name [name];\n";
	cout << "  incomplete - show all incomplete deadlines in increasing order of deadlines;\n";
	cout << "  all - show all deadlines;\n";
	cout << "  deadline - show info for the deadline [name] for [cno];\n";
	cout << "  course - show info for the course [cno];\n";
	cout << "  help - display this menu\n";
	cout << "  add - add something\n";
	cout << "  complete - complete a deadline\n";
	cout << "  exit\n";
	cout << "Press enter after the command for the program to start working on your command.\n";
	cout << "Thanks for using the program!\n";
	cout << "WARNING! Don't use single quotation marks ' in any input data! ' will be removed from input data since Oracle doesn't work with '. If you have to quote something, use double quotation marks \"\n";
}

string sanitize(string s)
{
	string newS = "";
	for (int i = 0; i < s.size(); i++)
		if (s[i] != '\'')
			newS += s[i];
	return newS;
}

string readPassword()
{
	struct termios settings;
	tcgetattr( STDIN_FILENO, &settings );
	settings.c_lflag =  (settings.c_lflag & ~(ECHO));
	tcsetattr( STDIN_FILENO, TCSANOW, &settings );

	string password = "";
	getline(cin, password);

	settings.c_lflag = (settings.c_lflag |   ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &settings );
	return password;
}

int main()
{
	string username;
	string password;
	const string connectString = "sunfire.csci.viu.ca";
	cout << "Enter username: ";
	getline(cin, username);

	cout << "Enter password: ";
	password = readPassword();

	cout << endl;
	try
	{
		Environment *env = Environment::createEnvironment();
		Connection *conn = env->createConnection(username, password, connectString);

		string queryStr = "";

		help();
		
		int staticDID = 0;

		ifstream fin;
		fin.open("staticDID.txt");
		if (fin.is_open())
		{
			fin >> staticDID;
		}
		fin.close();

		cout << "Enter command:\n";

		string command;
		cin >> command;

		while (command != "exit")
		{
			if (command == "deadlines")
			{
				Statement *stmt = conn->createStatement();
				cout << "Enter course number: ";
				string cno;
				cin >> cno;
				cno = sanitize(cno);
				queryStr = "select did, cno, name, worth, time, submit from projDeadlines D where D.cno = '" + cno + "' and D.status = 'incomplete' order by D.time asc";
				ResultSet *rs = stmt->executeQuery(queryStr);
				if (rs->next())
				{
					do
					{
						cout << "Deadline ID: " << rs->getString(1);
						cout << " Course number: " << rs->getString(2);
						cout << " Name of the deadline: " << rs->getString(3);
						cout << " Deadline's weight: " << rs->getString(4);
						cout << " Time of the deadline: " << rs->getString(5);
						cout << " How to submit: " << rs->getString(6);
						cout << '\n';
					}
					while (rs->next());
				}
				else
					cout << "No active deadlines for course " << cno << "\n";
				stmt->closeResultSet(rs);
				conn->terminateStatement(stmt);
			}
			else if (command == "instructor")
			{
				cout << "Do you want to show the instructor for a specific course [c] or an instructor with a specific name [n] or id [i]? ";
				char c;
				cin >> c;
				while ((c != 'c') && (c != 'n') && (c != 'i'))
				{
					cout << "Enter c for course or n for name or i for id: ";
					cin >> c;
				}
				if (c == 'c')
				{
					Statement *stmt = conn->createStatement();
					cout << "Enter course number: ";
					string cno;
					cin >> cno;
					cno = sanitize(cno);
					queryStr = "select I.insid, I.name, I.email, I.website from projInstructors I, projTeaching T where I.insid = T.insid and T.cno = '" + cno + "'";
					ResultSet *rs = stmt->executeQuery(queryStr);
					if (rs->next())
					{
						do
						{
							cout << "Instructor's ID: " << rs->getString(1);
							cout << " Instructor's name: " << rs->getString(2);
							cout << " Instructor's email: " << rs->getString(3);
							cout << " Instructor's website: " << rs->getString(4);
							cout << '\n';
						}
						while (rs->next());
					}
					else
						cout << "No instructors found for course :" << cno << "\n";
					stmt->closeResultSet(rs);
					conn->terminateStatement(stmt);
				}
				else if (c == 'n')
				{
					Statement *stmt = conn->createStatement();
					cout << "Enter instructor's name: ";
					string name;
					getline(cin, name);
					getline(cin, name);
					name = sanitize(name);
					queryStr = "select I.insid, I.name, I.email, I.website from projInstructors I where I.name = '" + name + "'";
					ResultSet *rs = stmt->executeQuery(queryStr);
					if (rs->next())
					{
						do
						{
							cout << "Instructor's ID: " << rs->getString(1);
							cout << " Instructor's name: " << rs->getString(2);
							cout << " Instructor's email: " << rs->getString(3);
							cout << " Instructor's website: " << rs->getString(4);
							cout << '\n';
						}
						while (rs->next());
					}
					else
						cout << "No instructors found with name " << name << "\n";
					stmt->closeResultSet(rs);
					conn->terminateStatement(stmt);
				}
				else
				{
					Statement *stmt = conn->createStatement();
					cout << "Enter instructor's id: ";
					string id;
					cin >> id;
					id = sanitize(id);
					queryStr = "select I.insid, I.name, I.email, I.website from projInstructors I where I.insid = '" + id + "'";
					ResultSet *rs = stmt->executeQuery(queryStr);
					if (rs->next())
					{
						do
						{
							cout << "Instructor's ID: " << rs->getString(1);
							cout << " Instructor's name: " << rs->getString(2);
							cout << " Instructor's email: " << rs->getString(3);
							cout << " Instructor's website: " << rs->getString(4);
							cout << '\n';
						}
						while (rs->next());
					}
					else
						cout << "No instructors found with ID " << id << "\n";
					stmt->closeResultSet(rs);
					conn->terminateStatement(stmt);
				}
			}
			else if (command == "incomplete")
			{
				Statement *stmt = conn->createStatement();
				queryStr = "select did, cno, name, worth, time, submit from projDeadlines D where D.status = 'incomplete'";
				ResultSet *rs = stmt->executeQuery(queryStr);
				if (rs->next())
				{
					do
					{
						cout << "Deadline ID: " << rs->getString(1);
						cout << " Course number: " << rs->getString(2);
						cout << " Name of the deadline: " << rs->getString(3);
						cout << " Deadline's weight: " << rs->getString(4);
						cout << " Time of the deadline: " << rs->getString(5);
						cout << " How to submit: " << rs->getString(6);
						cout << '\n';
					}
					while (rs->next());
				}
				else
					cout << "No active deadlines found\n";
				stmt->closeResultSet(rs);
				conn->terminateStatement(stmt);
			}
			else if (command == "all")
			{
				Statement *stmt = conn->createStatement();
				queryStr = "select did, cno, name, worth, time, submit, status from projDeadlines D";
				ResultSet *rs = stmt->executeQuery(queryStr);
				if (rs->next())
				{
					do
					{
						cout << "Deadline ID: " << rs->getString(1);
						cout << " Course number: " << rs->getString(2);
						cout << " Name of the deadline: " << rs->getString(3);
						cout << " Deadline's weight: " << rs->getString(4);
						cout << " Time of the deadline: " << rs->getString(5);
						cout << " How to submit: " << rs->getString(6);
						cout << " Status: " << rs->getString(7);
						cout << '\n';
					}
					while (rs->next());
				}
				else
					cout << "No deadlines found\n";
				stmt->closeResultSet(rs);
				conn->terminateStatement(stmt);
			}
			else if (command == "deadline")
			{
				cout << "Do you remember deadline's ID? [y/n] ";
				char c;
				cin >> c;
				while ((c != 'y') && (c != 'n'))
				{
					cout << "Enter y for yes or n for no: ";
					cin >> c;
				}
				if (c == 'y')
				{
					cout << "Enter deadline's ID: ";
					string id;
					cin >> id;
					id = sanitize(id);
					Statement *stmt = conn->createStatement();
					queryStr = "select did, cno, name, worth, time, submit, status from projDeadlines D where D.did = '" + id + "'";
					ResultSet *rs = stmt->executeQuery(queryStr);
					if (rs->next())
					{
						do
						{
							cout << "Deadline ID: " << rs->getString(1);
							cout << " Course number: " << rs->getString(2);
							cout << " Name of the deadline: " << rs->getString(3);
							cout << " Deadline's weight: " << rs->getString(4);
							cout << " Time of the deadline: " << rs->getString(5);
							cout << " How to submit: " << rs->getString(6);
							cout << " Status: " << rs->getString(7);
							cout << '\n';
						}
						while (rs->next());
					}
					else
						cout << "No deadlines found with deadline ID " << id << "\n";
					stmt->closeResultSet(rs);
					conn->terminateStatement(stmt);
				}
				else
				{
					cout << "Enter deadline's name: ";
					string name;
					getline(cin, name);
					getline(cin, name);
					name = sanitize(name);
					cout << "Enter course number: ";
					string cno;
					cin >> cno;
					cno = sanitize(cno);
					Statement *stmt = conn->createStatement();
					queryStr = "select did, cno, name, worth, time, submit, status from projDeadlines D where D.cno = '" + cno + "' and D.name = '" + name + "'";
					ResultSet *rs = stmt->executeQuery(queryStr);
					if (rs->next())
					{
						do
						{
							cout << "Deadline ID: " << rs->getString(1);
							cout << " Course number: " << rs->getString(2);
							cout << " Name of the deadline: " << rs->getString(3);
							cout << " Deadline's weight: " << rs->getString(4);
							cout << " Time of the deadline: " << rs->getString(5);
							cout << " How to submit: " << rs->getString(6);
							cout << " Status: " << rs->getString(7);
							cout << '\n';
						}
						while (rs->next());
					}
					else
						cout << "No deadlines found with name " << name << " and course " << cno << "\n";
					stmt->closeResultSet(rs);
					conn->terminateStatement(stmt);
				}
			}
			else if (command == "course")
			{
				Statement *stmt = conn->createStatement();
				cout << "Enter course number: ";
				string cno;
				cin >> cno;
				cno = sanitize(cno);
				queryStr = "select cno, title, credits from projCourses C where C.cno = '" + cno + "'";
				ResultSet *rs = stmt->executeQuery(queryStr);
				if (rs->next())
				{
					do
					{
						cout << "Course's number: " << rs->getString(1);
						cout << " Course's title: " << rs->getString(2);
						cout << " Course's credits: " << rs->getString(3);
						cout << '\n';
					}
					while (rs->next());
				}
				else
					cout << "No course found with course number " << cno << "\n";
				stmt->closeResultSet(rs);
				conn->terminateStatement(stmt);
			}
			else if (command == "help")
			{
				help();
			}
			else if (command == "add")
			{
				cout << "Do you want to add a course [c] or an instructor [i] or the fact that an instructor teaches a course [t] or a deadline [d]? ";
				char c;
				cin >> c;
				while ((c != 't') && (c != 'c') && (c != 'i') && (c != 'd'))
				{
					cout << "Enter c for course or i for instructor or d for deadline: ";
					cin >> c;
				}
				if (c == 'c')
				{
					string cno, credits, title;
					cout << "Enter course number: ";
					cin >> cno;
					cno = sanitize(cno);
					cout << "Enter the number of credits for the course: ";
					cin >> credits;
					credits = sanitize(credits);
					cout << "Enter the title of the course: ";
					getline(cin, title);
					getline(cin, title);
					title = sanitize(title);
					Statement *stmt = conn->createStatement();
					queryStr = "insert into projCourses (cno, credits, title) values ('" + cno + "', '" + credits + "', '" + title + "')";
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
						cout << "Added a new course to the system\n";
					else
						cout << "Error: something went wrong, please try something different\n";
				}
				else if (c == 'i')
				{
					string insid, name, email, website;
					cout << "Enter instructor's ID: ";
					cin >> insid;
					insid = sanitize(insid);
					cout << "Enter instructor's name: ";
					getline(cin, name);
					getline(cin, name);
					name = sanitize(name);
					cout << "Enter instructor's email: ";
					cin >> email;
					email = sanitize(email);
					cout << "Enter instructor's website: ";
					cin >> website;
					website = sanitize(website);
					Statement *stmt = conn->createStatement();
					queryStr = "insert into projInstructors (insid, name, email, website) values ('" + insid + "', '" + name + "', '" + email + "', '" + website + "')";
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
						cout << "Added a new instructor to the system\n";
					else
						cout << "Error: something went wrong, please try something different\n";
				}
				else if (c == 't')
				{
					string cno, insid, sno;
					cout << "Enter course number: ";
					cin >> cno;
					cno = sanitize(cno);
					cout << "Enter instructor's ID: ";
					cin >> insid;
					insid = sanitize(insid);
					cout << "Enter section number: ";
					cin >> sno;
					sno = sanitize(sno);
					queryStr = "insert into projTeaching (cno, insid, sno) values ('" + cno + "', '" + insid + "', '" + sno + "')";
					Statement *stmt = conn->createStatement();
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
						cout << "Added a new instructor-course link to the system\n";
					else
						cout << "Error: something went wrong, please try something different\n";
				}
				else
				{
					string did, cno, worth, name, time, submit;
					ostringstream convert;
					convert << staticDID;
					did = convert.str();
					cout << "Enter course number: ";
					cin >> cno;
					cno = sanitize(cno);
					cout << "Enter deadline's weight: ";
					cin >> worth;
					worth = sanitize(worth);
					cout << "Enter deadline's name: ";
					getline(cin, name);
					getline(cin, name);
					name = sanitize(name);
					cout << "Enter the deadline's time in format yyyy.mm.dd hh:mm : ";
					getline(cin, time);
					time = sanitize(time);
					cout << "Enter the way to submit the deadline: ";
					getline(cin, submit);
					submit = sanitize(submit);
					queryStr = "insert into projDeadlines (did, cno, worth, name, time, submit, status) values ('" + did + "', '" + cno + "', '" + worth + "', '" + name + "', '" + time + "', '" + submit + "', 'incomplete')";
					Statement *stmt = conn->createStatement();
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
					{
						cout << "Automatically generated deadline id (did): " << staticDID << "; status: incomplete;\n";
						staticDID++;
					}
					else
						cout << "Error: something went wrong, please try something different\n";
				}
			}
			else if (command == "complete")
			{
				cout << "Do you remember deadline's ID? [y/n] ";
				char c;
				cin >> c;
				while ((c != 'y') && (c != 'n'))
				{
					cout << "Enter y for yes or n for no: ";
					cin >> c;
				}
				if (c == 'y')
				{
					cout << "Enter deadline's id: ";
					string did;
					cin >> did;
					did = sanitize(did);
					Statement *stmt = conn->createStatement();
					queryStr = "update projDeadlines set status = 'complete' where did = '" + did + "'";
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
						cout << "Congratulations on not being lazy! You've completed a deadline! System has it recorded and is happy for you!\n";
					else
						cout << "Error: something went wrong, please try something different\n";
				}
				else
				{
					cout << "Enter course ID: ";
					string cno;
					cin >> cno;
					cno = sanitize(cno);
					cout << "Enter deadline's name: ";
					string name;
					getline(cin, name);
					getline(cin, name);
					name = sanitize(name);
					Statement *stmt = conn->createStatement();
					queryStr = "update projDeadlines set status = 'complete' where name = '" + name + "' and cno = '" + cno + "'";
					int i = stmt->executeUpdate(queryStr);
					conn->terminateStatement(stmt);
					if (i > 0)
						cout << "Congratulations on not being lazy! You've completed a deadline! System has it recorded and is happy for you!\n";
					else
						cout << "Error: something went wrong, please try something different\n";
				}
			}
			else
			{
				cout << "The command you've entered is not in the list of commands. Enter command help for a full list of commands.\n";
			}
			cout << "Enter command:\n";
			cin >> command;
		}
		cout << "Thanks for using the program! We'd appreciate if you left a 5-star... Just joking! Have a nice day!\n";
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);

		ofstream fout;
		fout.open("staticDID.txt", ios::trunc);
		fout << staticDID;
		fout.close();
	}
	catch (SQLException & e)
	{
		cout << e.what();
		return 0;
	}

	return 0;
}
