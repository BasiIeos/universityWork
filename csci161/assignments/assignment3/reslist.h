// Implementation of Reservation and ReservationList classes

#include <string>

using namespace std;

class Res
{
	public:
		int hour();
		int minute();
		string address();
		string name();
		bool date();
		void newHour(int h);
		void newMinute(int m);
		void newAddress(string a);
		void newName(string n);
		void newDate(bool t);
	private:
		int Hour;
		int Minute;
		string Address;
		string Name;
		bool Date;
};


class ResList
{
	public:
		ResList();
		~ResList();
		void submit();
		void pickup();
		void list();
		void help();
		bool term();
		static int count;
		static int countt;
	private:
		struct Node
		{
			Node* next;
			Res* data;
		};
		Node* head;
};
