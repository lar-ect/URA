

module chapaSG (qtX,qtY)  {
    raioMaior = 12;
    raioMenor = 3.5; 
    altura = 2; 
    distFuros = 15.5; 

    comprimento = (qtX-1)*distFuros+2*raioMaior;
    largura = (qtY-1)*distFuros+2*raioMaior;

    module base(){
     
     
      hull(){
       translate([raioMaior,raioMaior])cylinder(r=raioMaior,h=zdim);
       translate([comprimento-raioMaior,raioMaior,0])cylinder(r=raioMaior,h=zdim);
       translate([raioMaior,largura-raioMaior])cylinder(r=raioMaior,h=zdim);
       translate([comprimento-raioMaior,largura-raioMaior,0])cylinder(r=raioMaior,h=zdim);
      }
     }  


    module furosBase() {
     for(sY = [raioMaior:distFuros:distFuros*qtY])
      for (sX = [raioMaior:distFuros:distFuros*qtX]){
        translate([sX,sY,0])
        cylinder(altura+1,raioMenor,raioMenor,true);   
      } 
    }

    difference(){
     base(); 
     furosBase();
    }

}

chapaSG(7,1); 

//projection(cut = false)  chapaSG(7,7); 
