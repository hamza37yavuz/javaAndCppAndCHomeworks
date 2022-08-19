package Yaris;

public class Rabbit{
    public int basla(int a,int i){
        if ((a >= 1) & (a <= 2)) {
            return i;
        }
        else if ((a >= 3) & (a <= 4)) {
            if(i>11)
                i=20;
            else
                i += 9;
            return i;
        }
        else if(a == 5) {
            if (i <= 12)
                i = 1;

            else
                i -= 12;

            return i;
        }
        else if((a >= 6) & (a <= 8)){
            i += 1;
            return i;
        }
        else{
            if(i>2)
                i -= 2;
            else
                i = 1;
            return i;
        }

    }
    }

