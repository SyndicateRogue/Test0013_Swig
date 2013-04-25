/* File : example.h */

class Shape {
public:
  Shape() {
    nshapes++;
  }
  virtual ~Shape() {
    nshapes--;
  };
  double  x, y;   
  void    move(double dx, double dy);
  virtual double area(void) = 0;
  virtual double perimeter(void) = 0;
  static  int nshapes;
};


class Callback
{
public:
	virtual void onChanged(Shape* shape) = 0;
	virtual ~Callback() {};
};

class Circle : public Shape {
private:
  double radius;
  Callback* cb_;
public:
//  Circle(double r) : radius(r) { };
  Circle(double r, Callback* cb) : radius(r),cb_(cb) { };
  virtual double area(void);
  virtual double perimeter(void);

  void setR(double r);
};


class Square : public Shape {
private:
  double width;
public:
  Square(double w) : width(w) { };
  virtual double area(void);
  virtual double perimeter(void);
};
