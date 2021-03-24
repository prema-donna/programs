#include<iostream>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>

class Point2D
{
  protected:
    float x;
    float y;
  public:
    void setXY(float x1, float y1)
    {
      x = x1;
      y = y1;
    }
    float calculate2Dist(Point2D p)
    {
      float xdist = p.x - x;
      float ydist = p.y - y;
      float squaredDist = (float)pow(xdist, 2) + pow(ydist, 2);
      return (float)pow(squaredDist, 0.5);
    }
    void print(Point2D p)
    {
      int dist = (int)ceil(calculate2Dist(p));
      std::cout<<"2D Distance = "<<dist<<std::endl;
    }
};

class Point3D:public Point2D
{
  protected:
    float z;
  public:
    void setZ(float z1)
    {
      z = z1;
    }
    float calculate3Dist(Point3D p)
    {
      float xdist = p.x - x;
      float ydist = p.y - y;
      float zdist = p.z - z;
      float squaredDist = (float)pow(xdist, 2)+pow(ydist, 2)+pow(zdist,2);
      return (float)pow(squaredDist, 0.5); 
    }
    void print(Point3D p)
    {
      int dist = (int)ceil(calculate3Dist(p));
      std::cout<<"3D Distance = "<<dist<<std::endl;
    }
};

std::vector<std::vector<float>> sortPoints(std::vector<std::vector<float>> points)
{
  std::vector<std::vector<float>> res;
  std::map<std::vector<float>,int> allPoints;

  for(int i= 0; i< points.size(); i++)
  {
    allPoints[points[i]] += 1;
  }
  for(std::map<std::vector<float>,int>::iterator it = allPoints.begin(); it != allPoints.end(); ++it)
  {
    int numPoint = it->second;
    while(numPoint > 0)
    {
      res.push_back(it->first);
      numPoint--;
    }
  }
  return res;
}

void printAllPoints(std::vector<std::vector<float>> res)
{
  for(int i= 0; i< res.size(); i++)
  {
    std::cout<<"Point "<<i+1<<std::endl;
    std::cout<<"("<<res[i][0]<<", "<<res[i][1]<<", "<<res[i][2]<<")"<<std::endl;
  }
}

int main()
{
  Point2D p;
  Point2D q;
  Point3D r;
  Point3D s;


  float x1 = 1.5;
  float x2 = -4;
  float y1 = -2.3;
  float y2 = 3.6;
  float z1 = 0;
  float z2 = -7.14;

  p.setXY(x1,y1);
  q.setXY(x2,y2);
  p.print(q);

  r.setXY(x1,y1);
  s.setXY(x2,y2);
  r.setZ(z1);
  s.setZ(z2);
  r.print(s);

  std::vector<float> point1 = {x1,y1,z1};
  std::vector<float> point2 = {x2,y2,z2};
  std::vector<float> point3 = {1.5,-2.3,-2.3};
  std::vector<float> point4 = {1.5,-2.2,-0};
  std::vector<float> point5 = {1.5,2.3,-7.14};
  std::vector<float> point6 = {9.9,-16.8,-120};
  std::vector<float> point7 = {9.9,-16.8,-120};
  std::vector<std::vector<float>> myVec = {point1, point5, point7, point2, point6, point4, point3};

  printAllPoints(sortPoints(myVec));

  return 0;
}
