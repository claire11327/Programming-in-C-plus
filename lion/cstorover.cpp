#include <iostream>
using namespace std;



class Shape{
	public:
		float locationx,locationy;

		void show_place()
		{
			cout << locationx << "," << locationy << endl;
		}
};

class Square : public Shape{
	public:
		const int x;//,y,edge,big;
	//	Square (){
	//		cout << "con1"<<endl;
	//	};
		Square (int a):x(a){
			cout<<"x = "<<x<<endl;
		};
//		Square (int a,int b,int c,int d){};
		float edge1;
		float area_of_square(){
			return edge1 * edge1;
		}
};

int main()
{

	Square *s = new Square();
//	Square();
	s->Square(3);
	s->locationx = 0;
	s->locationy = 30;
	s->edge = 7;
	s->show_place();
}
