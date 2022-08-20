package Yiyeceklerr;

public class Main {
    public static void main(String[] args) {
        Meyve elma = new Meyve("elma");

        /*
        elma.setValues("elma","agac","yesil");
        System.out.println(elma.getIsim()+" "+elma.getRenk()+" "+elma.getYer());
        elma.setIsimRenk("elma","yesil");
        System.out.println("Elma bir "+elma.yiyecekTuru()+"dir");
         */

        Sebze.goster("Lahana","kırmızı");
        Meyve.goster("Elma","yesil");
    }
}
