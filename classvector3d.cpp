#include<iostream>
#include<cmath>

using namespace std;

class vector3d {
private:
  float _x, _y, _z ; // data

public:
  friend std::ostream& operator<<(std::ostream &os, vector3d &a) {
      os<< a.get_x() << " " << a.get_y() << " " << a.get_z() <<endl;
    }
    vector3d ()
    {
    };
    vector3d (float x, float y, float z){
      _x=x;
      _y=y;
      _z=z;
    }
    vector3d(const vector3d &a){
      _x=a._x;
      _y=a._y;
      _z=a._z;
    }

  void set_x(float x){
    _x=x;
  }
  void set_y(float y){
    _y=y;
  }void set_z(float z){
    _z=z;
  }
  float get_x(){
    return _x;
  }
  float get_y(){
    return _y;
  }
  float get_z(){
    return _z;
  }

vector3d& add(vector3d b){
  vector3d *imp = new vector3d((_x+b.get_x()),(_y+b.get_y()),(_z+b.get_z()));
  vector3d& temp = *imp;
  return temp;}

vector3d& subtract( vector3d b){
vector3d *imp = new vector3d((_x-b.get_x()),(_y-b.get_y()),(_z-b.get_z()));
vector3d& temp = *imp;
return temp;}

float dot(vector3d b) {
float *imp = new float(_x*b.get_x() + _y*b.get_y() + _z*b.get_z());
float& temp = *imp;
return temp;}

float norm(){
float *imp = new float(sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2)));
float& temp= *imp;
return temp;

}

vector3d& cross(vector3d b){
  vector3d *imp = new vector3d(_y*b.get_z()-b.get_y()*_z,-(_x*b.get_z()-b.get_x()*_z), _x*b.get_y()-b.get_x()*_y);
  vector3d& temp = *imp;
  return temp;}

vector3d& scalar_product(float l) {
  vector3d *imp = new vector3d(_x*l, _y*l, _z*l);
  vector3d& temp = *imp;
  return temp;
}

vector3d& scalar_product(int f){
  vector3d *imp = new vector3d(_x*f, _y*f, _z*f);
  vector3d& temp = *imp;
  return temp;
}

};

int main(){
  vector3d a,b;
  float x, y, z, i, j, k, w;
  int u;
  cin >> x>>y>>z;
    a.set_x(x);a.set_y(y);a.set_z(z);

  cin >> i>>j>>k;
  b.set_x(i);b.set_y(j);b.set_z(k);
  cin >> w;
  cin >> u;
  cout<< a.add(b);
  cout<< a.subtract(b);
  cout<< a.scalar_product(w);
  cout<< b.scalar_product(u);
  cout<< a.dot(b) << endl;
  cout<< a.cross(b);
  cout<< a.norm() << endl;
  cout<< b.norm() << endl;

  return 0;
}
