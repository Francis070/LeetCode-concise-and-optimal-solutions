class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kel = celsius + 273.15;
        double far = (celsius * 1.80) + 32.0;

        return {kel, far};
    }
};