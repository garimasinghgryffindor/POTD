
class Solution {
  public:
    double maxVolume(double p, double a) {
        // as V = lbh, 
        // => V = l (A/2-(lb+lh)) {from equation (ii)} 
        // => V = lA/2 – l2(b+h) 
        // => V = lA/2 – l2(P/4-l) {from equation (i)} 
        // => V = lA/2 – l2P/4 + l3 —-(iii)
        // Now differentiate V w.r.t l for finding maximum of volume. 
        // dV/dl = A/2 – lP/2 + 3l2 
        // After solving the quadratic in l we have l = (P – (P2-24A)1/2) / 12 
       
        // double l = (p - sqrt(pow(p, 2) - 24*a))/12;
        // double volume = l*a/2 - pow(l,2)*p/4 + pow(l,3);
        // return volume;
        
        double ans = (pow((p-(sqrt(pow(p, 2)-(24 * a))))/12, 2) *
             ((p / 4) - (2 * ((p - (sqrt(pow(p, 2) - (24 * a)))) / 12))));
        return ans;
    }
};
