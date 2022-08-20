package Yiyeceklerr;

public class Meyve extends Yiyecek{
    public Meyve(String isim) {
        super(isim, "agac");
    }

    @Override
    public String yiyecekTuru() {
        return "Meyve";
    }
    public static void goster(String isim,String renk){
        Meyve m = new Meyve(isim);
        System.out.println("Meyvenin rengi "+renk+"dir");
        System.out.println(isim+" "+m.getYer()+"ta yetişir.");
        System.out.println(isim+" bir "+m.yiyecekTuru()+"dir");

    }
}
