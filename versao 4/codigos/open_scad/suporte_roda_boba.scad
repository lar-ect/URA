module suporteRodaB () {

raioMaior = 12;
raioMenor = 3.5; 
altura = 2; 

rodaBComprimento = 50; 
rodaBLargura = 40; 

comprimento = 93; 

module base () {
 
 translate([-comprimento/2,0,0]) {
    cube([rodaBComprimento,rodaBLargura,altura],true);
    cube([comprimento,2*raioMaior,altura],true);
 }
 cylinder(altura,raioMaior,raioMaior,true);
 translate([-comprimento,0,0])
    cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {
 tam = rodaBComprimento*0.7;
 cylinder(altura+1,raioMenor,raioMenor,true); 
 translate([-comprimento,0,0])
    cylinder(altura+1,raioMenor,raioMenor,true); 
    
 translate([-comprimento/2,0,0]) {
   translate([0,12,0])
   cube([tam,4,altura+1],true); 
  
   translate([0,-12,0])
   cube([tam,4,altura+1],true); 
  } 
}


difference(){
base(); 
furosBase();

}

}

projection(cut = false) suporteRodaB(); 
