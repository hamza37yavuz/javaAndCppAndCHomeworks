package Yiyeceklerr;

public abstract class Yiyecek {
    private String isim;
    private String renk;
    private String yer;

    public Yiyecek(String isim,String yer,String renk){
        this.isim = isim;
        this.yer = yer;
        this.renk = renk;
    }
    public Yiyecek(String isim,String yer){
        this.isim = isim;
        this.yer = yer;
    }

    public String getIsim() {
        return isim;
    }
    public String getRenk() {
        return renk;
    }
    public String getYer() {
        return yer;
    }
    public void setValues(String isim,String yer,String renk) {
        this.isim = isim;
        this.yer = yer;
        this.renk = renk;
    }
    public void setIsimRenk(String isim,String renk) {
        this.isim = isim;
        this.renk = renk;
    }
    public String yiyecekTuru(){
        return "Belirsiz";
    }
}
