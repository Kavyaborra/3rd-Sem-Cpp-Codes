#include<iostream>
#include<cmath>

using namespace std;

struct vector3d{
float i,j,k;
};
struct triangle{
  vector3d t1,t2,t3;
};
struct line{
  vector3d l1,l2;
};
struct point{
  vector3d p;
};

vector3d subtract(vector3d a, vector3d b){
vector3d temp;
temp.i=a.i-b.i;
temp.j=a.j-b.j;
temp.k=a.k-b.k;
return temp;}

float norm(vector3d a){
return sqrt(pow(a.i,2)+pow(a.j,2)+pow(a.k,2));
}

float get_length(line a){
  vector3d temp;
  temp=subtract(a.l1, a.l2);
  return norm(temp);
}

float get_length(point p1, point p2){
  return norm(subtract(p1.p,p2.p));
}

vector3d add(vector3d a, vector3d b){
vector3d temp;
temp.i=a.i+b.i;
temp.j=a.j+b.j;
temp.k=a.k+b.k;
return temp;}

float dot(vector3d a, vector3d b){
return ((a.i)*(b.i)+(a.k)*(b.k)+(a.j)*(b.j));
}

vector3d cross(vector3d a, vector3d b){
vector3d temp;
temp.i=(a.j)*(b.k)-(a.k)*(b.j);
temp.j=(a.k)*(b.i)-(a.i)*(b.k);
temp.k=(a.i)*(b.j)-(a.j)*(b.i);
return temp;
}

vector3d scalar_product(float a, vector3d b) {
vector3d temp;
 temp.i=a*(b.i);
 temp.j=a*(b.j);
 temp.k=a*(b.k);
 return temp;
}

vector3d scalar_product(int a, vector3d b){
vector3d temp;
 temp.i=a*(b.i);
 temp.j=a*(b.j);
 temp.k=a*(b.k);
 return temp;
}

vector3d normalize(vector3d a){
  vector3d temp;
  temp.i=a.i/norm(a);
  temp.j=a.j/norm(a);
  temp.k=a.k/norm(a);
  return temp;
}

float get_angle_between_tri_points(point p1, point p2, point p3){
vector3d tri_p, tri_p1;
float angle;
tri_p=subtract(p1.p, p2.p);
tri_p1=subtract(p3.p,p2.p);
angle=acos(dot(tri_p, tri_p1)/(norm(tri_p)*norm(tri_p1)));
return angle;
}

float get_area(triangle a){
float l1,l2,l3,s;
point p1, p2, p3;
p1.p=a.t1;
p2.p=a.t2;
p3.p=a.t3;
l1=get_length(p1, p2);
l2=get_length(p2, p3);
l3=get_length(p3, p1);
s=(l1+l2+l3)/2;
return sqrt((s)*(s-l1)*(s-l2)*(s-l3));
}

vector3d get_normal(triangle a){
return cross(subtract(a.t2,a.t3)subtract(a.t1,a.t2));
}

int main(){
  /*vector3d a,b, result1, result, result2, result4, result5;
  float x;
  int y;
  std::cin >> a.i>>a.j>>a.k;
  std::cin >> b.i>>b.j>>b.k;
  std::cin >> x;
  std::cin >> y;
  result=add(a,b);
  std::cout << result.i<<" "<<result.j<<" "<<result.k << std::endl;
  result1=subtract(a,b);
  std::cout << result1.i<<" "<<result1.j<<" "<<result1.k << std::endl;
  std::cout << dot(a,b) << std::endl;
  result2=cross(a,b);
  std::cout << result2.i<<" "<<result2.j<<" "<<result2.k << std::endl;
  std::cout << norm(a)<< std::endl;
  result4=scalar_product(x, b);
  std::cout << result4.i<<" "<<result4.j<<" "<<result4.k << std::endl;
  result5=scalar_product(y, b);
  std::cout << result5.i<<" "<<result5.j<<" "<<result5.k << std::endl;
  */
  vector3d a, b, c;
  cin>>a.i>>a.j>>a.k;
  cin>>b.i>>b.j>>b.k;
  cin>>c.i>>c.j>>c.k;

  point p1, p2, p3;
  p1.p=a;
  p2.p=b;
  p3.p=c;

  triangle t1;
  t1.t1=a;
  t1.t2=b;
  t1.t3=c;

  line l1,l2, l3;
  l1.l1=a;
  l1.l2=b;
  l2.l1=b;
  l2.l2=c;
  l3.l1=c;
  l3.l2=a;

  std::cout <<get_length(l1)<<" "<<get_length(l2)<<" "<<get_length(l3) << std::endl;
  std::cout <<get_angle_between_tri_points(p1,p2,p3)<<" "<<get_angle_between_tri_points(p2,p3,p1)<<" "<<get_angle_between_tri_points(p3,p1,p2) << std::endl;
  std::cout << get_area(t1) << std::endl;
  vector3d no=normalize(get_normal(t1));
  std::cout << no.i<<" "<< no.j<<" " <<no.k<< std::endl;
  return 0;
}
