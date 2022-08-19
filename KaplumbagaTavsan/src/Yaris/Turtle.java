package Yaris;
public class Turtle {
    public int basla(int a, int i) {
        if ((a >= 1) & (a <= 5)) {
            if (i > 15)
                i = 20;
            else
                i += 5;
            return i;
        }
        else if ((a >= 6) & (a <= 7)) {
            if (i <= 6)
                i = 1;
            else
                i -= 6;
            return i;
        }
        else {
            i += 1;
            return i;
        }

    }
}
