/*
	Given two straight line segments(represented as a start Point and an end point), compute the point of intersection if any
*/
/*
	Standard case (When we have two non-parallel and non-vertical lines)

		All infinite lines that are not parallel will intersect(although of-course, not necessarily within the bounds of
		a particular line segment)

		1. To compute slopes and y-intercepts:

			We can plug each(x1, y1) and (x2, y2) value into y=mx+c

				let we have two equations as:

					y1=mx1+b and y2=mx2+b

					Then we just need to solve for m and b

						e.g: we have line (2, 5) to (9, 19) then we would use the equation:

							5=2m+b and 19=9m+b

							This leads us to m=2 and b=1

								hence y=2x+1

		2. To compute where they intersect

			Considering the lines y=2x+1 and y=3x-4

			We find the values where their x and y values will be the same

				That is we can set their equations equal to each other:

					2x+1=3x-4 =>x=5, y=11

		3. To compute where they intersect on a line segment

			We already have the intersection, so we just need to figure out if a point (p, q) 
				lies in between (x1, y1) and (x2, y2)

			Observe that we know (p, q) lines on the infinite line, but is it on the line segment

				All we need to do is to check that the value of p is between x1 and x2

	-------

	If the lines are non-vertical and parallel

		Two parallel lines can't intersect unless they are on the same line

			So here all we need to do is to check that the lines have the same y-intercept

			If they are on the same line, then we want to check if their line segments overlap

				That is one start or end point must be on the other line segment

	-------

	If the lines are both vertical

		Here we just need to check that they have the same x-value

	-------

	If one line is vertical and the other line is not

		The above approach for non-vertical and non-parallel lines mostly works

			However, a vertical line is not described with y=mx+b equation

				Instead, it is described as x=x1 equation

					Hence, we modify step 1 and step 2 to use this equation

*/

#include<iostream>
using namespace std;

class Point{
	public:
	int X, Y;
	Point(){};
	Point(int X, int Y){
		this->X=X, this->Y=Y;
	}
};

class Line{
	public:
	double slope, yIntercept;
	Point start, end;

	public:
	Line(Point start, Point end){
		this->start=start, this->end=end;
		// Vertical Lines
		if(start.X==end.X){
			slope=INT_MAX;
			yIntercept=INT_MAX;
		} else{
			slope=(end.Y-start.Y)/(end.X-start.X);
			yIntercept=end.Y-slope*end.X;
		}
	}

	bool isVertical(){
		return slope==INT_MAX;
	}

	double getYFrmX(double X){
		if(isVertical()){
			return INT_MAX;
		}
		return slope*X+yIntercept;
	}
};

class GetIntersections{
	public:
	bool isBetween(double start, double middle, double end){
		if(start>end){
			return end<=middle&&middle<=start;
		}
		return start<=middle&&middle<=end;
	}

	bool isBetween(Point start, Point middle, Point end){
		return isBetween(start.X, middle.X, end.X)&&(start.Y, middle.Y, end.Y);
	}
	
	Point intersection(Point start1, Point end1, Point start2, Point end2){
		Line line1(start1, end1);
		Line line2(start2, end2);
		Point p1;
		p1.X=-1, p1.Y=-1;
		/*
			If the lines are parallel, then their infinite lines must have
			the same y-intercept.

			If so, then we'll check start/end of one of the line is on the other line
		*/
		if(line1.slope==line2.slope){
			if(line1.yIntercept!=line2.yIntercept){
				return p1;
			}
			// Checking if the start or end of one of the line is on the other
			if(isBetween(start1, start2, end1)) return start2;
			else if(isBetween(start1, end2, end1)) return end2;
			else if(isBetween(start2, start1, end2)) return start1;
			else return p1;
		}
		/*
			Computing the intersection of the infinite lines and checking boundary
		*/
		// Getting intersection's X coordinate
		double X;
		if(line1.isVertical()||line2.isVertical()){
			X=line1.isVertical()?line1.start.X:line2.start.X;
		} else{
			X=(line2.yIntercept-line1.yIntercept)/(line1.slope-line2.slope);
		}
		// Getting intersection's Y coordinate using a non-vertical line
		double Y=line1.isVertical()?line2.getYFrmX(X):line1.getYFrmX(X);
		/*
			We now have the intersection of the infinite lines.
			Checking if it's within the boundaries of each line segment
		*/
		Point intersection(X, Y);
		if(isBetween(start1, intersection, end1)&&(isBetween(start2, intersection, end2)))
			return intersection;
		return p1;
	}
};

int main(){
	GetIntersections obj;
	Point start1(0, 2);
	Point end1(2, 0);
	Point start2(0, 3);
	Point end2(1, 0);
	Point res=obj.intersection(start1, end1, start2, end2);
	if(res.X==-1&&res.Y==-1){
		cout<<"No Intersection"<<endl;
	} else{
		cout<<res.X<<" "<<res.Y<<endl;
	}
}