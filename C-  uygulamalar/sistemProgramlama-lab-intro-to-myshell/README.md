[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10684694&assignment_repo_type=AssignmentRepo)
# sysprog-lab5-mysehll intro
Size verilen users text dosyasinda ``users ve hash(passwordrandomstring) ve randomstringler`` bulunmaktadir. (**Not: Gercek hayatta password raw data olarak saklanmaz ve hicbirsekilde rawdata olarak network vb uzerinden istenmez. Burada bunun __basit bir ornegi__ olarak random stringlerle birlestirilerek cikan hash sonucu ve random string seklinde saklanmasi yapilistir. Boyle bir yonteminde problemleri bulunmakta ve yine guvenli oldugu manasina gelmemektedir.**).  

Buradaki hash fonksiyonu basit olarak stringin "kendisine benzer" bir string vermektedir ``h(string) = 1string1``. Data structure dersinde bunun ne gibi problemlere yol acabilecegini gordunuz. Burada testlerde kolaylik olsun diye bu sekilde verildi.

## Yapilmasi istenenler

``main.c`` calistirildiginda sadece ``$`` isareti gosteren bir program yaziniz. Bu program 
  * kendisine verilen komutlari ``system()`` kullanarak calistirmaktadir.
  * ``changeuser username`` verildiginde passwordu sormaktadir (``su - user``a benzer bu sekilde verilmedi, sonra github kendisini hacklediginizi dusunebilir:)),  
    - ``password`` seklinde passwordu sormakta
    - username'i users.txt'de bularak karsilik gelen h(verilenpassword+randomstring) ile ikinci sutundaki sakli hash degerini karsilastirmakta
      * Eger esit degilse ``hatali login$`` seklinde terminal yeniden beklemeye gecmektedir
      * Dogru ise bundan sonra terminal beklemesi ``username$`` seklinde olmaktadir.
  * Enter (``\n``) verildiginde bir alt satirdan yine ``$`` seklinde yada giris yapildiysa ``username$`` seklinde beklemektedir.
  * Exit denildiginde eger ``username$`` ise kullanici logout oldugu icin ``$`` seklinde beklemekte, ``$`` menude exit denilince direk cikmaktadir.
  
  **Programin yazilmasinda stdio.h ve fopen vb kullanmayiniz.** Bunun yerine open, read, write, systemcallarini kullanmaniz istenmektedir (zorlastirma icin degil pratik yapmaniz icin). 
  
  ## Testler
  Size verilen test.c dosyasinda bir degisiklik yapmayiniz. 
  Sistemdeki testler sadece basit testler olup, programin her fonksiyonu test edilmemektedir. Bosluklara yeni satirlara vs dikkat ediniz. Testler test edilmedigi icin testlerde hata olabilir, dogru calistigindan eminseniz takilmayin. Notlandirma test sonuclarina bakilmaksizin yapilacaktir.
  
  ## Degerlendirme
  Sadece teslim edenlere 100 verilecektir. Haftaya proje bu lab uzerine verileceginden labi yapmaniz tavsiye edilir.


