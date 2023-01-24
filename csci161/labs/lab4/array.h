// Implementation of growing array class

class GArray
{
	public:
		GArray();
		GArray(int);
		~GArray();
		void insert(double k);
		void show();
		int getSize();
		bool operator ==(const GArray &a);
	private:
		int *A;
		int size;
		int elem;
};
