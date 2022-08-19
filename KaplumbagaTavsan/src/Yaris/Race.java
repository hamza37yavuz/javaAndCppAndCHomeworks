package Yaris;

import java.util.Random;

public class Race {
    public int sayi() {
        Random r = new Random();
        return r.nextInt(10);
    }
    public void yaris(){
        Turtle tu = new Turtle();
        Rabbit ra = new Rabbit();
        int a = sayi();
        int z = 1;
        int x = 1;
        int y = 1;
        int k = 1;
        int t = 1;
        while (true){
            if (z==1){
                z++;
            }
            else {
                a = sayi();
                x = k;
                y = t;
                k = tu.basla(a, x);
                t = ra.basla(a, y);
            }
            if((k==20)&(t<20)) {
                kiyas(k, t);
                System.out.println("KAPLUMBAGA kazandi oley");
                break;
            }
            else if ((k<20)&(t==20)){
                kiyas(k, t);
                System.out.println("TAVSAN kazandi, yuh!");
                break;
            }
            else if((k==20)&(k==t)){
                kiyas(k, t);
                System.out.println("Berabere");
                break;
            }
            else
                kiyas(k, t);
        }
    }
    public void kiyas(int t,int r){
        int b = 1;
        while(b<=20){
            if((t!=b)&(r!=b)){
                System.out.print("_");
                System.out.print(" ");
                b++;
            }
            else if ((t!=b)&(r==b)){
                System.out.print("T");
                System.out.print(" ");
                b++;
            }
            else if (r!=b){
                System.out.print("K");
                System.out.print(" ");
                b++;
            }
            else{
                System.out.print("AUCH");
                b++;
                break;
            }
        }
        System.out.println("\n");
        System.out.println("Kaplumbağa Kare: "+t);
        System.out.println("Tavşan Kare: "+r);

    }
}

