// 1) Finding random point in area of circle directly.
// By definition, Area = PI*r^2, alternatively Area is proportional to r^2.
// So random* Area is proportional to random of random*r^2, which can be written as (sqrt(random)*r)^2. Hence the relation between r & Area is same as sqrt(random)*r & random*Area.

// To find a random point inside the area, you need to choose an angle (ie 0 to 360) and find a random of radius (as explained above we should use sqrt(random)*r). 
class Solution {
public:
    double xCenter;
    double yCenter;
    double radius;
    Solution(double rad, double x_center, double y_center) {
          radius = rad;
        xCenter = x_center;
        yCenter = y_center;
    }
      double random(){
        return 1.0 * rand() / RAND_MAX;
    }
    vector<double> randPoint() {
         double length = sqrt(random()) * radius;
        double angle = random() * 2 * M_PI;  //M_PI ==pi
        double xRand = xCenter + length * cos(angle), yRand = yCenter + length * sin(angle);
        return {xRand, yRand};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
