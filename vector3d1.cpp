#include<iostream>
#include<cmath>

using namespace std;
struct vector3d{
float i,j,k;
};
vector3d add(vector3d a, vector3d b){
vector3d temp;
temp.i=a.i+b.i;
temp.j=a.j+b.j;
temp.k=a.k+b.k;
return temp;}

vector3d subtract(vector3d a, vector3d b){
vector3d temp;
temp.i=a.i-b.i;
temp.j=a.j-b.j;
temp.k=a.k-b.k;
return temp;}

float dot(vector3d a, vector3d b){
return ((a.i)*(b.i)+(a.k)*(b.k)+(a.j)*(b.j));
}

float norm(vector3d a){
return sqrt(pow(a.i,2)+pow(a.j,2)+pow(a.k,2));
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

int main(){
  vector3d a, b, result1, result, result2, result4, result5;
  float x;
  int y;
cin >> a.i >> a.j >> a.k;
cin >> b.i >> b.j >> b.k;
cin >> x;
cin >> y;
  result=add(a,b);
cout << result.i << result.j << result.k ;
  result1=subtract(a,b);
cout << result1.i << result1.j << result1.k ;
cout << dot(a,b);
  result2=cross(a,b);
cout << result2.i << result2.j << result2.k;
cout << norm(a);
  result4=scalar_product(x, b);
cout << result4.i << result4.j << result4.k;
  result5=scalar_product(y, b);
cout << result5.i << result5.j << result5.k;
  return 0;
}

