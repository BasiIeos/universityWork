// class declaration

class Flag
{
	public:
		// create a Flag object 
		Flag(int width, int height, char symbol);
		// create a Flag object with width = height = 1 and symbol = '*'
		Flag();
		~Flag();  // properly destroy a Flag object
		int getWidth();     // get width of the flag object
		int getHeight();    // get height of the flag object
		char getSymbol();   // get the display symbol of the flag object
		void resize(int newWidth, int newHeight);
		void changeSymbol(char newSymbol);
		int calculate();    // calculate the number of characters 
		                    // needed to draw this flag
		void draw();     // draw the Flag 
		bool bigFlag();     // return true if this Flag object uses
		                    // more than 25 characters to draw;
		                    // otherwise, return false
	private:
		int fwidth;
		int fheight;
		char fsymbol;
};
