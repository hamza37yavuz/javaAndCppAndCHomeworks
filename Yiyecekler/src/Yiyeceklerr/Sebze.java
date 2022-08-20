package Yiyeceklerr;

public class Sebze extends Yiyecek{
    public Sebze(String isim) {
        super(isim, "toprak");
    }

    @Override
    public String yiyecekTuru(){
        return "sebze";
    }
    public static void goster(String isim,String renk){
        Sebze s = new Sebze(isim);
        System.out.println("Sebzenin rengi "+renk+"dir");
        System.out.println(isim+" "+s.getYer()+"ta yetişir.");
        System.out.println(isim+" bir "+s.yiyecekTuru()+"dir");

    }
    }

