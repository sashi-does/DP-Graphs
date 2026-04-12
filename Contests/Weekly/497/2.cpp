// https://leetcode.com/problems/angles-of-a-triangle/

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a = sides[0], b = sides[1], c = sides[2];
        if(a + b > c && b + c > a && a + c > b) {
            // a b
            // a2 + b2 - c2 / 2ab
            vector<double> degrees;
            double val = (a*a + b*b - c*c) / (2.0*a*b);
            double radians = acos(val);
            double deg = (180 / M_PI) * radians * 1.0;
            degrees.push_back(deg);

            val = (b*b + c*c - a*a) / (2.0*c*b);
            radians = acos(val);
            deg = (180 / M_PI) * radians * 1.0;
            degrees.push_back(deg);

            val = (a*a + c*c - b*b) / (2.0*a*c);
            radians = acos(val);
            deg = (180 / M_PI) * radians * 1.0;
            degrees.push_back(deg);

            sort(degrees.begin(), degrees.end());
            return degrees;
            
        }
        return {};
    }
};