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

class Circle : public Shape{
	public :
		float pi = 3.14;
		float radius;
		float area_of_circle(){
			return radius * radius * pi;
		}
		void show(){
			cout<< area_of_circle()<<endl;
		}
};
class Square : public Shape{
	public:
		float edge;
		float area_of_square(){
			return edge * edge;
		}
		void show(){
			cout<< area_of_square()<<endl;
		}   

};

int main()
{
	Circle *c=new Circle();

	c->locationx = 10;
	c->locationy = 0;
	c->radius = 10;
	c->show_place();
	c->show();

	Square *s = new Square();

	s->locationx = 0;
	s->locationy = 30;
	s->edge = 7;
	s->show_place();
	s->show();
}
