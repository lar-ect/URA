raioMaior = 12.5;
raioMenor = 3.3; 

largura = 25;
comprimento = 45.5; 
paredeGrossa = 3; 
paredeFina = 2; 
altura = paredeGrossa; 
deslSup = 5 + raioMaior; // deslocamento do suporte onde a preça será presa no robô 

module suporteParafuso () {
 translate([0,0,  + altura/2])
 rotate([90,0,0])
    cylinder($fn=30, comprimento,3,3,true); 

}

module base() {
 
 suporteParafuso();
 cube([largura,comprimento,altura],true);
    
 translate([(largura - paredeGrossa )/2,0, deslSup])
 rotate([90,0,90]) {
     cylinder(paredeGrossa,raioMaior,raioMaior,true);
    translate([0,-deslSup/2,0]) 
    cube([largura,deslSup,altura],true);
 }
}

module furos() {
    
    // suporte 
    translate([(largura-paredeGrossa)/2,0, deslSup])
 rotate([90,0,90]) { 
    
  cylinder(altura+1,raioMenor,raioMenor,true);
 }

 // saida pinos 
  lFuroPinos = 6; 
  translate([-(largura-lFuroPinos)/2,0, 0])
 
  cube([lFuroPinos,12,altura+1],true);
 


 translate([0,0,  altura/2])
 rotate([90,0,0])
 cylinder($fn=20, comprimento+1,1,1,true);

}



difference(){
base(); 
furos();

}

 
 
 
 