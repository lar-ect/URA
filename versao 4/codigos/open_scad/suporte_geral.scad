module suprteSG ()  {

raioMaior = 12;
raioMenor = 3.5; 
altura = 2; 

comprimento = 93; 

module base () {
 
 translate([-comprimento/2,0,0])
 cube([comprimento,2*raioMaior,altura],true);
 cylinder(altura,raioMaior,raioMaior,true);
 translate([-comprimento,0,0])
    cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {
 tam = comprimento*0.7;
 cylinder(altura+1,raioMenor,raioMenor,true); 
 translate([-comprimento,0,0])
    cylinder(altura+1,raioMenor,raioMenor,true); 
    
 translate([-comprimento/2,0,0]) {
  
  
   translate([0,raioMaior/2-1,0])
   cube([tam,4,altura+1],true); 
  
  translate([0,-raioMaior/2+1,0])
   cube([tam,4,altura+1],true); 
  } 
}

difference(){
base(); 
furosBase();

}

}

projection(cut = false)  suprteSG(); 