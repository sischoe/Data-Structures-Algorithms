// PRE: x is roundable to a number in the value range of type int
// POST: return value is the integer nearest to x, or the one further
//       away from 0 if x lies right in between two integers.
int round(double x) {
    int trunc = x; // rounds towards 0 by standard
    double difference = x - trunc; // note: result is exact!
  
    if (difference >= 0.5) {
        // x was positive, and trunc + 1 is closer
        return trunc + 1;
    } else if (difference <= -0.5) {
        // x was negative, and trunc - 1 is closer
        return trunc - 1;
    } else {
        // |difference| < 0.5, trunc is closest integer
        return trunc;
    }
}
