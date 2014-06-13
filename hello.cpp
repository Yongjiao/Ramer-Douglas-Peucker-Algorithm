#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

typedef struct Point{
  double x;
  double y;
  Point() {} 
  Point(double x0, double y0): x(x0), y(y0) {} 
}Point;

//typedef struct Point Point;
using std::vector;

double Norm(Point p) 
{ 
  return sqrt(p.x * p.x + p.y * p.y); 
}
 
double operator*(Point p1, Point p2) 
{ 
  return (p1.x * p2.y - p2.x * p1.y); 
} 

//??cannot make it return to a pair reference, why
std::pair<int, double> findMaximumDistance(const vector<Point>& Points, const Point& firstpoint,const Point& lastpoint){
  int index=0;
  double Mdist=-1;

  Point p;
  p.x=lastpoint.x-firstpoint.x;
  p.y=lastpoint.y-firstpoint.y;

  for(int i=0;i<Points.size();i++){
  Point pp;
  pp.x=Points[i].x-firstpoint.x;
  pp.y=Points[i].y-firstpoint.y;
  int oneDist=fabs(pp * p) / Norm(p);
  if (oneDist>Mdist){
    Mdist=oneDist;
    index=i;
  }
  }
  std::cout<<"Maxdistance is"<<Mdist<<std::endl;
  return std::make_pair(index, Mdist);
}


//??can I make Points reference here?? yes, but 
vector<Point> simplifyWithRDP(vector<Point>& Points, double epsilon){ 
  Point first=Points[0]; //access elemnet at 0, which is data of type Point
  Point last=Points[Points.size()-1]; 
  if(Points.size()<3){
    return Points;//???? refernce??
  }

std::pair<int, double> maxDistance=findMaximumDistance(Points,first,last);//??refernce could be initiated like this right?
  std::cout<<"Max distance:"<<maxDistance.second<<std::endl; 
 //maxDistance change index n Maxi first n last
  int index=maxDistance.first;
  //std::cout<<int(it->x);
  if(maxDistance.second>epsilon){
    //    Point* indexptr=&Points[index];     
    vector<Point>::iterator it=Points.begin();
    it=it+index;
    vector<Point> l1(Points.begin(),it);
    //cut the second half, leave 0 to index   
    vector<Point> l2(it,Points.end());
    //cut the first half, leave index to last

    vector<Point> r1 =simplifyWithRDP(l1,epsilon);
    vector<Point> r2=simplifyWithRDP(l2,epsilon);
    
    vector<Point> rs(r1);
    rs.pop_back();
    rs.insert(rs.end(),r2.begin(),r2.end()); //r2.end(), which points after the last element, will not be added to the new// stick r1 and r2 with the last element of r1 removed  
    return rs;
  }
  else {
    vector<Point> r(1,first);
    //have to construct first&allocate memory for it or need to have the
    //thing before try to link it with a reference 
    //reference declaration& initialization: vector<Point>& rr(r) or rr=r; 
    r.push_back(last);
    return r;
  }
}

//??might need deconstruction for vector<T>!

int main(){
  vector<Point> Points(5);
  //for(int i=0;i<Points.size();i++){Points[i]= }
  Points[0].x=0;
  Points[0].y=0;
  Points[1].x=5;
  Points[1].y=9;
  Points[2].x=10;
  Points[2].y=10;
  Points[3].x=15;
  Points[3].y=7;
  Points[4].x=20;
  Points[4].y=0;
  double epsilon=2;
  vector<Point> simpath=simplifyWithRDP(Points,epsilon); //assignment here? a doesnt know the size and doesnt exist yet
  for(vector<Point>::const_iterator i = simpath.begin(); i < simpath.end(); ++i)
    std::cout <<'('<<i->x<< ", "<<i->y << ") ";
    std::cout<<std::endl;
  return 0;
}


